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

void InputController::Update()
{
}
