#pragma once
#include "Timer.h"

struct SheetInfo
{
	uint2 window_size;
	uint sheet_dim_x;
	vector<uint2> sheet_intervals; //x - start pos, y - frames count
	SheetInfo() {};
};

class SpriteSheetComponent
{
protected:
	shared_ptr<SheetInfo> sheet_info_;
	uint cur_state_;
	uint cur_frame_;
	float play_rate_;
	Timer timer_;
public:
	SpriteSheetComponent();
	~SpriteSheetComponent();
	void SetSheetInfo(shared_ptr<SheetInfo> sheet_info);
	bool SetState(int state);
	bool NextFrame();
	Rect GetCurRect();
	uint GetTilesCount();
	void SetPlayRate(float rate);
};

