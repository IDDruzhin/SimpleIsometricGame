#include "stdafx.h"
#include "PathMovement.h"


PathMovement::PathMovement():path_rebuild_(false)
{
}


PathMovement::~PathMovement()
{
}
/*
void PathMovement::SetDestination(int2 destination)
{
	finish_ = destination;
	path_rebuild_ = true;
}
*/
void PathMovement::MoveTo(int2 finish)
{
	finish_ = finish;
	path_rebuild_ = true;
}

void PathMovement::Move(shared_ptr<Grid> grid, float2 & location)
{
	UnitMovementComponent::Move(grid, location);
	if (!is_moving_)
	{
		if (path_rebuild_)
		{
			CalculatePath(grid, int2(location.x, location.y));
			path_rebuild_ = false;
		}
		if (!path_.empty())
		{
			destination_ = path_.top();
			CalcVelocity(location);
			path_.pop();
			is_moving_ = true;
		}
	}
	/*
	if (path_rebuild_)
	{
		CalculatePath(grid, int2(location.x, location.y));
		path_rebuild_ = false;
		if (!path_.empty())
		{
			destination_ = path_.top();
			CalcVelocity(location);
			path_.pop();
			is_moving_ = true;
		}
	}
	if (is_moving_)
	{
		if (!path_.empty())
		{
			destination_ = path_.top();
			CalcVelocity(location);
			path_.pop();
			is_moving_ = true;
		}
	}
	*/
}

void PathMovement::CalculatePath(shared_ptr<Grid> grid, int2 cur_location)
{
	///Dijkstra
	bool path_exist = false;
	path_ = stack<int2>();
	Bitset visited_nodes_mask(grid->GetDim().x * grid->GetDim().y);
	vector<shared_ptr<CellNode>> border_nodes;
	shared_ptr<CellNode> cur = make_shared<CellNode>(cur_location, 0, nullptr);
	border_nodes.push_back(cur);
	while (!border_nodes.empty())
	{
		auto min = min_element(border_nodes.begin(), border_nodes.end(), [](const shared_ptr<CellNode> &a, const shared_ptr<CellNode> &b) {return (a->cost < b->cost); });
		cur = *min;
		/*
		if (cur->index.x == 10)
		{
			if (cur->index.y == 5)
			{
				cout << "AAA" << endl;
			}
		}
		*/
		if (cur->index == finish_)
		{
			path_exist = true;
			break;
		}
		border_nodes.erase(min);
		/*
		cout << "Element: " << cur->index.x << " " << cur->index.y << endl;
		grid->PrintMask(visited_nodes_mask);
		*/
		visited_nodes_mask.Set(cur->index.y * grid->GetDim().x + cur->index.x, true);
		//grid->PrintMask(visited_nodes_mask);
		int tst_ind = cur->index.y * grid->GetDim().x + cur->index.x;
		bool tst = visited_nodes_mask.Get(tst_ind);
		int2 pos;
		int mask_pos;
		float cost;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				pos = cur->index;
				pos.x += j;
				pos.y += i;
				if (!(grid->IsInsideGrid(pos)))
				{
					continue;
				}
				mask_pos = pos.y * grid->GetDim().x + pos.x;
				if (!(visited_nodes_mask.Get(mask_pos)))
				{
					cost = cur->cost;
					if ((abs(i) + abs(j)) >= 2)
					{
						cost += 1.4f;
					}
					else
					{
						cost += 1.0f;
					}
					auto find = find_if(border_nodes.begin(), border_nodes.end(), [&pos](shared_ptr<CellNode> node) {return (node->index == pos); });
					shared_ptr<CellNode> next;
					if (find != border_nodes.end())
					{
						next = *find;
						if (cost < next->cost)
						{
							next->cost = cost;
							next->prev = cur;
						}
					}
					else
					{
						next = make_shared<CellNode>(pos,cost,cur);
						border_nodes.push_back(next);
					}
				}
			}
		}
	}
	if (path_exist)
	{
		while (cur->prev)
		{
			path_.push(cur->index);
			cur = cur->prev;
		}		
	}
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
