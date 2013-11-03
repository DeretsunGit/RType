#pragma once

#include "Element.h"

class Ennemy : public Element
{
	int			_hp;

public:
	Ennemy();
	~Ennemy();

	void	reset();
	void	onDeath();
};