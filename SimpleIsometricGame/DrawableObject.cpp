#include "stdafx.h"
#include "DrawableObject.h"


DrawableObject::DrawableObject()
{
}


DrawableObject::~DrawableObject()
{
}

void DrawableObject::RegisterGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info)
{
}

void DrawableObject::Draw(shared_ptr<Screen> screen)
{
	screen->Draw(graphics_component_);
}

void DrawableObject::UpdateSprite(uint cur_state_)
{
	bool need_update = false;
	need_update = sprite_sheet_component_->SetState(cur_state_);
	if (need_update)
	{
		graphics_component_->SetSpriteRect(sprite_sheet_component_->GetCurRect());
	}
	else
	{
		need_update = sprite_sheet_component_->NextFrame();
		if (need_update)
		{
			graphics_component_->SetSpriteRect(sprite_sheet_component_->GetCurRect());
		}
	}
}

uint DrawableObject::GetState()
{
	return 0;
}

void DrawableObject::Update()
{
	graphics_component_->SetLocation(screen_location_);
	if (sprite_sheet_component_)
	{
		UpdateSprite(GetState());
	}
}
