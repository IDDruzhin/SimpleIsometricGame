#pragma once
#include "GameModel.h"
#include "GameView.h"

//class GameModel;

class InputController
{
protected:
	shared_ptr<GameModel> game_model_;
public:
	InputController();
	~InputController();
	void SetGameModel(shared_ptr<GameModel> game_model);
	virtual void Update();
};

