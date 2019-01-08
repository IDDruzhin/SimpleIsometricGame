#pragma once
#include "GridActor.h"
#include "UnitMovementComponent.h"
class Unit :
	public GridActor
{
protected:
	shared_ptr<UnitMovementComponent> movement_component_;
public:
	enum UNIT_STATE
	{
		IDLE_RIGHT,
		IDLE_DOWN,
		IDLE_LEFT,
		IDLE_TOP,
		WALK_RIGHT,
		WALK_DOWN,
		WALK_LEFT,
		WALK_TOP,
		STATES_COUNT
	};
	Unit();
	Unit(shared_ptr<Grid> grid, int2 grid_location);
	~Unit();
	virtual void Update();
	virtual void MoveTo(int2 finish);
	virtual void UpdateMovement();
	int2 GetDestination();
};

