#include "Ennemy.h"

Ennemy::Ennemy(int id)
{
	this->setId(id);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
	this->setShipAttributes();
}

Ennemy::~Ennemy(void)
{
}

void Ennemy::setShipAttributes()
{
	t_coord	pos;
	t_coord	hitBoxSize;

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
}

void Ennemy::setBullet()
{
}
