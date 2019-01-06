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
	need_update |= sprite_sheet_component_->NextFrame();
	if (need_update)
	{
		graphics_component_->SetSpriteRect(sprite_sheet_component_->GetCurRect());
	}
}
