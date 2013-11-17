#pragma once

#include <list>
#include "Ennemy.h"
#include "Clock.h"
#include "Bullet.h"

class Wave
{
	std::list<Ennemy>	_ennemy;
	t_coord				_pos;
	Clock				_timeFire;
	Clock				_timePop;
public:
	Wave(std::list<Bullet*> &);
	~Wave();

	void	init();
	void	action();
	void	popEnnemy();
	void	moveEnnemy();
	void	moveBullet();
};
