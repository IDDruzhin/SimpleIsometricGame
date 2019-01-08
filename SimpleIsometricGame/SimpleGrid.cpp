#include "stdafx.h"
#include "SimpleGrid.h"


SimpleGrid::SimpleGrid(shared_ptr<GraphicsEngine> graphics_engine, int seed)
{
	string cells_texture_path = "Content/Blocks_sheet.png"; 
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 5;
	sheet_info->window_size.x = 111;
	sheet_info->window_size.y = 128;
	int tiles_count = 5;
	for (int i = 0; i < tiles_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i, 0));
	}
	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, cells_texture_path, sheet_info);
	float tile_width = 64;
	SetCellOffset(tile_width);
	graphics_component_->SetOrigin(int2(graphics_component_->GetSpriteRect().size.x / 2, 0));
	SetDim(uint2(30, 30));
	block_mask_.Clear();
	GenerateRandomGrid(seed);
}


SimpleGrid::~SimpleGrid()
{
}
