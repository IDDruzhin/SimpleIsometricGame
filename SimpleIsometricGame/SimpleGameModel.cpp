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
}

void SimpleGameModel::Update()
{

}
