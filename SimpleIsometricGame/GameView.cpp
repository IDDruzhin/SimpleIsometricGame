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
	screen_->SetCenter(model_->GetGridCenter());
}

bool GameView::IsRunning()
{
	return screen_->IsRunning();
}

void GameView::Zoom(float factor)
{
	screen_->Zoom(factor);
}
