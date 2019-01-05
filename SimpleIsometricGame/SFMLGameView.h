#pragma once
#include "GameView.h"
#include "SFMLGraphicsEngine.h"
#include "SFMLWindow.h"

class SFMLInputController;

class SFMLGameView :
	public GameView
{
public:
	SFMLGameView();
	~SFMLGameView();
	shared_ptr<GraphicsEngine> GetGraphicsEngine();
	void Render();
	shared_ptr<InputController> GetCompatibleController();
};

