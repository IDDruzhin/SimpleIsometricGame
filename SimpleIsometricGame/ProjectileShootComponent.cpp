#include "stdafx.h"
#include "ProjectileShootComponent.h"

ProjectileShootComponent::ProjectileShootComponent(int2 direction, float reload_time)
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
		//SpawnProjectile();
		reload_timer_.Restart(time);
	}
}
