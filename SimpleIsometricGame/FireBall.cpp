#include "stdafx.h"
#include "FireBall.h"


void FireBall::SetState(float2 dir)
{
	if (dir.x > 0)
	{
		//sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::RIGHT]);
		UpdateSprite(FIREBALL_STATES[ACTOR_DIRECTION::RIGHT]);
	}
	else if (dir.x < 0)
	{
		//sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::LEFT]);
		UpdateSprite(FIREBALL_STATES[ACTOR_DIRECTION::LEFT]);
	}
	else if (dir.y < 0)
	{
		//sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::TOP]);
		UpdateSprite(FIREBALL_STATES[ACTOR_DIRECTION::TOP]);
	}
	else if (grid_location_.y > 0)
	{
		//sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::DOWN]);
		UpdateSprite(FIREBALL_STATES[ACTOR_DIRECTION::DOWN]);
	}
}

shared_ptr<Projectile> FireBall::Clone()
{
	shared_ptr<FireBall> copy = make_shared<FireBall>();
	copy->graphics_component_ = graphics_component_->Clone();
	copy->sprite_sheet_component_ = sprite_sheet_component_->Clone();
	return copy;
}

FireBall::FireBall()
{
}

FireBall::FireBall(shared_ptr<GraphicsEngine> graphics_engine)
{
	string texture_path = "Content/fireball_0.png";
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 8;
	sheet_info->window_size.x = 64;
	sheet_info->window_size.y = 64;
	int sets_count = 8;
	for (int i = 0; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i * 8, 8));
	}
	RegisterGraphics(graphics_engine, texture_path, sheet_info);
	sprite_sheet_component_->SetPlayRate(0.1f);
	//CenterOrigin();
	graphics_component_->SetOrigin(int2(32, 38));
	//SetScale(1.2f);
	/*
	string texture_path = "Content/RedTile.png";
	RegisterGraphics(graphics_engine, texture_path);
	CenterOrigin();
	SetScale(0.5f);
	*/
}

FireBall::FireBall(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir, float speed):Projectile(graphics_engine, grid, grid_location, dir, speed)
{
	/*
	string texture_path = "Content/fireball_0.png";
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 8;
	sheet_info->window_size.x = 64;
	sheet_info->window_size.y = 64;
	int sets_count = 8;
	for (int i = 0; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i * 8, 8));
	}
	RegisterGraphics(graphics_engine, texture_path, sheet_info);
	CenterOrigin();
	SetScale(0.5f);
	*/
	string texture_path = "Content/RedTile.png";
	RegisterGraphics(graphics_engine, texture_path);
	CenterOrigin();
	SetScale(0.5f);
}

FireBall::~FireBall()
{
}

const int FireBall::FIREBALL_STATES[] = { 5,7,1,3 };
