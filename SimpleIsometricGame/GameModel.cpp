#include "stdafx.h"
#include "GameModel.h"


GameModel::GameModel():game_over_(false),random_map_seed_(0)
{
}


GameModel::GameModel(shared_ptr<GraphicsEngine> graphics_engine): game_over_(false)
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

void GameModel::Restart()
{
	GameSystem::Reset();
	game_over_ = false;
	Init(graphics_engine_);
}

void GameModel::Update()
{
	GameSystem::GetInstance()->Update();
}

void GameModel::Render(shared_ptr<Screen> screen)
{
	/*
	screen->Clear();
	grid_->Draw(screen);
	screen->Present();
	*/
	GameSystem::GetInstance()->Render(screen);
}

float2 GameModel::GetGridCenter()
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
		//float2 player_cell_location = player_->GetGridCellLocation();
		if (!(grid_->CheckEmployMask(cell_pos)) && (player_->GetGridCellLocation() != cell_pos) && (player_->GetDestination() != cell_pos))
		{
			bool block = grid_->CheckBlockMask(cell_pos);
			grid_->SetBlockMask(cell_pos, !block);
			player_->UpdateMovement();
		}
	}
}

void GameModel::MovePlayerTo(float2 screen_pos)
{
	float2 grid_pos = grid_->ScreenToGrid(screen_pos);
	//cout << "Grid pos:" << grid_pos.x << " " << grid_pos.y << endl;
	if (grid_->IsInsideGrid(grid_pos))
	{
		int2 cell_pos = int2(grid_pos.x, grid_pos.y);
		if (!grid_->CheckBlockMask(cell_pos))
		{
			player_->MoveTo(cell_pos);
		}	
	}
}

void GameModel::GenerateRandomMap(int seed)
{
	random_map_seed_ = seed;
	Restart();
}

void GameModel::GenerateRandomMap()
{
	auto now = chrono::system_clock::now();
	random_map_seed_ = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();
	Restart();
}

bool GameModel::IsGameOver()
{
	return game_over_;
}
