#pragma once
#include "GridActor.h"
#include "MovementComponent.h"
#include "AttackComponent.h"
class Projectile :
	public GridActor
{
protected:
	shared_ptr<MovementComponent> movement_component_;
	shared_ptr<AttackComponent> attack_component;
public:
	Projectile(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir = float2(1.0f, 0.0f), float speed = 3.0f);
	~Projectile();
	void Update();
	shared_ptr<Projectile> Copy();
};

