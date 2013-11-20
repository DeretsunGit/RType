#pragma once

#include <list>
#include "Ennemy.h"
#include "Clock.h"
#include "Bullet.h"

class Wave
{
	int					_id;
	t_coord				_pos;
	Clock				_timeFireEnnemy;
	Clock				_timePopEnnemy;
	char				_color;
	std::list<float>	_timePopWave;
	int					_nbEnnemies;
public:
	Wave(int, std::list<float>);
	~Wave();

	void				action(std::list<Ennemy*>, std::list<Bullet*>, float);
	std::list<eSprites>	fillSpriteEnemy(eSprites, int);
	void				popEnnemy(std::list<Ennemy*>);
	void				moveEnnemy(std::list<Ennemy*>);
	void				moveBullet(std::list<Bullet*>);
	void				shoot(std::list<Ennemy*>, std::list<Bullet*>);

	int					getNbEnnemies();
	std::list<eSprites>	getSpritesEnnemies();
};
