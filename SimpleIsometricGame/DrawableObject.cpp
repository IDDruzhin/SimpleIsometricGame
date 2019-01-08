#include "stdafx.h"
#include "DrawableObject.h"


DrawableObject::DrawableObject()
{
}

DrawableObject::DrawableObject(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info)
{
	RegisterGraphics(graphics_engine, path, sheet_info);
}


DrawableObject::~DrawableObject()
{
}

void DrawableObject::RegisterGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info)
{
	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, path, sheet_info);
}

void DrawableObject::Draw(shared_ptr<Screen> screen)
{
	screen->Draw(graphics_component_);
}

void DrawableObject::UpdateSprite(int cur_state)
{
	bool need_update = false;
	if (cur_state >= 0)
	{
		need_update = sprite_sheet_component_->SetState(cur_state);
	}
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

int DrawableObject::GetState()
{
	return -1;
}

void DrawableObject::Update()
{
	graphics_component_->SetLocation(screen_location_);
	if (sprite_sheet_component_)
	{
		UpdateSprite(GetState());
	}
}
/*
float2 DrawableObject::GetSize()
{
	return graphics_component_->GetSpriteRect();
}
*/

void DrawableObject::SetScale(float scale)
{
	graphics_component_->SetScale(scale);
}

void DrawableObject::Scale(float2 scale)
{
	graphics_component_->Scale(scale);
}

void DrawableObject::SetScale(float2 scale)
{
	graphics_component_->SetScale(scale);
}

Rect DrawableObject::GetSpriteRect()
{
	return graphics_component_->GetSpriteRect();
}

void DrawableObject::CenterOrigin()
{
	graphics_component_->CenterOrigin();
}
