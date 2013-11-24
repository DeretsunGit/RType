#include "Ennemy.h"
#include "Randomization.hpp"

Ennemy::Ennemy(int id)
{
	this->setId(id);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
}

Ennemy::~Ennemy(void)
{
}

void Ennemy::setBullet(std::list<Bullet*> &bullets, t_bullet &bullet)
{
	std::list<Bullet*>::iterator	it;

	for (it = bullets.begin(); ((it != bullets.end()) || (*it)->getHP() == 0); ++it) {}
	if ((*it)->getHP() == 0)
	{
		(*it)->setHP(bullet.hp);
		(*it)->setPos(&(this->getPos()));
		(*it)->setFaction(ENNEMY);
		(*it)->setSpeed(bullet.speed);
		(*it)->setSide(this->getSide());
		(*it)->setSprite(std::list<eSprites>(BULLETS_AI));
		(*it)->setIdWave(this->_idWave);
		(*it)->setHitboxSize(&bullet.hitBoxSize);
	}
}

void	Ennemy::setIdWave(int idWave)
{
	this->_idWave = idWave;
}

int		Ennemy::getIdWave() const
{
	return (this->_idWave);
}