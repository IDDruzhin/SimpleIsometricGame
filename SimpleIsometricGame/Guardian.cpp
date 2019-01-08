#include "stdafx.h"
#include "Guardian.h"


Guardian::Guardian(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, int2 patrol_direction):Unit(grid, grid_location)
{
	//string texture_path = "Content/crusader_idle_00000.png";
	//string texture_path = "Content/abstractTile_21.png";
	/*
	string texture_path = "Content/RedTile.png";
	
	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, texture_path);
	int2 patrol_locaton;
	patrol_locaton.x = grid_location.x;
	patrol_locaton.y = grid_location.y;
	if (patrol_direction.x > 0)
	{
		patrol_locaton.x += 1;
	}
	else if (patrol_direction.x < 0)
	{
		patrol_locaton.x -= 1;
	}
	if (patrol_direction.y > 0)
	{
		patrol_locaton.y += 1;
	}
	else if (patrol_direction.y < 0)
	{
		patrol_locaton.y -= 1;
	}
	movement_component_ = make_shared<PatrolMovement>(grid_location, patrol_locaton);
	graphics_component_->SetScale(0.2f);
	*/
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
	//graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, texture_path, sheet_info);
	RegisterGraphics(graphics_engine, texture_path, sheet_info);
	graphics_component_->SetOrigin(int2(sheet_info->window_size.x / 2, sheet_info->window_size.y - 25));
	graphics_component_->SetScale(0.5f);
	sprite_sheet_component_->SetPlayRate(0.1f);

	int2 patrol_locaton;
	patrol_locaton.x = grid_location.x;
	patrol_locaton.y = grid_location.y;
	if (patrol_direction.x > 0)
	{
		patrol_locaton.x += 1;
	}
	else if (patrol_direction.x < 0)
	{
		patrol_locaton.x -= 1;
	}
	if (patrol_direction.y > 0)
	{
		patrol_locaton.y += 1;
	}
	else if (patrol_direction.y < 0)
	{
		patrol_locaton.y -= 1;
	}
	movement_component_ = make_shared<PatrolMovement>(grid_location, patrol_locaton);
	movement_component_->SetSpeed(1.7f);
	attack_component = make_shared<AttackComponent>();
}


Guardian::~Guardian()
{
}

uint Guardian::GetState()
{
	float2 velocity = movement_component_->GetVelocity();
	if (abs(velocity.x) >= abs(velocity.y))
	{
		if (velocity.x >= 0)
		{
			if (movement_component_->IsMoving())
			{
				return GUARDIAN_STATES[UNIT_STATE::WALK_RIGHT];
			}
			else
			{
				return GUARDIAN_STATES[UNIT_STATE::IDLE_RIGHT];
			}
		}
		else
		{
			if (movement_component_->IsMoving())
			{
				return GUARDIAN_STATES[UNIT_STATE::WALK_LEFT];
			}
			else
			{
				return GUARDIAN_STATES[UNIT_STATE::IDLE_LEFT];
			}
		}
	}
	else
	{
		if (velocity.y >= 0)
		{
			if (movement_component_->IsMoving())
			{
				return GUARDIAN_STATES[UNIT_STATE::WALK_DOWN];
			}
			else
			{
				return GUARDIAN_STATES[UNIT_STATE::IDLE_DOWN];
			}
		}
		else
		{
			if (movement_component_->IsMoving())
			{
				return GUARDIAN_STATES[UNIT_STATE::WALK_TOP];
			}
			else
			{
				return GUARDIAN_STATES[UNIT_STATE::IDLE_TOP];
			}
		}
	}
	return uint();
}

void Guardian::Update()
{
	Unit::Update();
	attack_component->Attack(grid_, GetGridCellLocation());
	//grid_->SetKillzoneMask(GetGridCellLocation());
}

//const int Guardian::GUARDIAN_STATES[] = { 45,46,43,41,6,5,3,1 };
const int Guardian::GUARDIAN_STATES[] = { 61,62,59,57,22,21,19,17 };
