#include "stdafx.h"
#include "SFMLGraphicsEngine.h"


SFMLGraphicsEngine::SFMLGraphicsEngine()
{
}


SFMLGraphicsEngine::~SFMLGraphicsEngine()
{
}

shared_ptr<GraphicsComponent> SFMLGraphicsEngine::RegisterGraphicsResource(string path)
{
	shared_ptr<SFMLGraphicsComponent> graphicsComponent;
	auto res = textures_.find(path);
	if (res == textures_.end())
	{
		sf::Texture tex;
		tex.loadFromFile(path);
		textures_.emplace(path, tex);
		res = textures_.find(path);
	}
	graphicsComponent->SetTexture(res->second);
	return graphicsComponent;
}
