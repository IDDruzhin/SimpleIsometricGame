#pragma once
class GraphicsComponent
{
public:
	GraphicsComponent();
	~GraphicsComponent();
	virtual void SetLocation(float2 location) = 0;
};

