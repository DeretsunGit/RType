#include <ctime>
#include "Randomisation.h"

template<typename T>
Randomisation<T>::Randomisation()
{
  srand(::time(NULL));
}

template<typename T>
Randomisation<T>::~Randomisation()
{

}

/*template<class T>
T		Randomisation<T>::tRand()
{
	return (rand() % std::numeric_limits<T>::max());
}*/

template<class T>
T		Randomisation<T>::tRand(T max)
{
	return (rand() % max);
}

template<typename T>
T		Randomisation<T>::tRand(T min, T max)
{
	return (rand() % (max - min) + min);
}
