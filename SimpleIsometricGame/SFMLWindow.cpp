#include "stdafx.h"
#include "SFMLWindow.h"


SFMLWindow::SFMLWindow()
{
	window_ = make_shared<sf::RenderWindow>(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "SimpleIsometricGame");
	
	sf::View v;
	v.setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	//v.setCenter(0, DEFAULT_HEIGHT*0.7f);
	v.zoom(2.0f);
	window_->setView(v);
	
	
}

SFMLWindow::SFMLWindow(uint2 size, string name)
{
	window_ = make_shared<sf::RenderWindow>(sf::VideoMode(size.x, size.y), name);
	//sf::View v = window_->getView();
	//float ratio = (float)size.x / DEFAULT_WIDTH;
	//float ratio = (float)DEFAULT_WIDTH / size.x;
	//v.zoom(ratio);
	sf::View v;
	float ratio = (float)DEFAULT_WIDTH / size.x;
	float height = ratio * size.y;
	v.setSize(DEFAULT_WIDTH, height);
	//v.setCenter(0, height / 2);
	v.zoom(2.0f);
	window_->setView(v);
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

void SFMLWindow::Zoom(float factor)
{
	sf::View v = window_->getView();
	v.zoom(factor);
	window_->setView(v);
}

void SFMLWindow::SetCenter(float2 center)
{
	sf::View v = window_->getView();
	v.setCenter(center.x, center.y);
	window_->setView(v);
}

float2 SFMLWindow::GetCenter()
{
	sf::View v = window_->getView();
	//sf::Vector2f coord = window_->mapPixelToCoords(v.getCenter());
	return float2(v.getCenter().x, v.getCenter().y);
}

float2 SFMLWindow::GetSize()
{
	sf::View v = window_->getView();
	return float2(v.getSize().x, v.getSize().y);
}

float2 SFMLWindow::PixelToCoord(int2 pixel_pos)
{
	auto world_pos = window_->mapPixelToCoords(sf::Vector2i(pixel_pos.x, pixel_pos.y));
	return float2(world_pos.x, world_pos.y);
}
