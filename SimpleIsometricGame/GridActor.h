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
	int2 GetGridCellLocation();
};

