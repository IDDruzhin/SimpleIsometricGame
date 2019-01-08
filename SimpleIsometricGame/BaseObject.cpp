#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject():is_active_(true)
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

void BaseObject::Update()
{
}

bool BaseObject::IsActive()
{
	return is_active_;
}

void BaseObject::SetActivity(bool is_active)
{
	is_active_ = is_active;
}

void BaseObject::Destroy()
{
	SetActivity(false);
}


