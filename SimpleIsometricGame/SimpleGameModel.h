#pragma once
#include "GameModel.h"
#include "SimpleGrid.h"
#include "Guardian.h"
class SimpleGameModel :
	public GameModel
{
private:
	shared_ptr<GridActor> actor_;
public:
	SimpleGameModel();
	SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~SimpleGameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Update();
	virtual void Render(shared_ptr<Screen> screen);
};

