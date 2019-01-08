#pragma once
#include "Unit.h"
#include "PathMovement.h"
class PlayerCharacter :
	public Unit
{
private:
	static const int PLAYER_CHARACTER_STATES[];
public:
	PlayerCharacter(shared_ptr<GraphicsEngine> graphics_engine, shared_ptr<Grid> grid, int2 grid_location);
	~PlayerCharacter();
	virtual int GetState();
	virtual void Update();
};

