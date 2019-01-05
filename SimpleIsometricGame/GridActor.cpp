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
	int2 grid_cell_location;
	grid_cell_location.x = grid_location_.x + 0.5f;
	grid_cell_location.y = grid_location_.y + 0.5f;
	return grid_cell_location;
}
