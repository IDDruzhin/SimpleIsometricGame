#pragma once
#include "Timer.h"

struct SheetInfo
{
	uint2 window_size;
	uint2 sheet_dim;
	vector<uint2> sheet_intervals; //x - start pos, y - frames count
};

class GraphicsComponent
{
protected:
	shared_ptr<SheetInfo> sheet_info_;
	uint cur_state_;
	uint cur_frame_;
	float play_rate_;
	Timer timer_;
	virtual void SetSpriteWindow() = 0;
public:
	GraphicsComponent();
	~GraphicsComponent();
	void SetSheetInfo(shared_ptr<SheetInfo> sheet_info);
	void SetState(uint state);
	void NextFrame();
	virtual void SetLocation(float2 location) = 0;
	virtual void SetColor(uchar r = 255, uchar g = 255, uchar b = 255, uchar a = 255) = 0;
};

