#pragma once
#include "BaseObject.h"
#include "GraphicsComponent.h"
#include "SpriteSheetComponent.h"
class DrawableObject :
	public BaseObject
{
protected:
	shared_ptr<GraphicsComponent> graphics_component_;
	shared_ptr<SpriteSheetComponent> sprite_sheet_component_;
public:
	DrawableObject();
	~DrawableObject();
	virtual void Draw(shared_ptr<Screen> screen);
	virtual void UpdateSprite(uint cur_state_);
};

