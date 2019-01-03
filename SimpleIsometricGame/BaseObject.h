#pragma once
class BaseObject
{
protected:
	float2 WorldLocation;
public:
	BaseObject();
	~BaseObject();
	void SetWorldLocation(float2 l);
	float2 GetWorldLocation();
};

