#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location):Unit(grid, grid_location)
{
	string texture_path = "Content/spaghetti_atlas.png";
	shared_ptr<SheetInfo> sheet_info = make_shared<SheetInfo>();
	sheet_info->sheet_dim_x = 24;
	sheet_info->window_size.x = 85;
	sheet_info->window_size.y = 170;
	int sets_count = 40;
	for (int i = 0; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i*6, 6));
	}
	sets_count = 40 * 6 + 24;
	for (int i = 40 * 6; i < sets_count; i++)
	{
		sheet_info->sheet_intervals.push_back(uint2(i, 0));
	}
	RegisterGraphics(graphics_engine, texture_path, sheet_info);
	graphics_component_->SetOrigin(int2(sheet_info->window_size.x / 2, sheet_info->window_size.y - 25));
	graphics_component_->SetScale(0.5f);
	sprite_sheet_component_->SetPlayRate(0.1f);
	movement_component_ = make_shared<PathMovement>();
	movement_component_->SetSpeed(2.0f);
}

PlayerCharacter::~PlayerCharacter()
{
}

int PlayerCharacter::GetState()
{
	float2 velocity = movement_component_->GetVelocity();
	if (abs(velocity.x) >= abs(velocity.y))
	{
		if (velocity.x >= 0)
		{
			if (movement_component_->IsMoving())
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::WALK_RIGHT];
			}
			else
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::IDLE_RIGHT];
			}		
		}
		else
		{
			if (movement_component_->IsMoving())
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::WALK_LEFT];
			}
			else
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::IDLE_LEFT];
			}		
		}
	}
	else
	{
		if (velocity.y >= 0)
		{
			if (movement_component_->IsMoving())
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::WALK_DOWN];
			}
			else
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::IDLE_DOWN];
			}
		}
		else
		{
			if (movement_component_->IsMoving())
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::WALK_TOP];
			}
			else
			{
				return PLAYER_CHARACTER_STATES[UNIT_STATE::IDLE_TOP];
			}
		}
	}
	return uint();
}


void PlayerCharacter::Update()
{
	Unit::Update();
}

const int PlayerCharacter::PLAYER_CHARACTER_STATES[] = { 45,46,43,41,6,5,3,1 };
