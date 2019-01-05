#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
	screen_location_.x = 0;
	screen_location_.y = 0;
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

