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
};

