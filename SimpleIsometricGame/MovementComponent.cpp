#include "stdafx.h"
#include "MovementComponent.h"


MovementComponent::MovementComponent():is_moving_(false)
{
}


MovementComponent::~MovementComponent()
{
}

void MovementComponent::SetSpeed(float speed)
{
	speed_ = speed;
	float norm = Norm(velocity_);
	velocity_.x = speed_ * velocity_.x / norm;
	velocity_.y = speed_ * velocity_.y / norm;
}

void MovementComponent::SetDirection(float2 dir)
{
	float norm = Norm(dir);
	velocity_.x = speed_ * dir.x / norm;
	velocity_.y = speed_ * dir.y / norm;
}

void MovementComponent::UpdateLocation(float2 & location)
{
	float ratio = GameSystem::GetInstance()->GetElapsedSeconds();
	location.x += velocity_.x * ratio;
	location.y += velocity_.y * ratio;
}

bool MovementComponent::IsMoving()
{
	return is_moving_;
}

float2 MovementComponent::GetVelocity()
{
	return velocity_;
}

void MovementComponent::Move(shared_ptr<Grid> grid, float2 &location)
{
	UpdateLocation(location);
}
