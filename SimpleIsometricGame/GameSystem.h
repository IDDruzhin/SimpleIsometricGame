#pragma once
#include "Timer.h"
class GameSystem
{
private:
	static shared_ptr<GameSystem> instance_;
	Timer timer_;
	float elapsed_seconds_;
	GameSystem();
public:
	static shared_ptr<GameSystem> GetInstance();
	~GameSystem();
	float GetElapsedSeconds();
	void Update();
};

