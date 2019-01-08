#pragma once
#include "GraphicsEngine.h"
#include "SFMLGraphicsComponent.h"
#include <SFML/Graphics.hpp>

struct GraphicsData
{
	sf::Texture texture;
	shared_ptr<SheetInfo> sheet_info;
	GraphicsData() {};
};

class SFMLGraphicsEngine :
	public GraphicsEngine
{
private:
	unordered_map<string, GraphicsData> graphics_data_map_;
	SFMLGraphicsEngine();
public:
	~SFMLGraphicsEngine();
	static shared_ptr<GraphicsEngine> GetInstance();
	void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, shared_ptr<SpriteSheetComponent> &sprite_sheet_component, const string &path, shared_ptr<SheetInfo> sheet_info = nullptr);
};

