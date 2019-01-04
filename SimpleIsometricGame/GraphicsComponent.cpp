#include "stdafx.h"
#include "GraphicsComponent.h"


GraphicsComponent::GraphicsComponent()
{
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::SetSheetInfo(shared_ptr<SheetInfo> sheet_info)
{
	sheet_info_ = sheet_info;
}

void GraphicsComponent::SetState(uint state)
{
	if (cur_state_ != state)
	{
		cur_state_ = state;
		cur_frame_ = 0;
		SetSpriteWindow();
	}
}

void GraphicsComponent::NextFrame()
{
	if (sheet_info_)
	{
		float time = timer_.GetElapsedSeconds() - play_rate_;
		if (time > 0)
		{
			cur_frame_++;
			if (cur_frame_ >= sheet_info_->sheet_intervals[cur_state_].y)
			{
				cur_frame_ = 0;
			}
			SetSpriteWindow();
			timer_.Restart(time);
		}
	}
}
