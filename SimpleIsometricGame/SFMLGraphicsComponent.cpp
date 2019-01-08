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

void SFMLGraphicsComponent::SetScale(float scale)
{
	sprite_.setScale(scale,scale);
}

void SFMLGraphicsComponent::SetScale(float2 scale)
{
	sprite_.setScale(scale.x, scale.y);
}

void SFMLGraphicsComponent::Scale(float2 scale)
{
	sprite_.scale(sf::Vector2f(scale.x,scale.y));
}

void SFMLGraphicsComponent::SetOrigin(int2 origin)
{
	sprite_.setOrigin(origin.x, origin.y);
}

void SFMLGraphicsComponent::CenterOrigin()
{
	sf::IntRect tmp = sprite_.getTextureRect();
	sprite_.setOrigin(tmp.width/2.0f,tmp.height/2.0f);
}

void SFMLGraphicsComponent::SetSpriteRect(Rect r)
{
	sprite_.setTextureRect(sf::IntRect(r.left_top.x, r.left_top.y, r.size.x, r.size.y));
}

Rect SFMLGraphicsComponent::GetSpriteRect()
{
	sf::IntRect tmp = sprite_.getTextureRect();
	Rect r;
	r.left_top.x = tmp.left;
	r.left_top.y = tmp.top;
	r.size.x = tmp.width;
	r.size.y = tmp.height;
	return r;
}

sf::Sprite SFMLGraphicsComponent::GetSprite()
{
	return sprite_;
}

shared_ptr<GraphicsComponent> SFMLGraphicsComponent::Clone()
{
	shared_ptr<SFMLGraphicsComponent> copy = make_shared<SFMLGraphicsComponent>();
	copy->sprite_ = sprite_;
	//shared_ptr<GraphicsComponent> res = copy;
	return copy;
}
