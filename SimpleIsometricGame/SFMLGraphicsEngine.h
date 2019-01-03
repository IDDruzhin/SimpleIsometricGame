#pragma once
#include "GraphicsEngine.h"
#include "SFMLGraphicsComponent.h"
#include <SFML/Graphics.hpp>

class SFMLGraphicsEngine :
	public GraphicsEngine
{
private:
	unordered_map<string, sf::Texture> textures_;
public:
	SFMLGraphicsEngine();
	~SFMLGraphicsEngine();
	shared_ptr<GraphicsComponent> RegisterGraphicsResource(string path);
};

