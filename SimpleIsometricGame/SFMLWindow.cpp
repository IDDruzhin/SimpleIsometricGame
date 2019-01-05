#include "stdafx.h"
#include "SFMLWindow.h"


SFMLWindow::SFMLWindow()
{
	window_ = make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768), "SimpleIsometricGame");
}

SFMLWindow::SFMLWindow(uint2 size, string name)
{
	window_ = make_shared<sf::RenderWindow>(sf::VideoMode(size.x, size.y), name);
}


SFMLWindow::~SFMLWindow()
{
}

shared_ptr<sf::RenderWindow> SFMLWindow::GetWindow()
{
	return window_;
}

void SFMLWindow::Draw(shared_ptr<GraphicsComponent> graphics_component)
{
	shared_ptr<SFMLGraphicsComponent> cur_graphics_component = dynamic_pointer_cast<SFMLGraphicsComponent>(graphics_component);
	if (cur_graphics_component)
	{
		//sf::Transform t;
		//t.scale(100.0f / 1024, 100.0f / 1024);
		window_->draw(cur_graphics_component->GetSprite());
	}
}

void SFMLWindow::Clear()
{
	window_->clear();
}

void SFMLWindow::Present()
{
	window_->display();
}

bool SFMLWindow::IsRunning()
{
	return window_->isOpen();
}
