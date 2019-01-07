#pragma once
#include "UnitMovementComponent.h"

struct CellNode
{
	int2 index;
	float cost;
	shared_ptr<CellNode> prev;
	CellNode() {}
	CellNode(int2 _index, float _cost, shared_ptr<CellNode> _prev) : index(_index), cost(_cost), prev(_prev) {}
};

class PathMovement :
	public UnitMovementComponent
{
protected:
	int2 finish_;
	stack<int2> path_;
	bool path_rebuild_;
	float Heuristic(int2 cur_node);
public:
	PathMovement();
	~PathMovement();
	//void SetDestination(int2 destination);
	void MoveTo(int2 finish);
	void Move(shared_ptr<Grid> grid, float2 &location);
	void CalculatePath(shared_ptr<Grid> grid, int2 cur_location);
	void UpdateMovement(shared_ptr<Grid> grid);
};

