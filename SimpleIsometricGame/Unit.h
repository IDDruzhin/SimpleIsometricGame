#pragma once
#include "GridActor.h"
#include "MovementComponent.h"
class Unit :
	public GridActor
{
protected:
	shared_ptr<MovementComponent> movement_component_;
public:
	Unit();
	Unit(shared_ptr<Grid> grid, int2 grid_location);
	~Unit();
	virtual void Update();
};

