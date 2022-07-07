#include "Timer.h"
using namespace std::chrono;
Timer::Timer()
{
	time = steady_clock::now();
}

float Timer::Mark()
{
	const auto old = time;
	time = steady_clock::now();
	const duration<float> frameTime = time - old;
	return frameTime.count();
}
