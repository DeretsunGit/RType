#pragma once

#include <list>
#include "Ennemy.h"
#include "Clock.h"
#include "Bullet.h"

class Wave
{
	t_coord				_pos;
	Clock				_timeFireEnnemy;
	Clock				_timePopEnnemy;
	char				_color;
	std::list<float>	_timePopWave;
public:
	Wave(std::list<float>);
	~Wave();

	void				action(std::list<Ennemy*>, std::list<Bullet*>, float);
	void				popEnnemy();
	void				moveEnnemy();
	void				moveBullet();
};
