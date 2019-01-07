#pragma once
#include "GridActor.h"
#include "UnitMovementComponent.h"
class Unit :
	public GridActor
{
protected:
	shared_ptr<UnitMovementComponent> movement_component_;
public:
	Unit();
	Unit(shared_ptr<Grid> grid, int2 grid_location);
	~Unit();
	virtual void Update();
	int2 GetDestination();
};

