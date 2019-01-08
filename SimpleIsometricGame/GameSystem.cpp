#include "stdafx.h"
#include "GameSystem.h"


GameSystem::GameSystem()
{
}


shared_ptr<GameSystem> GameSystem::GetInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = shared_ptr<GameSystem>(new GameSystem());
	}
	return instance_;
}

void GameSystem::Reset()
{
	instance_.reset();
}

GameSystem::~GameSystem()
{
}

float GameSystem::GetElapsedSeconds()
{
	return elapsed_seconds_;
}

void GameSystem::Update()
{
	elapsed_seconds_ = timer_.GetElapsedSeconds();
	timer_.Restart();
	/*
	for (auto it = grid_actors_.begin(); it != grid_actors_.end(); )
	{
		if ((*it)->IsActive())
		{
			(*it)->Update();
			it++;
		}
		else
		{
			int dist = distance(grid_actors_.begin(), it);
			grid_actors_.erase(it);
			it = grid_actors_.begin() + dist;
		}
	}
	*/
	for (auto it = grid_actors_.begin(); it != grid_actors_.end(); )
	{
		if ((*it)->IsActive())
		{
			(*it)->Update();
			it++;
		}
		else
		{
			it = grid_actors_.erase(it);
		}
	}
	for (auto it = screen_elements_.begin(); it != screen_elements_.end(); )
	{
		if ((*it)->IsActive())
		{
			(*it)->Update();
			it++;
		}
		else
		{
			it = screen_elements_.erase(it);
		}
	}
	/*
	for (auto it = screen_elements_.begin(); it != screen_elements_.end(); )
	{
		if ((*it)->IsActive())
		{
			(*it)->Update();
			it++;
		}
		else
		{
			int dist = distance(screen_elements_.begin(), it);
			screen_elements_.erase(it);
			it = screen_elements_.begin() + dist;
		}
	}
	*/
}

void GameSystem::Render(shared_ptr<Screen> screen)
{
	screen->Clear();
	for (auto it = grids_.begin(); it != grids_.end(); it++)
	{
		(*it)->Draw(screen);
	}
	//Depth sort
	grid_actors_.sort([](shared_ptr<GridActor> a, shared_ptr<GridActor> b) {return (a->GetScreenLocation().y < b->GetScreenLocation().y); });
	//sort(grid_actors_.begin(), grid_actors_.end(), [](shared_ptr<GridActor> a, shared_ptr<GridActor> b) {return (a->GetScreenLocation().y < b->GetScreenLocation().y); });
	for (auto it = grid_actors_.begin(); it != grid_actors_.end(); it++)
	{
		(*it)->Draw(screen);
	}
	for (auto it = screen_elements_.begin(); it != screen_elements_.end(); it++)
	{
		//(*it)->SetScreenLocation(screen->)
		float2 center = screen->GetCenter();
		float2 size = screen->GetSize();
		float2 pos;
		float2 scale;
		Rect r;
		r = (*it)->GetSpriteRect();
		pos = screen->PixelToCoord(int2(0,0));
		//pos = float2(-1000, 0);
		//pos.x = center.x - size.x / 2.0f;
		//pos.y = center.y - size.y / 2.0f;
		scale.x = size.x / r.size.x;
		scale.y = size.y / r.size.y;
		
		//(*it)->SetScreenLocation(pos);
		(*it)->SetScale(scale);
		(*it)->SetScreenLocation(center);
		(*it)->Draw(screen);
	}
	screen->Present();
}

void GameSystem::AddGrid(shared_ptr<Grid> grid)
{
	grids_.push_back(grid);
}

void GameSystem::AddGridActor(shared_ptr<GridActor> grid_actor)
{
	grid_actors_.push_back(grid_actor);
}

void GameSystem::AddScreenElement(shared_ptr<DrawableObject> screen_element)
{
	screen_elements_.push_back(screen_element);
}

shared_ptr<GameSystem> GameSystem::instance_ = nullptr;
