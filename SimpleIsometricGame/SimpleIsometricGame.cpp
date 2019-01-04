// SimpleIsometricGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SFMLGraphicsEngine.h"
#include "SimpleGameModel.h"
#include "SFMLGraphicsEngine.h"


int main()
{
	shared_ptr<GraphicsEngine> game_view = make_shared<SFMLGraphicsEngine>();
	shared_ptr<GameModel> game_model = make_shared<SimpleGameModel>(game_view);
	shared_ptr<InputController> game_controller = game_view->GetCompatibleController();
	game_controller->SetGameModel(game_model);
	while (game_view->IsRunning())
	{
		game_controller->Update();
		game_model->Update();
		game_model->Render();
	}
    return 0;
}

