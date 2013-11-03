#pragma once

#include "Element.h"

class Ennemy : public Element
{
public:
	Ennemy();
	~Ennemy();

	void	reset();
	void	onDeath();
};