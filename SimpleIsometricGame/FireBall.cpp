#include "stdafx.h"
#include "FireBall.h"


void FireBall::SetState(float2 dir)
{
	if (dir.x > 0)
	{
		sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::RIGHT]);
	}
	else if (dir.x < 0)
	{
		sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::LEFT]);
	}
	else if (dir.y < 0)
	{
		sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::TOP]);
	}
	else if (grid_location_.y > 0)
	{
		sprite_sheet_component_->SetState(FIREBALL_STATES[ACTOR_DIRECTION::DOWN]);
	}
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
	CenterOrigin();
	SetScale(0.5f);
}

FireBall::FireBall(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, float2 dir, float speed):Projectile(graphics_engine, grid, grid_location, dir, speed)
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
	CenterOrigin();
	SetScale(0.5f);
	//graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, texture_path, sheet_info);
	/*
	graphics_component_->SetOrigin(int2(sheet_info->window_size.x / 2, sheet_info->window_size.y - 25));
	graphics_component_->SetScale(0.5f);
	sprite_sheet_component_->SetPlayRate(0.1f);
	movement_component_ = make_shared<PathMovement>();
	movement_component_->SetSpeed(2.0f);
	*/
}

FireBall::~FireBall()
{
}

const int FireBall::FIREBALL_STATES[] = { 5,7,1,5 };
