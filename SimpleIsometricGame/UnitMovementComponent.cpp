#include "stdafx.h"
#include "UnitMovementComponent.h"


UnitMovementComponent::UnitMovementComponent()
{
}


UnitMovementComponent::~UnitMovementComponent()
{
}

void UnitMovementComponent::SetDestination(int2 destination)
{
	destination_.x = destination.x;
	destination_.y = destination.y;
}

bool UnitMovementComponent::FinishAtDestination(float2 &location)
{
	float2 tmp;
	tmp.x = destination_.x + 0.5f;
	tmp.y = destination_.y + 0.5f;
	float2 dest_vector;
	dest_vector.x = tmp.x - location.x;
	dest_vector.y = tmp.y - location.y;
	if (dest_vector.Dot(velocity_) < 0)
	{
		location.x = tmp.x;
		location.y = tmp.y;
		return true;
	}
	return false;
}

void UnitMovementComponent::UpdateMovement(shared_ptr<Grid> grid)
{
	if (grid->CheckBlockMask(destination_))
	{
		is_moving_ = false;
	}
}

