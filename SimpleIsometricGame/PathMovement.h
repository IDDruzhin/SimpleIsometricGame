#pragma once
#include "UnitMovementComponent.h"

struct CellNode
{
	int2 index;
	uint cost;
	shared_ptr<CellNode> prev;
};

class PathMovement :
	public UnitMovementComponent
{
protected:
	int2 finish_;
	stack<int2> path_;
	bool path_rebuild_;
public:
	PathMovement();
	~PathMovement();
	void SetDestination(int2 destination);
	void Move(shared_ptr<Grid> grid, float2 &location);
	void CalculatePath(shared_ptr<Grid> grid, int2 cur_location);
	void UpdateMovement(shared_ptr<Grid> grid);
};
