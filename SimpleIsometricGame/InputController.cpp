#include "stdafx.h"
#include "InputController.h"


InputController::InputController()
{
}


InputController::~InputController()
{
}

void InputController::SetGameModel(shared_ptr<GameModel> game_model)
{
	game_model_ = game_model;
}

void InputController::SetGameView(shared_ptr<GameView> game_view)
{
	game_view_ = game_view;
}

void InputController::Update()
{
}

void InputController::SetZoomRatio(float ratio)
{
	zoom_ratio_ = ratio;
}
