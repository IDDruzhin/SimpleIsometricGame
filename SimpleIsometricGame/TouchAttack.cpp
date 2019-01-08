#include "stdafx.h"
#include "TouchAttack.h"


TouchAttack::TouchAttack()
{
}


TouchAttack::~TouchAttack()
{
}

void TouchAttack::Attack(shared_ptr<Grid> grid, int2 cur_location)
{
	grid->SetKillzoneMask(cur_location);
}
