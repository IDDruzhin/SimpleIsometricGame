#include "stdafx.h"
#include "Timer.h"


Timer::Timer():init_seconds_(0.0f),start_(chrono::system_clock::now())
{
}


Timer::~Timer()
{
}

float Timer::GetElapsedSeconds()
{
	float elapsed_seconds = init_seconds_ + chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_).count() / 1000.0f;
}

void Timer::Restart(float init_seconds)
{
	init_seconds_ = init_seconds;
	start_ = chrono::system_clock::now();
}
