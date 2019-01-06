#include "stdafx.h"
#include "SFMLInputController.h"


SFMLInputController::SFMLInputController(shared_ptr<sf::RenderWindow> window) : window_(window)
{
	//game_view_ = game_view;
	zoom_ratio_ = 0.1f;
}

SFMLInputController::~SFMLInputController()
{
}

void SFMLInputController::Update()
{
	sf::Event e;
	while (window_->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			window_->close();
		else if (e.type == sf::Event::MouseWheelScrolled)
		{
			//cout << e.mouseWheelScroll.delta << endl;
			game_view_->Zoom(1.0f + zoom_ratio_ * e.mouseWheelScroll.delta);
		}
		else if (e.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2i screen(e.mouseButton.x, e.mouseButton.y);
			sf::Vector2f world_pos = window_->mapPixelToCoords(screen);
			//float2 grid_pos = game_model_->
			switch (e.key.code)
			{
			case sf::Mouse::Right:
				game_model_->ToggleGridBlockMask(float2(world_pos.x,world_pos.y));
				cout << "Screen:" << endl;
				cout << e.mouseButton.x << endl;
				cout << e.mouseButton.y << endl;
				cout << "World:" << endl;
				cout << world_pos.x << endl;
				cout << world_pos.y << endl;
			default:
				break;
			}
		}
	}
}
