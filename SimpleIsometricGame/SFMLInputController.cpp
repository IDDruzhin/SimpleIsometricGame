#include "stdafx.h"
#include "SFMLInputController.h"


SFMLInputController::SFMLInputController(shared_ptr<sf::RenderWindow> window) : window_(window)
{
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
		if (e.type == sf::Event::MouseButtonReleased)
		{
			switch (e.key.code)
			{
			case sf::Mouse::Right:
				cout << "RightMouse" << endl;
			default:
				break;
			}
		}
	}
}
