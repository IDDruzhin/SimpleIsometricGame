#pragma once
#include "InputController.h"
#include "SFMLGameView.h"
//#include <SFML/Graphics.hpp>
class SFMLInputController :
	public InputController
{
private:
	shared_ptr<sf::RenderWindow> window_;
public:
	//SFMLInputController(shared_ptr<sf::RenderWindow> window, shared_ptr<GameView> game_view);
	SFMLInputController(shared_ptr<sf::RenderWindow> window);
	~SFMLInputController();
	void Update();
};

