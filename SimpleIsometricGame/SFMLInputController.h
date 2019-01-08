#pragma once
#include "InputController.h"
#include "SFMLGameView.h"

class SFMLInputController :
	public InputController
{
private:
	shared_ptr<sf::RenderWindow> window_;
public:
	SFMLInputController(shared_ptr<sf::RenderWindow> window);
	~SFMLInputController();
	void Update();
};

