#include "stdafx.h"
#include "SimpleGameModel.h"


SimpleGameModel::SimpleGameModel()
{
}

SimpleGameModel::SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine)
{
	Init(graphics_engine);
}


SimpleGameModel::~SimpleGameModel()
{
}

void SimpleGameModel::Init(shared_ptr<GraphicsEngine> graphics_engine)
{
	graphics_engine_ = graphics_engine;
	grid_ = make_shared<SimpleGrid>(graphics_engine_);
	GameSystem::GetInstance()->AddGrid(grid_);
	player_ = make_shared<PlayerCharacter>(graphics_engine_, grid_, int2(0, 5));
	GameSystem::GetInstance()->AddGridActor(player_);
	shared_ptr<GridActor> actor;

	actor = make_shared<Guardian>(graphics_engine_, grid_, int2(0, 0), int2(1, 0));
	GameSystem::GetInstance()->AddGridActor(actor);
	
	//player_->MoveTo(int2(8, 5));
}

void SimpleGameModel::Update()
{
	grid_->ClearEmployMask();
	GameModel::Update();
	/*
	grid_->ClearEmployMask();
	actor_->Update();
	player_->Update();
	*/
}

void SimpleGameModel::Render(shared_ptr<Screen> screen)
{
	/*
	screen->Clear();
	grid_->Draw(screen);
	actor_->Draw(screen);
	player_->Draw(screen);
	//cout << "Actor: " << actor_->GetScreenLocation().x << " " << actor_->GetScreenLocation().y << endl;
	screen->Present();
	*/
	GameSystem::GetInstance()->Render(screen);
}
