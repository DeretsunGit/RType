#pragma once

#include <list>
#include "Ennemy.h"

class Wave
{
	std::list<Ennemy>	_livingMobs;
	std::list<Ennemy>	_deadMobs;

public:
	Wave();
	~Wave();

	void	start();
	void	moveMobs();
	void	mobsAction();
};