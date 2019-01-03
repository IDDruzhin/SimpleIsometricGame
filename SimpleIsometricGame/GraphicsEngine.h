#pragma once
#include "GraphicsComponent.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	virtual shared_ptr<GraphicsComponent> RegisterGraphicsResource(string path) = 0;
};

