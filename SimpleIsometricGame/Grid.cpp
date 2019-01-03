#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::Grid(int2 dim, float cell_size)
{
	dim_ = dim;
	cell_size_ = cell_size;
	cells_map_.resize(dim_.x*dim_.y);
}

Grid::~Grid()
{
}

void Grid::SetDim(int2 dim)
{
	dim_ = dim;
	cells_map_.resize(dim_.x*dim_.y);
}

int2 Grid::GetDim()
{
	return dim_;
}

void Grid::SetCellsMap(vector<unsigned char> cells_map)
{
	if (cells_map.size() == dim_.x * dim_.y)
	{
		cells_map_ = cells_map;
	}
}

void Grid::RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, const vector<string> &pathes)
{
	cells_graphics_.clear();
	for (const string &path : pathes)
	{
		cells_graphics_.push_back(graphics_engine->RegisterGraphicsResource(path));
	}
}

void Grid::GenerateRandomGrid(int seed)
{
	cells_map_.resize(dim_.x * dim_.y);
	mt19937 gen;
	gen.seed(seed);
	uniform_int_distribution<unsigned char> dist(0, cells_graphics_.size());
	generate(cells_map_.begin(), cells_map_.end(), [&dist, gen]() { return dist(gen); });
}

void Grid::Draw(shared_ptr<GraphicsEngine> graphics_engine)
{
	int index;
	float2 cell_location;
	for (int y = 0; y < dim_.y; y++)
	{
		for (int x = 0; x < dim_.x; x++)
		{
			index = y * dim_.x + x;
			if (cells_map_[index] > 0)
			{
				cell_location = screen_location_;
				//cells_graphics_[cells_map_[index] - 1]->SetLocation();
			}
		}
	}
}
