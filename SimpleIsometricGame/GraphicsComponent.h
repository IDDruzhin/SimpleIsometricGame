#pragma once
#include "Timer.h"

class GraphicsComponent
{
public:
	GraphicsComponent();
	~GraphicsComponent();
	virtual void SetLocation(float2 location) = 0;
	virtual void SetColor(uchar r = 255, uchar g = 255, uchar b = 255, uchar a = 255) = 0;
	virtual void SetOrigin(int2 origin) = 0;
	virtual void SetSpriteRect(Rect r) = 0;
};

