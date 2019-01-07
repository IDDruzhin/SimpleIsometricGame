#pragma once
#include "MovementComponent.h"
class PatrolMovement :
	public MovementComponent
{
protected:
	int2 first_;
	int2 second_;
	float wait_time_;
	Timer timer_;
public:
	PatrolMovement(int2 first, int2 second, float speed = 1.0f);
	~PatrolMovement();
	virtual void Move(shared_ptr<Grid> grid, float2 &location);
};

