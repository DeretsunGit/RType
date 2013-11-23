#pragma once
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include "Clock.hpp"

class Event
{
public:
	Event(void);
	~Event(void);
	void start();

private:
	float getSecFromStrHour(const std::string&) const;
	float getSecFromStrMin(const std::string&) const;
	float getSecFromStrMSec(const std::string&) const;
	float transformFormat(const std::string&) const;

	std::map<float, std::string> _events;
	Clock _clock;
};

