#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir, float speed):GridActor(grid, grid_location)
{
	movement_component_->SetDirection(dir);
	movement_component_->SetSpeed(speed);
	attack_component = make_shared<AttackComponent>();
}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	if (!grid_->IsInsideGrid(grid_location_))
	{
		Destroy();
	}
	else
	{
		attack_component->Attack(grid_, GetGridCellLocation());
	}
	movement_component_->Move(grid_, grid_location_);
	GridActor::Update();
}

shared_ptr<Projectile> Projectile::Copy()
{
	return shared_ptr<Projectile>();
}
