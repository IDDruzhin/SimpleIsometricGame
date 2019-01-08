#include "stdafx.h"
#include "FireballAttack.h"

void FireballAttack::SpawnProjectile(shared_ptr<Grid> grid, int2 cur_location)
{
	//GameSystem::GetInstance()->AddGridActor(make_shared<FireBall>());
}

FireballAttack::FireballAttack(int2 direction, float reload_time):ProjectileShootComponent(direction, reload_time)
{
}

FireballAttack::~FireballAttack()
{
}
