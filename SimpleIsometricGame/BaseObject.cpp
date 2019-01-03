#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

void BaseObject::SetWorldLocation(float2 world_location)
{
	world_location_ = world_location;
}

float2 BaseObject::GetWorldLocation()
{
	return world_location_;
}
