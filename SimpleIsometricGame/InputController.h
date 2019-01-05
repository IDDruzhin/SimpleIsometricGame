#pragma once
#include "GameModel.h"
//#include "GameView.h"

//class GameModel;
class GameView;

class InputController
{
protected:
	shared_ptr<GameModel> game_model_;
	shared_ptr<GameView> game_view_;
public:
	InputController();
	~InputController();
	void SetGameModel(shared_ptr<GameModel> game_model);
	void SetGameView(shared_ptr<GameView> game_view);
	virtual void Update();
};

