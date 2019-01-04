#include "stdafx.h"
#include "SimpleGrid.h"


SimpleGrid::SimpleGrid(shared_ptr<GraphicsEngine> graphics_engine)
{
	dim_.x = 30;
	dim_.y = 30;
	cell_size_ = 50.0f;
	string cell_texture_path = "Content/isometric_pixel_0087.png";
	RegisterCellsGraphics(graphics_engine, cell_texture_path);
	GenerateRandomGrid(999);
}


SimpleGrid::~SimpleGrid()
{
}
