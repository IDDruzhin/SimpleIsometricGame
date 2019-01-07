#include "stdafx.h"
#include "Unit.h"


Unit::Unit()
{
}

Unit::Unit(shared_ptr<Grid> grid, int2 grid_location):GridActor(grid, grid_location)
{
}


Unit::~Unit()
{
}

void Unit::Update()
{
	movement_component_->Move(grid_, grid_location_);
	GridActor::Update();
}

int2 Unit::GetDestination()
{
	return movement_component_->GetDestination();
}
