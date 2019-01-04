#include "stdafx.h"
#include "GameModel.h"


GameModel::GameModel()
{
}


GameModel::GameModel(shared_ptr<GraphicsEngine> graphics_engine)
{
	graphics_engine_ = graphics_engine;
	grid_ = 
}

GameModel::~GameModel()
{
}

void GameModel::Render()
{
	grid_->Draw(graphics_engine_);
}
