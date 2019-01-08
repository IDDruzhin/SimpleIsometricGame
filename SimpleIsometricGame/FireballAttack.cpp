#include "stdafx.h"
#include "FireballAttack.h"

shared_ptr<Projectile> FireballAttack::GetProjectile()
{
	return fireball_prototype_->Clone();
}

FireballAttack::FireballAttack(shared_ptr<GraphicsEngine> graphics_engine, int2 direction, float shoot_speed, float reload_time):ProjectileShootComponent(graphics_engine, direction, shoot_speed, reload_time)
{
	if (fireball_prototype_ == nullptr)
	{
		fireball_prototype_ = make_shared<FireBall>(graphics_engine);
	}
}

FireballAttack::~FireballAttack()
{
}

shared_ptr<FireBall> FireballAttack::fireball_prototype_ = nullptr;
