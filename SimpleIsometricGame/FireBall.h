#pragma once
#include "Projectile.h"
class FireBall :
	public Projectile
{
public:
	FireBall(shared_ptr<GraphicsEngine> graphics_engine);
	FireBall(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir = float2(1.0f, 0.0f), float speed = 3.0f);
	~FireBall();
};

