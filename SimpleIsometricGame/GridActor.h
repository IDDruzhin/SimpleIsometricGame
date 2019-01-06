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
	~GridActor();
	void SetGridCellLocation(float2 grid_location);
	float2 GetGridCellLocation();
};

