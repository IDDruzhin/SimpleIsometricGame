#include "stdafx.h"
#include "PatrolMovement.h"


PatrolMovement::PatrolMovement(int2 first, int2 second, float speed):first_(first),second_(second)
{
	speed_ = speed;
	wait_time_ = 1.0f;
}

PatrolMovement::~PatrolMovement()
{
}

void PatrolMovement::Move(shared_ptr<Grid> grid, float2 & location)
{
	grid->SetEmployMask(first_);
	if (is_moving_)
	{
		UpdateLocation(location);
		grid->SetEmployMask(second_);
		float2 dest_vector;
		dest_vector.x = second_.x + 0.5f - location.x;
		dest_vector.y = second_.y + 0.5f - location.y;
		if (dest_vector.Dot(dest_vector, velocity_) < 0)
		{
			location.x = second_.x + 0.5f;
			location.y = second_.y + 0.5f;
			is_moving_ = false;
			timer_.Restart();
			swap(first_, second_);
		}
	}
	else
	{
		float time = timer_.GetElapsedSeconds() - wait_time_;
		if (time > 0)
		{
			bool block = grid->CheckBlockMask(second_);
			bool emp = grid->CheckEmployMask(second_);
			if (!(grid->CheckBlockMask(second_) || grid->CheckEmployMask(second_)))
			{
				float2 dest_vector;
				dest_vector.x = second_.x + 0.5f - location.x;
				dest_vector.y = second_.y + 0.5f - location.y;
				SetDirection(dest_vector);
				is_moving_ = true;
				grid->SetEmployMask(second_);
			}
		}
	}
}
