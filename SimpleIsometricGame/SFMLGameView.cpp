#include "stdafx.h"
#include "SFMLGameView.h"


SFMLGameView::SFMLGameView()
{
	screen_ = make_shared<SFMLWindow>();
	uint2 size;
	size.x = 500;
	size.y = 500;
	//screen_ = make_shared<SFMLWindow>(size,"Low");
}


SFMLGameView::~SFMLGameView()
{
}

shared_ptr<GraphicsEngine> SFMLGameView::GetGraphicsEngine()
{
	return SFMLGraphicsEngine::GetInstance();
}

void SFMLGameView::Render()
{
	model_->Render(screen_);
}

shared_ptr<InputController> SFMLGameView::GetCompatibleController()
{
	shared_ptr<InputController> compatible_controller;
	shared_ptr<SFMLWindow> window = dynamic_pointer_cast<SFMLWindow>(screen_);
	if (window)
	{
		compatible_controller = make_shared<SFMLInputController>(window->GetWindow());
	}
	return compatible_controller;
}