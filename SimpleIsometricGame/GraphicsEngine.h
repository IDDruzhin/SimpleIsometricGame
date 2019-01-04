#pragma once
#include "GraphicsComponent.h"
#include "SpriteSheetComponent.h"
#include "InputController.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	GraphicsEngine(uint2 size, string name);
	~GraphicsEngine();
	virtual void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, const string &path) = 0;
	virtual void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, shared_ptr<SpriteSheetComponent> &sprite_sheet_component, const string &path, SheetInfo &sheet_info) = 0;
	virtual void Draw(shared_ptr<GraphicsComponent> graphics_component) = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual shared_ptr<InputController> GetCompatibleController() = 0;
	virtual bool IsRunning() = 0;
};

