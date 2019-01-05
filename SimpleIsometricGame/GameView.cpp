#include "stdafx.h"
#include "GameView.h"


GameView::GameView()
{
}


GameView::~GameView()
{
}

void GameView::SetModel(shared_ptr<GameModel> model)
{
	model_ = model;
}

bool GameView::IsRunning()
{
	return screen_->IsRunning();
}
