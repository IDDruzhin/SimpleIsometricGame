#pragma once
#include "Unit.h"
#include "PatrolMovement.h"
#include "AttackComponent.h"
class Guardian :
	public Unit
{
private:
	static const int GUARDIAN_STATES[];
protected:
	shared_ptr<AttackComponent> attack_component;
public:
	Guardian(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, int2 patrol_direction);
	~Guardian();
	virtual uint GetState();
	virtual void Update();
};

