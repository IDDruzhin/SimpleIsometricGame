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
public:
	SFMLGraphicsEngine();
	~SFMLGraphicsEngine();
	//shared_ptr<GraphicsComponent> RegisterGraphicsResource(const string &path);
	//shared_ptr<GraphicsComponent> RegisterGraphicsResource(const string &path, SheetInfo &sheet_info);
	void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, const string &path);
	void RegisterGraphicsResource(shared_ptr<GraphicsComponent> &graphics_component, shared_ptr<SpriteSheetComponent> &sprite_sheet_component, const string &path, SheetInfo &sheet_info);
};

