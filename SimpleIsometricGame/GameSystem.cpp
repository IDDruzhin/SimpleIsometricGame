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

GameSystem::~GameSystem()
{
}

float GameSystem::GetElapsedSeconds()
{
	return elapsed_seconds_;
}

shared_ptr<GameSystem> GameSystem::instance_ = nullptr;
