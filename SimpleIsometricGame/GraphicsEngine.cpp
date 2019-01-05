#include "stdafx.h"
#include "GraphicsEngine.h"


GraphicsEngine::GraphicsEngine()
{
}

/*
GraphicsEngine::GraphicsEngine(uint2 size, string name)
{
}
*/

GraphicsEngine::~GraphicsEngine()
{
}

shared_ptr<GraphicsEngine> GraphicsEngine::instance_ = nullptr;