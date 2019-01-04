#include "stdafx.h"
#include "SpriteSheetComponent.h"


SpriteSheetComponent::SpriteSheetComponent()
{
}


SpriteSheetComponent::~SpriteSheetComponent()
{
}

void SpriteSheetComponent::SetSheetInfo(shared_ptr<SheetInfo> sheet_info)
{
	sheet_info_ = sheet_info;
}

bool SpriteSheetComponent::SetState(uint state)
{
	if (cur_state_ != state)
	{
		cur_state_ = state;
		cur_frame_ = 0;
		return true;
	}
	return false;
}

bool SpriteSheetComponent::NextFrame()
{
	float time = timer_.GetElapsedSeconds() - play_rate_;
	if (time > 0)
	{
		cur_frame_++;
		if (cur_frame_ >= sheet_info_->sheet_intervals[cur_state_].y)
		{
			cur_frame_ = 0;
		}
		timer_.Restart(time);
		return true;
	}
	return false;
}

Rect SpriteSheetComponent::GetCurRect()
{
	Rect r;
	uint cur_index = cur_state_ + cur_frame_;
	uint2 cur_pos;
	cur_pos.x = cur_index % sheet_info_->sheet_dim_x;
	cur_pos.y = cur_index / sheet_info_->sheet_dim_x;
	r.top_left.x = sheet_info_->window_size.x * cur_pos.x;
	r.top_left.y = sheet_info_->window_size.y * cur_pos.y;
	r.size = sheet_info_->window_size;
	return r;
}