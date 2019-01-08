#include "stdafx.h"
#include "ProjectileShootComponent.h"

void ProjectileShootComponent::SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location)
{
	shared_ptr<Projectile> projectile = GetProjectile();
	projectile->SetGrid(grid);
	float2 loc;
	loc.x = cur_location.x + direction_.x + 0.5f;
	loc.y = cur_location.y + direction_.y + 0.5f;
	projectile->SetGridCellLocation(loc);
	projectile->SetDirection(float2(direction_.x,direction_.y));
	projectile->SetSpeed(shoot_speed_);
	GameSystem::GetInstance()->AddGridActor(projectile);
}

ProjectileShootComponent::ProjectileShootComponent(shared_ptr<GraphicsEngine> graphics_engine, int2 direction, float shoot_speed, float reload_time):shoot_speed_(shoot_speed),direction_(direction),reload_time_(reload_time)
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
