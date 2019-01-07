#pragma once
#include "Unit.h"
#include "PathMovement.h"
class PlayerCharacter :
	public Unit
{
public:
	PlayerCharacter(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location);
	~PlayerCharacter();
};

