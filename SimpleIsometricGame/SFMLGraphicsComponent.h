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
	void SetColor(uchar r = 255, uchar g = 255, uchar b = 255, uchar a = 255);
	void SetLocation(float2 location);
	void SetScale(float scale);
	void SetScale(float2 scale);
	void Scale(float2 scale);
	void SetOrigin(int2 origin);
	void CenterOrigin();
	void SetSpriteRect(Rect r);
	Rect GetSpriteRect();
	sf::Sprite GetSprite();
	shared_ptr<GraphicsComponent> Clone();
};

