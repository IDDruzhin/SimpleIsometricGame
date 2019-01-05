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

void SFMLGraphicsComponent::SetColor(uchar r, uchar g, uchar b, uchar a)
{
	sprite_.setColor(sf::Color(r, g, b, a));
}

void SFMLGraphicsComponent::SetLocation(float2 location)
{
	sprite_.setPosition(location.x, location.y);
}

void SFMLGraphicsComponent::SetOrigin(int2 origin)
{
	sprite_.setOrigin(origin.x, origin.y);
}

void SFMLGraphicsComponent::SetSpriteRect(Rect r)
{
	sprite_.setTextureRect(sf::IntRect(r.left_top.x, r.left_top.y, r.size.x, r.size.y));
}

sf::Sprite SFMLGraphicsComponent::GetSprite()
{
	return sprite_;
}
