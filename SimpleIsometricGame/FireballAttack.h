#pragma once
#include "ProjectileShootComponent.h"
#include "FireBall.h"
class FireballAttack :
	public ProjectileShootComponent
{
protected:
	static shared_ptr<FireBall> fireball_prototype_;
	shared_ptr<Projectile> GetProjectile();
public:
	FireballAttack(shared_ptr<GraphicsEngine> graphics_engine, int2 direction, float shoot_speed = 3.0f, float reload_time = 3.0f);
	~FireballAttack();
};

