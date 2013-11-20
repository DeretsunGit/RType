#include "Ennemy.h"
#include "Randomisation.cpp"
template class Randomisation<bool>;

Ennemy::Ennemy(int id)
{
	this->setId(id);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
}

Ennemy::~Ennemy(void)
{
}

void Ennemy::setBullet(std::list<Bullet*> &bullets)
{
	std::list<Bullet*>::iterator	it;
	t_coord							hitBoxSize;

	for (it = bullets.begin(); ((it != bullets.end()) || (*it)->getHP() == 0); ++it) {}
	if ((*it)->getHP() == 0)
	{
		(*it)->setHP(1);
		(*it)->setPos(&(this->getPos()));
		(*it)->setFaction(ENNEMY);
		(*it)->setSpeed(2);
		(*it)->setSide(this->getSide());
		(*it)->setSprite(std::list<eSprites>(BULLETS_AI));
		(*it)->setIdWave(this->_idWave);
		hitBoxSize._posX = 5;
		hitBoxSize._posY = 5;
		(*it)->setHitboxSize(&hitBoxSize);
	}
}

void	Ennemy::setIdWave(int idWave)
{
	this->_idWave = idWave;
}

int		Ennemy::getIdWave()
{
	return (this->_idWave);
}