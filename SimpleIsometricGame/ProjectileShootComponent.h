#pragma once
#include "AttackComponent.h"
#include "Projectile.h"
class ProjectileShootComponent :
	public AttackComponent
{
protected:
	float reload_time_;
	Timer reload_timer_;
	int2 direction_;
	shared_ptr<Projectile> projectile_;
	//virtual void SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location) = 0;
public:
	ProjectileShootComponent(int2 direction = int2(1,0), float reload_time = 3.0f);
	~ProjectileShootComponent();
	void Attack(shared_ptr<Grid> grid, int2 cur_location);
};

