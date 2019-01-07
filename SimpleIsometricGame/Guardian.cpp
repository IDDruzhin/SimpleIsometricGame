#include "stdafx.h"
#include "Guardian.h"


Guardian::Guardian(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location, int2 patrol_direction):Unit(grid, grid_location)
{
	//string texture_path = "Content/crusader_idle_00000.png";
	//string texture_path = "Content/abstractTile_21.png";
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
}


Guardian::~Guardian()
{
}
