#pragma once
#include "BaseObject.h"
class GridActor :
	public BaseObject
{
protected:
	int2 grid_location_;
	//shared_ptr<GraphicsComponent> CGraphics;
public:
	GridActor();
	~GridActor();
};

