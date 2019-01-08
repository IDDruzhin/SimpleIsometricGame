#pragma once
#include "GraphicsEngine.h"
#include "Screen.h"

class BaseObject
{
protected:
	float2 screen_location_;
	bool is_active_;
public:
	BaseObject();
	~BaseObject();
	void SetScreenLocation(float2 screen_location);
	float2 GetScreenLocation();
	virtual void Update();
	bool IsActive();
	virtual void SetActivity(bool is_active);
	virtual void Destroy();
};

