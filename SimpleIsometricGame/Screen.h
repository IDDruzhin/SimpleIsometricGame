#pragma once
#include "GraphicsComponent.h"
//#include "InputController.h"

class Screen
{
public:
	Screen();
	~Screen();
	virtual void Draw(shared_ptr<GraphicsComponent> graphics_component) = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual bool IsRunning() = 0;
};

