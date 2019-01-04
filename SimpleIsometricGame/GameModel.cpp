#include "stdafx.h"
#include "GameModel.h"


GameModel::GameModel()
{
}


GameModel::GameModel(shared_ptr<GraphicsEngine> graphics_engine)
{
	Init(graphics_engine);
}

GameModel::~GameModel()
{
}

void GameModel::Init(shared_ptr<GraphicsEngine> graphics_engine)
{
	graphics_engine_ = graphics_engine;
}

void GameModel::Update()
{
}

void GameModel::Render()
{
	grid_->Draw(graphics_engine_);
}
