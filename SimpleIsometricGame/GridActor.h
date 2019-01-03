#pragma once
#include "BaseObject.h"
class GridActor :
	public BaseObject
{
protected:
	float2 grid_location_;
	//shared_ptr<GraphicsComponent> CGraphics;
public:
	GridActor();
	~GridActor();
	void SetGridCellLocation(int2 grid_location);
	int2 GetGridCellLocation();
};

