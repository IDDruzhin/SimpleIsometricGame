#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}

Grid::Grid(uint2 dim, float2 cell_offset, shared_ptr<GraphicsEngine> graphics_engine, const string &cell_texture_path)
{
	dim_ = dim;
	uint size = dim_.x*dim_.y;
	block_mask_.Resize(size);
	block_mask_.Clear(true);
	cell_offset_ = cell_offset;
	RegisterCellsGraphics(graphics_engine, cell_texture_path);
}

Grid::~Grid()
{
}

void Grid::SetDim(uint2 dim)
{
	dim_ = dim;
	uint size = dim_.x*dim_.y;
	block_mask_.Resize(size);
}

uint2 Grid::GetDim()
{
	return dim_;
}

void Grid::SetCellOffset(float2 cell_offset)
{
	cell_offset_ = cell_offset;
}

float2 Grid::GetCellOffset()
{
	return cell_offset_;
}

/*
void Grid::SetCellsMap(vector<unsigned char> cells_map)
{
	if (cells_map.size() == dim_.x * dim_.y)
	{
		cells_map_ = cells_map;
	}
}
*/

void Grid::RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, const string &path)
{
	graphics_engine->RegisterGraphicsResource(graphics_component_, path);
}

void Grid::GenerateRandomGrid(int seed)
{
	//cells_map_.resize(dim_.x * dim_.y);
	uint size = dim_.x * dim_.y;
	block_mask_.Clear();
	block_mask_.Resize(size);
	mt19937 gen;
	gen.seed(seed);
	uniform_int_distribution<int> dist(0, 1);
	for (int i = 0; i < size; i++)
	{
		if (dist(gen))
		{
			block_mask_.Set(i);
		}
	}
	//generate(cells_map_.begin(), cells_map_.end(), [&dist, &gen]() { return dist(gen); });
}

void Grid::Draw(shared_ptr<Screen> screen)
{
	int index;
	float2 cell_grid_location;
	float2 cell_screen_location;
	for (int y = 0; y < dim_.y; y++)
	{
		for (int x = 0; x < dim_.x; x++)
		{
			index = y * dim_.x + x;
			if (block_mask_.Get(index))
			{
				/*
				cell_grid_location.x = x * cell_size_;
				cell_grid_location.y = y * cell_size_;
				cell_screen_location = GridToScreen(cell_grid_location);
				cell_screen_location.x += screen_location_.x;
				cell_screen_location.y += screen_location_.y;
				cells_graphics_->SetLocation(cell_screen_location);
				//cells_graphics_->SetLocation(cell_grid_location);
				graphics_engine->Draw(cells_graphics_);
				*/
				cell_grid_location.x = x;
				cell_grid_location.y = y;
				cell_screen_location = GridToScreen(cell_grid_location);
				cell_screen_location.x += screen_location_.x;
				cell_screen_location.y += screen_location_.y;
				graphics_component_->SetLocation(cell_screen_location);
				//cells_graphics_->SetLocation(cell_grid_location);
				//graphics_engine->Draw(cells_graphics_);
				screen->Draw(graphics_component_);
			}
		}
	}
}

float2 Grid::GridToScreen(float2 grid_pos)
{
	float2 screen_pos;
	/*
	screen_pos.x = grid_pos.x - grid_pos.y;
	screen_pos.y = (grid_pos.x + grid_pos.y) / 2.0f;
	*/
	screen_pos.x = (grid_pos.x - grid_pos.y) * cell_offset_.x;
	screen_pos.y = (grid_pos.x + grid_pos.y) * cell_offset_.y;
	return screen_pos;
}

float2 Grid::ScreenToGrid(float2 screen_pos)
{
	float2 grid_pos;
	grid_pos.x = (2 * screen_pos.y + screen_pos.x) / 2.0f;
	grid_pos.y = (2 * screen_pos.y - screen_pos.x) / 2.0f;
	return grid_pos;
}

float2 Grid::GetGridCenter()
{
	float2 center;
	center.x = dim_.x / 2.0f;
	center.y = dim_.y / 2.0f;
	center = GridToScreen(center);
	return center;
}
