#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location):Unit(grid, grid_location)
{
	string texture_path = "Content/RedTile.png";

	graphics_engine->RegisterGraphicsResource(graphics_component_, sprite_sheet_component_, texture_path);
	movement_component_ = make_shared<PathMovement>();
	graphics_component_->SetScale(0.2f);
}

PlayerCharacter::~PlayerCharacter()
{
}
