#pragma once
#include "Unit.h"
#include "PatrolMovement.h"
class Guardian :
	public Unit
{
public:
	Guardian(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, int2 patrol_direction);
	~Guardian();
};

