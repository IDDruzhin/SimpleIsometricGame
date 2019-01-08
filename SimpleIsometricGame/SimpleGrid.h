#pragma once
#include "Grid.h"
class SimpleGrid :
	public Grid
{
public:
	SimpleGrid(shared_ptr<GraphicsEngine> graphics_engine, int seed = 0);
	~SimpleGrid();
};

