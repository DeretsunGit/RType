#pragma once
#include <time.h>

class Clock
{
private:
	clock_t _startTime;
public:
	Clock(void)
	{
		this->_startTime = 0;
	}

	~Clock(void)
	{
	}

	bool initialise()
	{
		if ((this->_startTime = clock()) == -1)
			return (false);
		return (true);
	}

	float getTimeBySec()
	{
		clock_t elapsedTime = clock() - this->_startTime;
		return (((float)elapsedTime) / CLOCKS_PER_SEC);
	}
};

