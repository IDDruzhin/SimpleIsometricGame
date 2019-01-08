#pragma once
#include "UnitMovementComponent.h"
class PatrolMovement :
	public UnitMovementComponent
{
protected:
	int2 start_;
	float wait_time_;
	Timer timer_;
public:
	PatrolMovement(int2 first, int2 second, float speed = 1.0f);
	~PatrolMovement();
	virtual void Move(shared_ptr<Grid> grid, float2 &location);
};

