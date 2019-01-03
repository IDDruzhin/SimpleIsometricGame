#pragma once
#include "BaseObject.h"
class GridActor :
	public BaseObject
{
protected:
	int2 GridLocation;
	//shared_ptr<GraphicsComponent> CGraphics;
public:
	GridActor();
	~GridActor();
};

