#pragma once
#include "Grid.h"
#include "Unit.h"
#include "GameSystem.h"

class GameModel
{
protected:
	shared_ptr<GraphicsEngine> graphics_engine_;
	shared_ptr<Grid> grid_;
	shared_ptr<Unit> player_;
	int2 finish_point_;
	bool game_over_;
	int random_map_seed_;
public:
	GameModel();
	GameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~GameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Restart();
	virtual void Update();
	virtual void Render(shared_ptr<Screen> screen);
	float2 GetGridCeneter();
	virtual void ToggleGridBlockMask(float2 screen_pos);
	virtual void MovePlayerTo(float2 screen_pos);
	virtual void GenerateRandomMap(int seed);
	virtual void GenerateRandomMap();
	virtual bool IsGameOver();
};

