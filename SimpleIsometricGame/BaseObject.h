#pragma once
class BaseObject
{
protected:
	float2 screen_location_;
public:
	BaseObject();
	~BaseObject();
	void SetWorldLocation(float2 world_location);
	float2 GetWorldLocation();
};

