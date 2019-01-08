#pragma once
#include "DrawableObject.h"
#include "Grid.h"
class GridActor :
	public DrawableObject
{
protected:
	float2 grid_location_;
	shared_ptr<Grid> grid_;
public:
	GridActor();
	GridActor(shared_ptr<Grid> grid, int2 grid_location);
	~GridActor();
	void SetGridCellLocation(float2 grid_location);
	int2 GetGridCellLocation();
	float2 GetGridLocation();
	virtual void Update();
	virtual void SetGrid(shared_ptr<Grid> grid);
};

