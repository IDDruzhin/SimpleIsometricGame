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
