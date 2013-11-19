#include "Ennemy.h"
#include "Randomisation.cpp"
template class Randomisation<bool>;

Ennemy::Ennemy(int id, t_coord pos, std::list<eSprites> sprites)
{
	this->setId(id);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
	this->setPos(&pos);
	this->setShipAttributes();
	this->setSprite(sprites);
}

Ennemy::~Ennemy(void)
{
}

void Ennemy::setShipAttributes()
{
	Randomisation<bool>	rand;
	t_coord				hitBoxSize;

	this->setHP(1);
	this->setSpeed(1);
	this->_powerShoot = 1;
	this->setSide(rand.tRand(1));
	hitBoxSize._posX = 10;
	hitBoxSize._posY = 10;
	this->setHitboxSize(&hitBoxSize);
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
		hitBoxSize._posX = 5;
		hitBoxSize._posY = 5;
		(*it)->setHitboxSize(&hitBoxSize);
	}
}
