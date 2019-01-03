#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

void BaseObject::SetScreenLocation(float2 screen_location)
{
	screen_location_ = screen_location;
}

float2 BaseObject::GetScreenLocation()
{
	return screen_location_;
}
