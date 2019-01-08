#pragma once
#include "GridActor.h"
#include "ProjectileShootComponent.h"
class Cannon :
	public GridActor
{
protected:
	shared_ptr<ProjectileShootComponent> attack_component_;
public:
	Cannon(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location);
	Cannon();
	~Cannon();
	virtual void Update();
};

