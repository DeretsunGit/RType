#include "stdafx.h"
#include "Clock.h"


Clock::Clock(void)
{
	_startTime = 0;
}

Clock::~Clock(void)
{
}

bool Clock::initialise()
{
	if ((_startTime = clock()) == -1)
		return (false);
	return (true);
}

float Clock::getTimeBySec()
{
	clock_t elapsedTime = clock() - _startTime;
	return (((float)elapsedTime)/CLOCKS_PER_SEC);
}