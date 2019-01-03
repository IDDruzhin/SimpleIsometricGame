#pragma once
#include "GraphicsComponent.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	virtual shared_ptr<GraphicsComponent> RegisterGraphicsResource(const string &path) = 0;
};

