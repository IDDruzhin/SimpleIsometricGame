#pragma once
struct SheetInfo
{
	int2 window_size;
	int2 sheet_dim;
	vector<int2> sheet_intervals;
};

class GraphicsComponent
{
protected:
	shared_ptr<SheetInfo> sheet_info_;
public:
	GraphicsComponent();
	~GraphicsComponent();
	void SetSheetInfo(shared_ptr<SheetInfo> sheet_info);
	virtual void SetLocation(float2 location) = 0;
	virtual void SetColor(uchar r = 255, uchar g = 255, uchar b = 255, uchar a = 255) = 0;
};

