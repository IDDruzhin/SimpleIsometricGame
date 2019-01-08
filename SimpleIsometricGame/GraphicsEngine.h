#pragma once
#include "GraphicsComponent.h"
#include "SpriteSheetComponent.h"

class GraphicsEngine
{
protected:
	static shared_ptr<GraphicsEngine> instance_;
	GraphicsEngine();
public:
	~GraphicsEngine();
	virtual void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, shared_ptr<SpriteSheetComponent> &sprite_sheet_component, const string &path, shared_ptr<SheetInfo> sheet_info = nullptr) = 0;
};

