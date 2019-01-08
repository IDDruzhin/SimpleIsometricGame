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
	virtual void UpdateSprite(int cur_state);
public:
	DrawableObject();
	DrawableObject(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info = nullptr);
	~DrawableObject();
	virtual void RegisterGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info = nullptr);
	virtual void Draw(shared_ptr<Screen> screen);
	virtual int GetState();
	virtual void Update();
	virtual void SetScale(float scale);
	virtual void SetScale(float2 scale);
	virtual void Scale(float2 scale);
	virtual Rect GetSpriteRect();
	virtual void CenterOrigin();
};

