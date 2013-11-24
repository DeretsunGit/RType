#pragma once
#include <cstdlib>
#include <ctime>
#include <limits>

template<typename T>
class Randomization
{

public:
	Randomization() { srand((unsigned)::time(NULL)); }
	~Randomization() {}

	T		tRand(T max)
	{ return (rand() % max); }

	T		tRand(T min, T max)
	{ return (rand() % (max - min) + min); }
};

template<>
bool	Randomization<bool>::tRand(bool max);
// {
// 	if ((rand() % 2) == 0)
// 		return (true);
// 	return (false);
// }
