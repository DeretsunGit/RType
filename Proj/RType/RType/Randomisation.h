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
	T		tRand(); //rand sur les positif du type pass�
	T		tRand(T); // random de 0 � x
	T		tRand(T, T); // random entre x et y

};