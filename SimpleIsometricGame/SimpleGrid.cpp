#include "stdafx.h"
#include "SimpleGrid.h"


SimpleGrid::SimpleGrid(shared_ptr<GraphicsEngine> graphics_engine)
{
	//dim_.x = 10;
	//dim_.y = 10;
	//string cell_texture_path = "Content/isometric_pixel_0087.png";
	//string cell_texture_path = "Content/isometric_pixel_0200.png";
	//string cell_texture_path = "Content/abstractTile_21.png";
	//string cells_texture_path = "Content/Blocks_sheet.png";
	string cells_texture_path = "Content/Blocks_sheet_001.png"; 
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 5;
	sheet_info->window_size.x = 111;
	sheet_info->window_size.y = 128;
	int tiles_count = 10;
	/*
	sheet_info->window_size.x = 112;
	sheet_info->window_size.y = 129;
	int tiles_count = 20;
	*/
	for (int i = 0; i < tiles_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i, 0));
	}
	//RegisterGraphics()
	//RegisterCellsGraphics(graphics_engine, cell_texture_path);
	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, cells_texture_path, sheet_info);
	float tile_width = 64;
	SetCellOffset(tile_width);
	graphics_component_->SetOrigin(int2(graphics_component_->GetSpriteRect().size.x / 2, 0));
	SetDim(uint2(10, 10));
	block_mask_.Clear();
	//fill(cells_map_.begin(), cells_map_.end(), 22);
	//GenerateRandomGrid();
	//fill(cells_map_.begin(), cells_map_.end(), 0);
	/*
	cell_offset_.x = tile_width / 2.0f;
	cell_offset_.y = cell_offset_.x / 2.0f;
	*/
	/*
	float scale = tile_width / graphics_component_->GetSpriteRect().size.x;
	graphics_component_->SetScale(scale);
	cell_offset_.x = scale * graphics_component_->GetSpriteRect().size.x / 2.0f;
	cell_offset_.y = scale * graphics_component_->GetSpriteRect().size.y / 4.0f;
	*/
	//cells_map_.resize(dim_.x*dim_.y,1);
	//block_mask_.Resize(dim_.x*dim_.y);
	//block_mask_.Clear(true);
	//GenerateRandomGrid(999);
}


SimpleGrid::~SimpleGrid()
{
}
