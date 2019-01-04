#include "stdafx.h"
#include "SFMLGraphicsEngine.h"


SFMLGraphicsEngine::SFMLGraphicsEngine()
{
}


SFMLGraphicsEngine::~SFMLGraphicsEngine()
{
}

void SFMLGraphicsEngine::RegisterGraphicsResource(shared_ptr<GraphicsComponent>& graphics_component, const string & path)
{
	GraphicsData graphics_data;
	shared_ptr<SFMLGraphicsComponent> graphics_component_tmp = make_shared<SFMLGraphicsComponent>();
	auto res = graphics_data_map_.find(path);
	if (res == graphics_data_map_.end())
	{
		graphics_data.texture.loadFromFile(path);
		res = graphics_data_map_.emplace(path, graphics_data).first;
	}
	graphics_component_tmp->SetTexture(res->second.texture);
	graphics_component = move(graphics_component_tmp);
}

void SFMLGraphicsEngine::RegisterGraphicsResource(shared_ptr<GraphicsComponent>& graphics_component, shared_ptr<SpriteSheetComponent>& sprite_sheet_component, const string & path, SheetInfo & sheet_info)
{
	GraphicsData graphics_data;
	shared_ptr<SFMLGraphicsComponent> graphics_component_tmp = make_shared<SFMLGraphicsComponent>();
	shared_ptr<SpriteSheetComponent> sprite_sheet_component_tmp = make_shared<SpriteSheetComponent>();
	auto res = graphics_data_map_.find(path);
	if (res == graphics_data_map_.end())
	{
		graphics_data.texture.loadFromFile(path);
		graphics_data.sheet_info = make_shared<SheetInfo>(move(sheet_info));
		res = graphics_data_map_.emplace(path, graphics_data).first;
	}
	graphics_component_tmp->SetTexture(res->second.texture);
	sprite_sheet_component_tmp->SetSheetInfo(res->second.sheet_info);
	graphics_component = move(graphics_component_tmp);
	sprite_sheet_component = move(sprite_sheet_component_tmp);
}