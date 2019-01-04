#pragma once
#include "InputController.h"
#include <SFML/Graphics.hpp>
class SFMLInputController :
	public InputController
{
private:
	shared_ptr<sf::RenderWindow> window_;
public:
	SFMLInputController(shared_ptr<sf::RenderWindow> window);
	~SFMLInputController();
};

