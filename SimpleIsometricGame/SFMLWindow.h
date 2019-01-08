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
	virtual void Zoom(float factor);
	virtual void SetCenter(float2 center);
	virtual float2 GetCenter();
	virtual float2 GetSize();
	virtual float2 PixelToCoord(int2 pixel_pos);
	//virtual Rect GetRect();
};

