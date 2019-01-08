#include "stdafx.h"
#include "SFMLInputController.h"


SFMLInputController::SFMLInputController(shared_ptr<sf::RenderWindow> window) : window_(window)
{
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
			game_view_->Zoom(1.0f + zoom_ratio_ * e.mouseWheelScroll.delta);
		}
		else if (e.type == sf::Event::MouseButtonPressed)
		{
			if (game_model_->IsGameOver())
			{
				continue;
			}
			sf::Vector2i screen(e.mouseButton.x, e.mouseButton.y);
			sf::Vector2f world_pos = window_->mapPixelToCoords(screen);
			switch (e.key.code)
			{
			case sf::Mouse::Right:
				game_model_->ToggleGridBlockMask(float2(world_pos.x,world_pos.y));
				break;
			case sf::Mouse::Left:
				game_model_->MovePlayerTo(float2(world_pos.x, world_pos.y));
			default:
				break;
			}
		}
		else if (e.type == sf::Event::KeyPressed)
		{
			switch (e.key.code)
			{
			case sf::Keyboard::R:
				game_model_->Restart();
				break;
			case sf::Keyboard::G:
				game_model_->GenerateRandomMap();
				break;
			default:
				break;
			}
		}
	}
}
