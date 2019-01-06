#include "stdafx.h"
#include "SimpleGrid.h"


SimpleGrid::SimpleGrid(shared_ptr<GraphicsEngine> graphics_engine)
{
	dim_.x = 30;
	dim_.y = 30;
	//dim_.x = 10;
	//dim_.y = 10;
	//string cell_texture_path = "Content/isometric_pixel_0087.png";
	//string cell_texture_path = "Content/isometric_pixel_0200.png";
	string cell_texture_path = "Content/abstractTile_21.png";
	RegisterCellsGraphics(graphics_engine, cell_texture_path);
	float tile_width = 64;
	/*
	cell_offset_.x = tile_width / 2.0f;
	cell_offset_.y = cell_offset_.x / 2.0f;
	*/
	float scale = tile_width / cells_graphics_->GetSpriteRect().size.x;
	cells_graphics_->SetScale(scale);
	cell_offset_.x = scale * cells_graphics_->GetSpriteRect().size.x / 2.0f;
	cell_offset_.y = scale * cells_graphics_->GetSpriteRect().size.y / 4.0f;
	cells_map_.resize(dim_.x*dim_.y,1);
	//GenerateRandomGrid(999);
}


SimpleGrid::~SimpleGrid()
{
}
