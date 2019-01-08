#pragma once
#include "GameModel.h"
#include "SimpleGrid.h"
#include "Guardian.h"
#include "PlayerCharacter.h"
class SimpleGameModel :
	public GameModel
{
private:
	//shared_ptr<GridActor> actor_;
	//shared_ptr<Unit> player_;
public:
	SimpleGameModel();
	SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine);
	~SimpleGameModel();
	virtual void Init(shared_ptr<GraphicsEngine> graphics_engine);
	virtual void Update();
	virtual void Render(shared_ptr<Screen> screen);
	//virtual void MovePlayerTo(shared_ptr<Screen> screen);
};

