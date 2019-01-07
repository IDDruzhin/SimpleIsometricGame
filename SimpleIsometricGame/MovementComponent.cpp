#include "stdafx.h"
#include "MovementComponent.h"


MovementComponent::MovementComponent():is_moving_(false),speed_(1.0f)
{
}


MovementComponent::~MovementComponent()
{
}

void MovementComponent::SetSpeed(float speed)
{
	speed_ = speed;
	float norm = velocity_.Norm(velocity_);
	velocity_.x = speed_ * velocity_.x / norm;
	velocity_.y = speed_ * velocity_.y / norm;
}

void MovementComponent::SetDirection(float2 dir)
{
	float norm = dir.Norm(dir);
	if (norm < 1e-6)
	{
		velocity_ = float2(0.0f, 0.0f);
	}
	else
	{
		velocity_.x = speed_ * dir.x / norm;
		velocity_.y = speed_ * dir.y / norm;
	}
}

void MovementComponent::UpdateLocation(float2 & location)
{
	float ratio = GameSystem::GetInstance()->GetElapsedSeconds();
	location.x += velocity_.x * ratio;
	location.y += velocity_.y * ratio;
	//location.x += velocity_.x;
	//location.y += velocity_.y;
}

bool MovementComponent::IsMoving()
{
	return is_moving_;
}

void MovementComponent::SetMovement(bool is_moving)
{
	is_moving_ = is_moving;
}

float2 MovementComponent::GetVelocity()
{
	return velocity_;
}

void MovementComponent::Move(shared_ptr<Grid> grid, float2 &location)
{
	if (is_moving_)
	{
		UpdateLocation(location);
	}
}
