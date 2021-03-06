#pragma once
#include "GridActor.h"
#include "MovementComponent.h"
#include "AttackComponent.h"
class Projectile :
	public GridActor
{
protected:
	shared_ptr<MovementComponent> movement_component_;
	shared_ptr<AttackComponent> attack_component_;
public:
	Projectile();
	Projectile(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir = float2(1.0f, 0.0f), float speed = 3.0f);
	~Projectile();
	void Update();
	virtual shared_ptr<Projectile> Clone();
	virtual void SetSpeed(float speed);
	virtual void SetDirection(float2 dir);
	virtual void SetState(float2 dir);
};

