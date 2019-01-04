#include "stdafx.h"
#include "SFMLGraphicsEngine.h"


SFMLGraphicsEngine::SFMLGraphicsEngine()
{
}


SFMLGraphicsEngine::~SFMLGraphicsEngine()
{
}


shared_ptr<GraphicsComponent> SFMLGraphicsEngine::RegisterGraphicsResource(const string &path)
{
	GraphicsData graphics_data;
	shared_ptr<SFMLGraphicsComponent> graphics_component;
	auto res = graphics_data_map_.find(path);
	if (res == graphics_data_map_.end())
	{
		graphics_data.texture.loadFromFile(path);
		res = graphics_data_map_.emplace(path, graphics_data).first;
	}
	graphics_component->SetTexture(res->second.texture);
	graphics_component->SetSheetInfo(res->second.sheet_info);
	return graphics_component;
}

shared_ptr<GraphicsComponent> SFMLGraphicsEngine::RegisterGraphicsResource(const string & path, SheetInfo & sheet_info)
{
	GraphicsData graphics_data;
	shared_ptr<SFMLGraphicsComponent> graphics_component;
	auto res = graphics_data_map_.find(path);
	if (res == graphics_data_map_.end())
	{
		graphics_data.texture.loadFromFile(path);
		graphics_data.sheet_info = make_shared<SheetInfo>(move(sheet_info));
		res = graphics_data_map_.emplace(path, graphics_data).first;
	}
	graphics_component->SetTexture(res->second.texture);
	graphics_component->SetSheetInfo(res->second.sheet_info);
	return graphics_component;
}
