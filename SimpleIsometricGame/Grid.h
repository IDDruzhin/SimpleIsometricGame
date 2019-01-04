#pragma once
#include "BaseObject.h"
#include "GraphicsComponent.h"
class Grid :
	public BaseObject
{
protected:
	uint2 dim_;
	float cell_size_;
	vector<unsigned char> cells_map_;
	shared_ptr<GraphicsComponent> cells_graphics_;
public:
	Grid();
	Grid(uint2 dim, float cell_size);
	~Grid();
	void SetDim(uint2 dim);
	uint2 GetDim();
	void SetCellsMap(vector<unsigned char> cells_map);
	void RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, const string &path);
	void GenerateRandomGrid(int seed = 123);
	void Draw(shared_ptr<GraphicsEngine> graphics_engine);
	float2 GridToScreen(float2 grid_pos);
	float2 ScreenToGrid(float2 screen_pos);
};

