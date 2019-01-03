#include "stdafx.h"
#include "SFMLGraphicsComponent.h"


SFMLGraphicsComponent::SFMLGraphicsComponent()
{
}


SFMLGraphicsComponent::~SFMLGraphicsComponent()
{
}

void SFMLGraphicsComponent::SetTexture(const sf::Texture &texture)
{
	sprite_.setTexture(texture);
}

void SFMLGraphicsComponent::SetLocation(float2 location)
{
	sprite_.setPosition(location.x, location.y);
}
