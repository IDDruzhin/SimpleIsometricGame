#pragma once
#include "GraphicsComponent.h"
#include "SpriteSheetComponent.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	virtual void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, const string &path) = 0;
	virtual void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, shared_ptr<SpriteSheetComponent> &sprite_sheet_component, const string &path, SheetInfo &sheet_info) = 0;
};

