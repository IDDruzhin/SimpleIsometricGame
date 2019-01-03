#include "stdafx.h"
#include "GridActor.h"


GridActor::GridActor()
{
}


GridActor::~GridActor()
{
}

void GridActor::SetGridCellLocation(int2 grid_location)
{
	grid_location_.x = grid_location.x;
	grid_location_.y = grid_location.y;
}

int2 GridActor::GetGridCellLocation()
{
	int2 grid_cell_location = {grid_location_.x, grid_location_.y};
	return grid_cell_location;
}
