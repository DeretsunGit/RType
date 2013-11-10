#pragma once
#include <cstdlib>
#include <limits>

template<class T>
class Randomisation
{
	bool	_is;

public:
	Randomisation();
	~Randomisation();

	void	init();
	T		tRand(); //rand sur les positif du type passé
	T		tRand(T); // random de 0 à x
	T		tRand(T, T); // random entre x et y

};