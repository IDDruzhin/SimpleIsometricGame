#pragma once
#include "GraphicsComponent.h"
#include <SFML/Graphics.hpp>
class SFMLGraphicsComponent :
	public GraphicsComponent
{
private:
	sf::Sprite sprite_;
public:
	SFMLGraphicsComponent();
	~SFMLGraphicsComponent();
	void SetTexture(const sf::Texture &texture);
};

