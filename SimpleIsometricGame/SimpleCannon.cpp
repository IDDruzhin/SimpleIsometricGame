#include "stdafx.h"
#include "SimpleCannon.h"


SimpleCannon::SimpleCannon(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location):Cannon(graphics_engine, grid, grid_location)
{
	string texture_path = "Content/unicorn_atlas.png";
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 24;
	sheet_info->window_size.x = 85;
	sheet_info->window_size.y = 170;
	int sets_count = 40;
	for (int i = 0; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i * 6, 6));
	}
	sets_count = 40 * 6 + 24;
	for (int i = 40 * 6; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i, 0));
	}
	RegisterGraphics(graphics_engine, texture_path, sheet_info);
	graphics_component_->SetOrigin(int2(sheet_info->window_size.x / 2, sheet_info->window_size.y - 25));
	graphics_component_->SetScale(0.5f);
	attack_component_ = make_shared<FireballAttack>(graphics_engine);
	if (grid_location_.x < 0)
	{
		UpdateSprite(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::RIGHT]);
		//sprite_sheet_component_->SetState(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::RIGHT]);
	}
	else if (grid_location_.x >= grid_->GetDim().x)
	{
		UpdateSprite(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::LEFT]);
		//sprite_sheet_component_->SetState(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::LEFT]);
	}
	else if (grid_location_.y >= grid_->GetDim().y)
	{
		UpdateSprite(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::TOP]);
		//sprite_sheet_component_->SetState(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::TOP]);
	}
	else if (grid_location_.y < 0)
	{
		UpdateSprite(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::DOWN]);
		//sprite_sheet_component_->SetState(SIMPLE_CANNON_STATES[ACTOR_DIRECTION::DOWN]);
	}
}

SimpleCannon::~SimpleCannon()
{
}

const int SimpleCannon::SIMPLE_CANNON_STATES[] = { 53,54,51,49};
