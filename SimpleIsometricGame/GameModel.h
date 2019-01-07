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
public:
	GameModel();
	GameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~GameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Update();
	virtual void Render(shared_ptr<Screen> screen);
	float2 GetGridCeneter();
	virtual void ToggleGridBlockMask(float2 screen_pos);
	virtual void MovePlayerTo(float2 screen_pos);
};

