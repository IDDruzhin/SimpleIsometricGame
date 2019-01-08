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

int2 GridActor::GetGridCellLocation()
{
	int2 cell_location(grid_location_.x, grid_location_.y);
	return cell_location;
}

float2 GridActor::GetGridLocation()
{
	return grid_location_;
}

void GridActor::Update()
{
	screen_location_ = grid_->GridToScreen(grid_location_);
	DrawableObject::Update();
}

void GridActor::SetGrid(shared_ptr<Grid> grid)
{
	grid_ = grid;
}
