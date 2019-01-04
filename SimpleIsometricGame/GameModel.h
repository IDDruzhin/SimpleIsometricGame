#pragma once
#include "Grid.h"

class GameModel
{
protected:
	shared_ptr<GraphicsEngine> graphics_engine_;
	shared_ptr<Grid> grid_;
public:
	GameModel();
	GameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~GameModel();
	virtual void Render();
};

