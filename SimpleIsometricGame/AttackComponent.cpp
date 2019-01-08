#include "stdafx.h"
#include "AttackComponent.h"


AttackComponent::AttackComponent()
{
}


AttackComponent::~AttackComponent()
{
}

void AttackComponent::Attack(shared_ptr<Grid> grid, int2 cur_location)
{
	grid->SetKillzoneMask(cur_location);
}
