#pragma once
#include "Timer.h"
#include "GridActor.h"
//#include "Unit.h"
class GameSystem
{
private:
	static shared_ptr<GameSystem> instance_;
	Timer timer_;
	float elapsed_seconds_;
	GameSystem();
	//vector<shared_ptr<Grid>> grids_;
	//vector<shared_ptr<GridActor>> grid_actors_;
	list<shared_ptr<Grid>> grids_;
	list<shared_ptr<GridActor>> grid_actors_;
	list<shared_ptr<DrawableObject>> screen_elements_;
	//vector<shared_ptr<DrawableObject>> screen_elements_;
public:
	static shared_ptr<GameSystem> GetInstance();
	static void Reset();
	~GameSystem();
	float GetElapsedSeconds();
	void Update();
	void Render(shared_ptr<Screen> screen);
	void AddGrid(shared_ptr<Grid> grid);
	void AddGridActor(shared_ptr<GridActor> grid_actor);
	void AddScreenElement(shared_ptr<DrawableObject> screen_element);
};

