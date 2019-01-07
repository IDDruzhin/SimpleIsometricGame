#pragma once
#include "MovementComponent.h"
class UnitMovementComponent :
	public MovementComponent
{
protected:
	int2 destination_;
public:
	UnitMovementComponent();
	~UnitMovementComponent();
	virtual void SetDestination(int2 destination);
	virtual bool FinishAtDestination(float2 &location);
	virtual void UpdateMovement(shared_ptr<Grid> grid);
	virtual void MoveTo(int2 finish);
	virtual void Move(shared_ptr<Grid> grid, float2 &location);
	virtual void CalcVelocity(float2 &location);
	int2 GetDestination();
};

