#pragma once
#include "Grid.h"
#include "AttackComponent.h"
#include "Projectile.h"
class ProjectileShootComponent :
	public AttackComponent
{
protected:
	float shoot_speed_;
	float reload_time_;
	Timer reload_timer_;
	int2 direction_;
	virtual shared_ptr<Projectile> GetProjectile() = 0;
	virtual void SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location);
public:
	ProjectileShootComponent(shared_ptr<GraphicsEngine> graphics_engine, int2 direction, float shoot_speed = 3.0f, float reload_time = 3.0f);
	~ProjectileShootComponent();
	void Attack(shared_ptr<Grid> grid, int2 cur_location);
};

