#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

void BaseObject::SetWorldLocation(float2 l)
{
	WorldLocation = l;
}

float2 BaseObject::GetWorldLocation()
{
	return WorldLocation;
}
