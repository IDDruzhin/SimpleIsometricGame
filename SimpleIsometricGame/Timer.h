#pragma once
class Timer
{
private:
	chrono::time_point<chrono::system_clock> start_;
	float init_seconds_;
public:
	Timer();
	~Timer();
	float GetElapsedSeconds();
	void Restart(float init_seconds = 0.0f);
};

