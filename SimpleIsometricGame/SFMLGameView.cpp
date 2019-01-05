#include "stdafx.h"
#include "SFMLGameView.h"


SFMLGameView::SFMLGameView()
{
	screen_ = make_shared<SFMLWindow>();
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
	shared_ptr<SFMLInputController> compatible_controller;
	shared_ptr<SFMLWindow> window = dynamic_pointer_cast<SFMLWindow>(screen_);
	if (window)
	{
		compatible_controller = make_shared<SFMLInputController>(window->GetWindow());
	}
	return compatible_controller;
}
