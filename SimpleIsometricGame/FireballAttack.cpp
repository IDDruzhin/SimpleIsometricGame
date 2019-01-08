#include "stdafx.h"
#include "FireballAttack.h"

shared_ptr<Projectile> FireballAttack::GetProjectile()
{
	return fireball_prototype_;
}

FireballAttack::FireballAttack(shared_ptr<GraphicsEngine> graphics_engine, float shoot_speed, int2 direction, float reload_time):ProjectileShootComponent(graphics_engine, shoot_speed, direction, reload_time)
{
	if (fireball_prototype_ == nullptr)
	{
		fireball_prototype_ = make_shared<FireBall>(graphics_engine);
	}
}

FireballAttack::~FireballAttack()
{
}

shared_ptr<Projectile> FireballAttack::fireball_prototype_ = nullptr;
