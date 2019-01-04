#pragma once
#include "GameModel.h"
#include "SimpleGrid.h"
class SimpleGameModel :
	public GameModel
{
public:
	SimpleGameModel();
	SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~SimpleGameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Update();
};

