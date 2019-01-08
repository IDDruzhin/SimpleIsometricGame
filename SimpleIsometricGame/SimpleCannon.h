#pragma once
#include "Cannon.h"
class SimpleCannon :
	public Cannon
{
private:
	static const int SIMPLE_CANNON_STATES[];
public:
	SimpleCannon(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location);
	~SimpleCannon();
};

