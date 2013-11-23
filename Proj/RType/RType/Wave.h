#pragma once

#include <list>
#include "Ennemy.h"
#include "Clock.h"
#include "Bullet.h"

class Wave
{
private:
	int					_id;
	std::list<float>	_timePopWave;
protected:
	t_coord				_pos;
	Clock				_timeFireEnnemy;
	Clock				_timePopEnnemy;
	char				_color;
	int					_nbEnnemies;
	float				_popInterval;
	float				_fireInterval;
	bool				_live;
	t_ennemy			_ennemy;
	t_bullet			_bullet;
public:
	Wave(int, std::list<float>&);
	~Wave();

	void				action(std::list<Ennemy*>&, std::list<Bullet*>&, float);
	std::list<eSprites>	fillSpriteEnemy(eSprites, int);
	void				popEnnemy(std::list<Ennemy*>&);
	void				moveEnnemy(std::list<Ennemy*>&);
	void				moveBullet(std::list<Bullet*>&);
	void				shoot(std::list<Ennemy*>&, std::list<Bullet*>&);
	bool				checkEnemiesStillAlive(std::list<Ennemy*>&);

	int					getNbEnnemies();
};
