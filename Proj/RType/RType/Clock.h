#pragma once
#include <time.h>

class Clock
{
private:
	clock_t _startTime;

public:
	Clock(void);
	~Clock(void);
	bool initialise();
	float getTimeBySec();
};

