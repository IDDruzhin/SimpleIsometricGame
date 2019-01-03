#pragma once
class BaseObject
{
protected:
	float2 screen_location_;
public:
	BaseObject();
	~BaseObject();
	void SetScreenLocation(float2 screen_location);
	float2 GetScreenLocation();
};

