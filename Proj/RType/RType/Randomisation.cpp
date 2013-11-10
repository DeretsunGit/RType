#include "Randomisation.h"


template<class T>
Randomisation<T>::Randomisation()
{
	srand(TIME(NULL));
}

template<class T>
Randomisation<T>::~Randomisation()
{

}

template<class T>
T		Randomisation<T>::tRand()
{
	return (rand() % std::numeric_limits<T>::max());
}

template<class T>
T		Randomisation<T>::tRand(T max)
{
	return (rand() % max);
}

template<class T>
T		Randomisation<T>::tRand(T min, T max)
{
	return (rand() % max + min);
}