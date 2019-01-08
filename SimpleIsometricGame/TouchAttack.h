#pragma once
#include "AttackComponent.h"
class TouchAttack :
	public AttackComponent
{
public:
	TouchAttack();
	~TouchAttack();
	virtual void Attack(shared_ptr<Grid> grid, int2 cur_location);
};

