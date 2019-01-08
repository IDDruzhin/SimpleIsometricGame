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

void Unit::MoveTo(int2 finish)
{
	movement_component_->MoveTo(finish);
}

void Unit::UpdateMovement()
{
	movement_component_->UpdateMovement(grid_);
}

int2 Unit::GetDestination()
{
	return movement_component_->GetDestination();
}
