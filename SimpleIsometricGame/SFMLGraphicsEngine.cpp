#include "stdafx.h"
#include "SFMLGraphicsEngine.h"


SFMLGraphicsEngine::SFMLGraphicsEngine()
{
	//window_ = make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768), "SimpleIsometricGame");
	//window_ = make_shared<sf::RenderWindow>(sf::VideoMode(100, 100), "SimpleIsometricGame");
}

/*
SFMLGraphicsEngine::SFMLGraphicsEngine(uint2 size, string name)
{
	window_ = make_shared<sf::RenderWindow>(sf::VideoMode(size.x, size.y), name);
}
*/

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
	else
	{
		if (res->second.sheet_info == nullptr)
		{
			res->second.sheet_info = make_shared<SheetInfo>(move(sheet_info));
		}
	}
	graphics_component_tmp->SetTexture(res->second.texture);
	sprite_sheet_component_tmp->SetSheetInfo(res->second.sheet_info);
	graphics_component_tmp->SetSpriteRect(sprite_sheet_component_tmp->GetCurRect());
	graphics_component = move(graphics_component_tmp);
	sprite_sheet_component = move(sprite_sheet_component_tmp);
}

/*
void SFMLGraphicsEngine::Draw(shared_ptr<GraphicsComponent> graphics_component)
{
	shared_ptr<SFMLGraphicsComponent> cur_graphics_component = dynamic_pointer_cast<SFMLGraphicsComponent>(graphics_component);
	if (cur_graphics_component)
	{
		//sf::Transform t;
		//t.scale(100.0f / 1024, 100.0f / 1024);
		window_->draw(cur_graphics_component->GetSprite());
	}
}

void SFMLGraphicsEngine::Clear()
{
	window_->clear();
}

void SFMLGraphicsEngine::Present()
{
	window_->display();
}

shared_ptr<InputController> SFMLGraphicsEngine::GetCompatibleController()
{
	shared_ptr<SFMLInputController> compatible_controller = make_shared<SFMLInputController>(window_);
	return compatible_controller;
}

bool SFMLGraphicsEngine::IsRunning()
{
	return window_->isOpen();
}
*/
