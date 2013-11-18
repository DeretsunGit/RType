#include "Ennemy.h"
#include "Randomisation.h"

Ennemy::Ennemy(int id, char color)
{
	this->setId(id);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
	this->setColor(color);
	this->setShipAttributes();
}

Ennemy::~Ennemy(void)
{
}

void Ennemy::setShipAttributes()
{
	Randomisation<bool>	rand;
	t_coord				pos;
	t_coord				hitBoxSize;

	this->_skins[1] = "default.jpg";
	this->_skins[2] = "defaultUp.jpg";
	this->_skins[3] = "defaultDown.jpg";
	this->setHP(1);
	pos._posX = 1650;
	pos._posY = 450;
	this->setPos(&pos);
	hitBoxSize._posX = 10;
	hitBoxSize._posY = 10;
	this->setHitboxSize(&hitBoxSize);
	this->setSpeed(1);
	this->_powerShoot = 1;
	this->setSide(rand.tRand(1));
}

void Ennemy::setBullet(std::list<Bullet*> &bullets)
{
	std::list<Bullet*>::iterator it;

	for (it = bullets.begin(); ((it != bullets.end()) || (*it)->getHP() == 0); ++it)
	{
	}
	if ((*it)->getHP() == 0)
	{
		/*
		set HP
		set Skin
		set Hitbox
		set Pos
		set Faction
		set Speed
		*/
	}
}
