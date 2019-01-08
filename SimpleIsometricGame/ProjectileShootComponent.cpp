#include "stdafx.h"
#include "ProjectileShootComponent.h"

void ProjectileShootComponent::SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location)
{
	shared_ptr<Projectile> projectile = GetProjectile();
	projectile->SetDirection(float2(direction_.x,direction_.y));
	projectile->SetSpeed(shoot_speed_);
}

ProjectileShootComponent::ProjectileShootComponent(shared_ptr<GraphicsEngine> graphics_engine, float shoot_speed, int2 direction, float reload_time):shoot_speed_(shoot_speed),direction_(direction),reload_time_(reload_time)
{
}

ProjectileShootComponent::~ProjectileShootComponent()
{
}

void ProjectileShootComponent::Attack(shared_ptr<Grid> grid, int2 cur_location)
{
	float time = reload_timer_.GetElapsedSeconds() - reload_time_;
	if (time > 0)
	{
		SpawnProjectile(grid, cur_location);
		reload_timer_.Restart(time);
	}
}
