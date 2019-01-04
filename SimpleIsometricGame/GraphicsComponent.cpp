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
