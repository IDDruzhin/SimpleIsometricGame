#include "stdafx.h"
#include "Cannon.h"


Cannon::Cannon(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location):GridActor(grid,grid_location)
{
}

Cannon::Cannon()
{
}


Cannon::~Cannon()
{
}

void Cannon::Update()
{
	GridActor::Update();
	attack_component_->Attack(grid_, GetGridCellLocation());
}
