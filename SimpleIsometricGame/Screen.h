#pragma once
#include "GraphicsComponent.h"
#define DEFAULT_WIDTH 1024
#define DEFAULT_HEIGHT 768

class Screen
{
public:
	Screen();
	~Screen();
	virtual void Draw(shared_ptr<GraphicsComponent> graphics_component) = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual bool IsRunning() = 0;
	virtual void Zoom(float factor) = 0;
	virtual void SetCenter(float2 center) = 0;
	virtual float2 GetCenter() = 0;
	virtual float2 GetSize() = 0;
	virtual float2 PixelToCoord(int2 pixel_pos) = 0;
};

