#pragma once
#include <cstdlib>
#include <limits>

template<typename T>
class Randomisation
{

public:
	Randomisation();
	~Randomisation();

	//T		tRand(); //rand sur les positif du type pass�
	T		tRand(T); // random de 0 � x
	T		tRand(T, T); // random entre x et y

};