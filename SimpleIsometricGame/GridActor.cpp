#include "stdafx.h"
#include "GridActor.h"


GridActor::GridActor()
{
}


GridActor::~GridActor()
{
}

void GridActor::SetGridCellLocation(float2 grid_location)
{
	grid_location_.x = grid_location.x;
	grid_location_.y = grid_location.y;
}

float2 GridActor::GetGridCellLocation()
{
	return grid_location_;
}
