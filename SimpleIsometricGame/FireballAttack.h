#pragma once
#include "ProjectileShootComponent.h"
#include "FireBall.h"
class FireballAttack :
	public ProjectileShootComponent
{
protected:
	static shared_ptr<Projectile> fireball_prototype_;
	shared_ptr<Projectile> GetProjectile();
public:
	FireballAttack(shared_ptr<GraphicsEngine> graphics_engine, float shoot_speed = 3.0f, int2 direction = int2(1, 0), float reload_time = 3.0f);
	~FireballAttack();
};

