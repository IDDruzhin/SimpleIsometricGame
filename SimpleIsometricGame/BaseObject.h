#pragma once
class BaseObject
{
protected:
	float2 world_location_;
public:
	BaseObject();
	~BaseObject();
	void SetWorldLocation(float2 world_location);
	float2 GetWorldLocation();
};

