#pragma once
#include <cstdlib>
#include <limits>

template<typename T>
class Randomisation
{

public:
	Randomisation();
	~Randomisation();

	//T		tRand(); //rand sur les positif du type passé
	T		tRand(T); // random de 0 à x
	T		tRand(T, T); // random entre x et y

};