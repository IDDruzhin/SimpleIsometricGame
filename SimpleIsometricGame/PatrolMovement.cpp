#include "stdafx.h"
#include "PatrolMovement.h"


PatrolMovement::PatrolMovement(int2 first, int2 second, float speed):start_(first)
{
	speed_ = speed;
	wait_time_ = 1.0f;
	SetDestination(second);
}

PatrolMovement::~PatrolMovement()
{
}

void PatrolMovement::Move(shared_ptr<Grid> grid, float2 & location)
{
	grid->SetEmployMask(start_);
	if (is_moving_)
	{
		UpdateLocation(location);
		grid->SetEmployMask(destination_);
		if (FinishAtDestination(location))
		{
			is_moving_ = false;
			timer_.Restart();
			swap(start_, destination_);
		}
		/*
		UpdateLocation(location);
		grid->SetEmployMask(destination_);
		float2 dest_vector;
		dest_vector.x = destination_.x + 0.5f - location.x;
		dest_vector.y = destination_.y + 0.5f - location.y;
		if (dest_vector.Dot(dest_vector, velocity_) < 0)
		{
			location.x = destination_.x + 0.5f;
			location.y = destination_.y + 0.5f;
			is_moving_ = false;
			timer_.Restart();
			swap(start_, destination_);
		}
		*/
	}
	else
	{
		float time = timer_.GetElapsedSeconds() - wait_time_;
		if (time > 0)
		{
			bool block = grid->CheckBlockMask(destination_);
			bool emp = grid->CheckEmployMask(destination_);
			if (!(grid->CheckBlockMask(destination_) || grid->CheckEmployMask(destination_)))
			{
				float2 dest_vector;
				dest_vector.x = destination_.x + 0.5f - location.x;
				dest_vector.y = destination_.y + 0.5f - location.y;
				SetDirection(dest_vector);
				is_moving_ = true;
				grid->SetEmployMask(destination_);
			}
		}
	}
}
