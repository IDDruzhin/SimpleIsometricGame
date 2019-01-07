#pragma once
#include "DrawableObject.h"
#include "BitSet.h"
class Grid :
	public DrawableObject
{
protected:
	uint2 dim_;
	float2 cell_offset_;
	Bitset block_mask_;
	Bitset employ_mask_;
	Bitset killzone_mask_;
	vector<unsigned char> cells_map_;
	//shared_ptr<GraphicsComponent> cells_graphics_;
public:
	Grid();
	//Grid(uint2 dim, float2 cell_tile_size, shared_ptr<GraphicsEngine> graphics_engine, const string &cell_texture_path);
	~Grid();
	void SetDim(uint2 dim);
	uint2 GetDim();
	void SetCellOffset(float2 cell_offset);
	void SetCellOffset(float tile_width);
	float2 GetCellOffset();
	//void SetCellsMap(vector<unsigned char> cells_map);
	//void RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path);
	//void RegisterCellsGraphics(shared_ptr<GraphicsEngine> graphics_engine, string path, shared_ptr<SheetInfo> sheet_info);
	virtual void GenerateRandomGrid(int seed = 123);
	virtual void Draw(shared_ptr<Screen> screen);
	//void Draw(shared_ptr<GraphicsEngine> graphics_engine);
	float2 GridToScreen(float2 grid_pos);
	float2 ScreenToGrid(float2 screen_pos);
	float2 GetGridCenter();
	bool IsInsideGrid(float2 grid_pos);
	bool IsInsideGrid(int2 grid_pos);
	bool CheckBlockMask(int2 pos);
	bool CheckEmployMask(int2 pos);
	void SetBlockMask(int2 pos, bool block);
	void SetEmployMask(int2 pos);
	void SetKillzoneMask(int2 pos);
	void ClearEmployMask();
	void ClearKillzoneMask();
	void PrintMask(Bitset mask);
};

