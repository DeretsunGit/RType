#include	"Randomization.hpp"

template<>
bool	Randomization<bool>::tRand(bool max)
{
	if ((rand() % 2) == 0)
		return (true);
	return (false);
}
