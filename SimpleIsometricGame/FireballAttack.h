#pragma once
#include "ProjectileShootComponent.h"
#include "FireBall.h"
class FireballAttack :
	public ProjectileShootComponent
{
protected:
	virtual void SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location);
public:
	FireballAttack(int2 direction = int2(1, 0), float reload_time = 3.0f);
	~FireballAttack();
};

