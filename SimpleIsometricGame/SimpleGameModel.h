#pragma once
#include "GameModel.h"
#include "SimpleGrid.h"
#include "Guardian.h"
#include "PlayerCharacter.h"
#include "SimpleCannon.h"
class SimpleGameModel :
	public GameModel
{
public:
	SimpleGameModel();
	SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~SimpleGameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Update();
	virtual void Render(shared_ptr<Screen> screen);
};

