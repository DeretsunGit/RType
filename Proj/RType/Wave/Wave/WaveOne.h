#pragma once

#include <list>
#include "Wave.hpp"

class WaveOne : public Wave
{
public:
	WaveOne(int, std::list<float>&);
	~WaveOne();
};
