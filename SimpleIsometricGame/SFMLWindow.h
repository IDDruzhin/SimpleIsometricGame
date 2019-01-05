#pragma once
#include "Screen.h"
#include "SFMLGraphicsComponent.h"
class SFMLWindow :
	public Screen
{
private:
	shared_ptr<sf::RenderWindow> window_;
public:
	SFMLWindow();
	SFMLWindow(uint2 size, string name);
	~SFMLWindow();
	shared_ptr<sf::RenderWindow> GetWindow();
	void Draw(shared_ptr<GraphicsComponent> graphics_component);
	void Clear();
	void Present();
	bool IsRunning();
};

