#include "stdafx.h"
#include "Projectile.h"

void Projectile::SetState(float2 dir)
{
}

Projectile::Projectile()
{
	attack_component = make_shared<AttackComponent>();
}

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
	shared_ptr<Projectile> copy = make_shared<Projectile>();
	copy->graphics_component_ = graphics_component_;
	copy->sprite_sheet_component_ = sprite_sheet_component_;
	return copy;
}

void Projectile::SetSpeed(float speed)
{
	movement_component_->SetSpeed(speed);
}

void Projectile::SetDirection(float2 dir)
{
	movement_component_->SetDirection(dir);
	SetState(dir);
}
