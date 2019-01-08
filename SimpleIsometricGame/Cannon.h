#pragma once
#include "GridActor.h"
class Cannon :
	public GridActor
{
protected:
	float shoot_interval_;
	Timer shoot_timer_;
	int direction;
public:
	enum CANNON_DIRECTION
	{
		RIGHT,
		DOWN,
		LEFT,
		TOP
	};
	Cannon();
	~Cannon();
};

