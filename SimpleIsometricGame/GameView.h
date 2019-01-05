#pragma once
#include "GraphicsEngine.h"
#include "Screen.h"
//#include "InputController.h"
#include "GameModel.h"

class InputController;

class GameView
{
protected:
	shared_ptr<Screen> screen_;
	shared_ptr<GameModel> model_;
public:
	GameView();
	~GameView();
	virtual shared_ptr<GraphicsEngine> GetGraphicsEngine() = 0;
	virtual void Render() = 0;
	virtual shared_ptr<InputController> GetCompatibleController() = 0;
	void SetModel(shared_ptr<GameModel> model);
	bool IsRunning();
};

