#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}

/*
Grid::Grid(uint2 dim, float2 cell_offset, shared_ptr<GraphicsEngine> graphics_engine, const string &cell_texture_path)
{
	dim_ = dim;
	uint size = dim_.x*dim_.y;
	block_mask_.Resize(size);
	block_mask_.Clear(true);
	cell_offset_ = cell_offset;
	//RegisterCellsGraphics(graphics_engine, cell_texture_path);
}
*/

Grid::~Grid()
{
}

void Grid::SetDim(uint2 dim)
{
	dim_ = dim;
	uint size = dim_.x*dim_.y;
	block_mask_.Resize(size);
	killzone_mask_.Resize(size);
	if (sprite_sheet_component_)
	{
		cells_map_.resize(size,0);
	}
	size = (dim_.x+1)*(dim_.y+1);
	employ_mask_.Resize(size);
}

uint2 Grid::GetDim()
{
	return dim_;
}

void Grid::SetCellOffset(float2 cell_offset)
{
	cell_offset_ = cell_offset;
}

void Grid::SetCellOffset(float tile_width)
{
	float scale = tile_width / graphics_component_->GetSpriteRect().size.x;
	graphics_component_->SetScale(scale);
	cell_offset_.x = scale * graphics_component_->GetSpriteRect().size.x / 2.0f;
	cell_offset_.y = scale * graphics_component_->GetSpriteRect().size.y / 4.0f;
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

/*
void Grid::RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path)
{
	graphics_engine->RegisterGraphicsResource(graphics_component_, path);
}

void Grid::RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path, SheetInfo sheet_info)
{
	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, path, sheet_info);
}
*/

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
			//SetBlockMask(i, true);
			block_mask_.Set(i, true);
		}
	}
	//uniform_int_distribution<int> sprite_dist(0, sprite_sheet_component_->);
	if (sprite_sheet_component_)
	{
		uniform_int_distribution<int> sprite_dist(0, sprite_sheet_component_->GetTilesCount()-1);
		generate(cells_map_.begin(), cells_map_.end(), [&sprite_dist, &gen]() { return sprite_dist(gen); });
	}
	//generate(cells_map_.begin(), cells_map_.end(), [&dist, &gen]() { return dist(gen); });
}

void Grid::Draw(shared_ptr<Screen> screen)
{
	int index;
	float2 cell_grid_location;
	float2 cell_screen_location;
	if (sprite_sheet_component_ == nullptr)
	{
		for (int y = 0; y < dim_.y; y++)
		{
			for (int x = 0; x < dim_.x; x++)
			{
				index = y * dim_.x + x;
				if (!block_mask_.Get(index))
				{
					cell_grid_location.x = x;
					cell_grid_location.y = y;
					cell_screen_location = GridToScreen(cell_grid_location);
					//cell_screen_location.x += screen_location_.x;
					//cell_screen_location.y += screen_location_.y;
					graphics_component_->SetLocation(cell_screen_location);
					screen->Draw(graphics_component_);
				}
			}
		}
	}
	else
	{
		for (int y = 0; y < dim_.y; y++)
		{
			for (int x = 0; x < dim_.x; x++)
			{
				index = y * dim_.x + x;
				if (!block_mask_.Get(index))
				{
					if (sprite_sheet_component_->SetState(cells_map_[index]))
					{
						graphics_component_->SetSpriteRect(sprite_sheet_component_->GetCurRect());
					}
					cell_grid_location.x = x;
					cell_grid_location.y = y;
					cell_screen_location = GridToScreen(cell_grid_location);
					//cell_screen_location.x += screen_location_.x;
					//cell_screen_location.y += screen_location_.y;
					graphics_component_->SetLocation(cell_screen_location);
					screen->Draw(graphics_component_);
				}
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
	//grid_pos.x -= screen_location_.x;
	//grid_pos.y -= screen_location_.y;
	screen_pos.x = screen_location_.x + (grid_pos.x - grid_pos.y) * cell_offset_.x;
	screen_pos.y = screen_location_.y + (grid_pos.x + grid_pos.y) * cell_offset_.y;
	return screen_pos;
}

float2 Grid::ScreenToGrid(float2 screen_pos)
{
	float2 grid_pos;
	/*
	grid_pos.x = (2 * screen_pos.y + screen_pos.x) / 2.0f;
	grid_pos.y = (2 * screen_pos.y - screen_pos.x) / 2.0f;
	*/
	screen_pos.x -= screen_location_.x;
	screen_pos.y -= screen_location_.y;
	//screen_pos.x -= cell_offset_.x;
	grid_pos.x = (screen_pos.x / cell_offset_.x + screen_pos.y / cell_offset_.y) / 2.0f;
	grid_pos.y = (screen_pos.y / cell_offset_.y - (screen_pos.x / cell_offset_.x)) / 2.0f;
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

bool Grid::IsInsideGrid(float2 grid_pos)
{
	if (grid_pos.x >= 0 && grid_pos.x <= dim_.x && grid_pos.y >= 0 && grid_pos.y <= dim_.y)
	{
		return true;
	}
	return false;
}

bool Grid::IsInsideGrid(int2 grid_pos)
{
	if (grid_pos.x >= 0 && grid_pos.x < dim_.x && grid_pos.y >= 0 && grid_pos.y < dim_.y)
	{
		return true;
	}
	return false;
}

bool Grid::CheckBlockMask(int2 pos)
{
	uint index = pos.y * dim_.x + pos.x;
	return block_mask_.Get(index);
}

bool Grid::CheckEmployMask(int2 pos)
{
	uint index = (pos.y + 1) * (dim_.x + 1) + (pos.x + 1);
	return employ_mask_.Get(index);
}

void Grid::SetBlockMask(int2 pos, bool block)
{
	uint index = pos.y * dim_.x + pos.x;
	block_mask_.Set(index, block);
}

void Grid::SetEmployMask(int2 pos)
{
	uint index = (pos.y + 1) * (dim_.x + 1) + (pos.x + 1);
	employ_mask_.Set(index, true);
}

void Grid::SetKillzoneMask(int2 pos)
{
	uint index = pos.y * dim_.x + pos.x;
	killzone_mask_.Set(index, true);
}

void Grid::ClearEmployMask()
{
	employ_mask_.Clear();
}

void Grid::ClearKillzoneMask()
{
	killzone_mask_.Clear();
}

void Grid::PrintMask(Bitset mask)
{
	cout << endl;
	for (int i = 0; i < dim_.y; i++)
	{
		for (int j = 0; j < dim_.x; j++)
		{
			cout << mask.Get(i*dim_.x + j) << " ";
		}
		cout << endl;
	}
}

Bitset Grid::GetBlockMask()
{
	return block_mask_;
}

