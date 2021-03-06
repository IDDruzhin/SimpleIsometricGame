// SimpleIsometricGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SimpleGameModel.h"
#include "SFMLGameView.h"
#include "SFMLInputController.h"


int main()
{
	shared_ptr<GameView> game_view = make_shared<SFMLGameView>();
	shared_ptr<GameModel> game_model = make_shared<SimpleGameModel>(game_view->GetGraphicsEngine());
	game_view->SetModel(game_model);
	shared_ptr<InputController> game_controller = game_view->GetCompatibleController();
	game_controller->SetGameView(game_view);
	game_controller->SetGameModel(game_model);
	while (game_view->IsRunning())
	{
		game_controller->Update();
		game_model->Update();
		game_view->Render();
	}
    return 0;
}

