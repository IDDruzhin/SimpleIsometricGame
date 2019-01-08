#include "stdafx.h"
#include "SFMLGraphicsEngine.h"


SFMLGraphicsEngine::SFMLGraphicsEngine()
{
}

SFMLGraphicsEngine::~SFMLGraphicsEngine()
{
}

shared_ptr<GraphicsEngine> SFMLGraphicsEngine::GetInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = shared_ptr<SFMLGraphicsEngine>(new SFMLGraphicsEngine());
	}
	return instance_;
}

void SFMLGraphicsEngine::RegisterGraphicsResource(shared_ptr<GraphicsComponent>& graphics_component, shared_ptr<SpriteSheetComponent>& sprite_sheet_component, const string & path, shared_ptr<SheetInfo> sheet_info)
{
	GraphicsData graphics_data;
	auto res = graphics_data_map_.find(path);
	if (res == graphics_data_map_.end())
	{
		graphics_data.texture.loadFromFile(path);
		graphics_data.sheet_info = sheet_info;
		res = graphics_data_map_.emplace(path, graphics_data).first;
	}
	shared_ptr<SFMLGraphicsComponent> graphics_component_tmp = make_shared<SFMLGraphicsComponent>();
	graphics_component_tmp->SetTexture(res->second.texture);
	
	shared_ptr<SpriteSheetComponent> sprite_sheet_component_tmp;
	if (sheet_info)
	{
		sprite_sheet_component_tmp = make_shared<SpriteSheetComponent>();
		sprite_sheet_component_tmp->SetSheetInfo(res->second.sheet_info);
		graphics_component_tmp->SetSpriteRect(sprite_sheet_component_tmp->GetCurRect());
	}
	graphics_component = move(graphics_component_tmp);
	sprite_sheet_component = move(sprite_sheet_component_tmp);
}
