#pragma once
#include "Timer.h"

class GraphicsComponent
{
public:
	GraphicsComponent();
	~GraphicsComponent();
	virtual void SetLocation(float2 location) = 0;
	virtual void SetScale(float scale) = 0;
	virtual void SetScale(float2 scale) = 0;
	virtual void Scale(float2 scale) = 0;
	virtual void SetColor(uchar r = 255, uchar g = 255, uchar b = 255, uchar a = 255) = 0;
	virtual void SetOrigin(int2 origin) = 0;
	virtual void SetSpriteRect(Rect r) = 0;
	virtual Rect GetSpriteRect() = 0;
	virtual void CenterOrigin() = 0;
	virtual shared_ptr<GraphicsComponent> Clone() = 0;
};

