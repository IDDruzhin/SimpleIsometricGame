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
	GameSystem::GetInstance()->Update();
}

void GameModel::Render(shared_ptr<Screen> screen)
{
	screen->Clear();
	grid_->Draw(screen);
	screen->Present();
}

float2 GameModel::GetGridCeneter()
{
	return grid_->GetGridCenter();
}

void GameModel::ToggleGridBlockMask(float2 screen_pos)
{
	float2 grid_pos = grid_->ScreenToGrid(screen_pos);
	cout << "Grid pos:" << grid_pos.x << " " << grid_pos.y << endl;
	if (grid_->IsInsideGrid(grid_pos))
	{
		int2 cell_pos = int2(grid_pos.x, grid_pos.y);
		bool block = grid_->CheckBlockMask(cell_pos);
		grid_->SetBlockMask(cell_pos, !block);
	}
}