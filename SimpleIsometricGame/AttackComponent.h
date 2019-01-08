#pragma once
#include "GameSystem.h"
#include "Grid.h"
class AttackComponent
{
public:
	AttackComponent();
	~AttackComponent();
	virtual void Attack(shared_ptr<Grid> grid, int2 cur_location);
};

