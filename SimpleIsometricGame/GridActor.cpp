#include "stdafx.h"
#include "GridActor.h"


GridActor::GridActor()
{
}

GridActor::GridActor(shared_ptr<Grid> grid, int2 grid_location)
{
	grid_ = grid;
	grid_location_.x = grid_location.x + 0.5f;
	grid_location_.y = grid_location.y + 0.5f;
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

void GridActor::Update()
{
	screen_location_ = grid_->GridToScreen(grid_location_);
	DrawableObject::Update();
}
