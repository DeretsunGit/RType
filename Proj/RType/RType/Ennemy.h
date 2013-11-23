#pragma once

#include "Element.h"
#include "Bullet.h"
#include <map>

typedef struct	s_ennemy
{
	t_coord		hitBoxSize;
	eSprites	firstSprite;
	int			nbSprites;
	int			hp;
	int			speed;
}				t_ennemy;

typedef struct	s_bullet
{
	t_coord		hitBoxSize;
	int			hp;
	int			speed;
}				t_bullet;

class Ennemy : public Element
{
private:
	int							_idWave;
	unsigned short				_powerShoot;
public:
	Ennemy(int);
	~Ennemy();

	void	setBullet(std::list<Bullet*> &, t_bullet &);
	void	setIdWave(int);

	int		getIdWave();
};