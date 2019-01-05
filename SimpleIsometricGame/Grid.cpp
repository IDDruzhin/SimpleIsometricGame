#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::Grid(uint2 dim, float cell_size, shared_ptr<GraphicsEngine> graphics_engine, const string &cell_texture_path)
{
	dim_ = dim;
	cell_size_ = cell_size;
	cells_map_.resize(dim_.x*dim_.y,1);
	RegisterCellsGraphics(graphics_engine, cell_texture_path);
}

Grid::~Grid()
{
}

void Grid::SetDim(uint2 dim)
{
	dim_ = dim;
	cells_map_.resize(dim_.x*dim_.y);
}

uint2 Grid::GetDim()
{
	return dim_;
}

void Grid::SetCellSize(float size)
{
	cell_size_ = size;
}

float Grid::GetCellSize()
{
	return cell_size_;
}

void Grid::SetCellsMap(vector<unsigned char> cells_map)
{
	if (cells_map.size() == dim_.x * dim_.y)
	{
		cells_map_ = cells_map;
	}
}

void Grid::RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, const string &path)
{
	graphics_engine->RegisterGraphicsResource(cells_graphics_, path);
}

void Grid::GenerateRandomGrid(int seed)
{
	cells_map_.resize(dim_.x * dim_.y);
	mt19937 gen;
	gen.seed(seed);
	uniform_int_distribution<int> dist(0, 1);
	generate(cells_map_.begin(), cells_map_.end(), [&dist, &gen]() { return dist(gen); });
}

void Grid::Draw(shared_ptr<GraphicsEngine> graphics_engine)
{
	int index;
	float2 cell_grid_location;
	float2 cell_screen_location;
	for (int y = 0; y < dim_.y; y++)
	{
		for (int x = 0; x < dim_.x; x++)
		{
			index = y * dim_.x + x;
			if (cells_map_[index] > 0)
			{
				cell_grid_location.x = x * cell_size_;
				cell_grid_location.y = y * cell_size_;
				cell_screen_location = GridToScreen(cell_grid_location);
				cell_screen_location.x += screen_location_.x;
				cell_screen_location.y += screen_location_.y;
				cells_graphics_->SetLocation(cell_screen_location);
				//cells_graphics_->SetLocation(cell_grid_location);
				graphics_engine->Draw(cells_graphics_);
			}
		}
	}
}

float2 Grid::GridToScreen(float2 grid_pos)
{
	float2 screen_pos;
	screen_pos.x = grid_pos.x - grid_pos.y;
	screen_pos.y = (grid_pos.x + grid_pos.y) / 2.0f;
	return screen_pos;
}

float2 Grid::ScreenToGrid(float2 screen_pos)
{
	float2 grid_pos;
	grid_pos.x = (2 * screen_pos.y + screen_pos.x) / 2.0f;
	grid_pos.y = (2 * screen_pos.y - screen_pos.x) / 2.0f;
	return grid_pos;
}
