#pragma once
#include "GameSystem.h"
#include "Grid.h"
class MovementComponent
{
protected:
	float2 velocity_;
	float speed_;
	bool is_moving_;
public:
	MovementComponent();
	~MovementComponent();
	void SetSpeed(float speed);
	void SetDirection(float2 dir);
	void UpdateLocation(float2 &location);
	bool IsMoving();
	void SetMovement(bool is_moving);
	float2 GetVelocity();
	virtual void Move(shared_ptr<Grid> grid, float2 &location);
};

