// SimpleIsometricGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GraphicsEngine.h"
#include "SFMLGraphicsEngine.h"
#include "GameModel.h"
#include "InputController.h"


int main()
{
	shared_ptr<GraphicsEngine> game_view = make_shared<SFMLGraphicsEngine>();
	shared_ptr<GameModel> game_model = make_shared<GameModel>();
	shared_ptr<InputController> game_controller = game_view->GetCompatibleController();
	game_controller->SetGameModel(game_model);
    return 0;
}

