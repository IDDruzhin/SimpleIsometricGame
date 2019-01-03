#pragma once
#include "BaseObject.h"
#include "GraphicsComponent.h"
class Grid :
	public BaseObject
{
protected:
	int2 dim_;
	float cell_size_;
	vector<unsigned char> cells_map_;
	vector<shared_ptr<GraphicsComponent>> cells_graphics_;
public:
	Grid();
	Grid(int2 dim, float cell_size);
	~Grid();
	void SetDim(int2 dim);
	int2 GetDim();
	void SetCellsMap(vector<unsigned char> cells_map);
	void RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, const vector<string> &pathes);
	void GenerateRandomGrid(int seed = 123);
	void Draw(shared_ptr<GraphicsEngine> graphics_engine);
};

