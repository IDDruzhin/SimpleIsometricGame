#include "stdafx.h"
#include "PathMovement.h"


PathMovement::PathMovement()
{
}


PathMovement::~PathMovement()
{
}

void PathMovement::SetDestination(int2 destination)
{
	finish_ = destination_;
	path_rebuild_ = true;
}

void PathMovement::Move(shared_ptr<Grid> grid, float2 & location)
{
	UnitMovementComponent::Move(grid, location);
	if (path_rebuild_)
	{
		CalculatePath(grid, int2(location.x, location.y));
	}
	if (!path_.empty())
	{
		destination_ = path_.top();
		path_.pop();
		is_moving_ = true;
	}
}

void PathMovement::CalculatePath(shared_ptr<Grid> grid, int2 cur_location)
{
}

void PathMovement::UpdateMovement(shared_ptr<Grid> grid)
{
	if (grid->CheckBlockMask(finish_))
	{
		if (is_moving_)
		{
			is_moving_ = false;
			path_rebuild_ = true;
		}
	}
}
