#pragma once
#include "GameSystem.h"
#include "Grid.h"
class MovementComponent
{
protected:
	float2 velocity_;
	float speed_;
	bool is_moving_;
	void UpdateLocation(float2 &location);
public:
	MovementComponent();
	~MovementComponent();
	void SetSpeed(float speed);
	void SetDirection(float2 dir);
	bool IsMoving();
	void SetMovement(bool is_moving);
	float2 GetVelocity();
	virtual void Move(shared_ptr<Grid> grid, float2 &location);
};

