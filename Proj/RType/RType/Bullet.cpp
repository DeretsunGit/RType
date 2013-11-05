#include "Bullet.h"


Bullet::Bullet(void)
{
	this->setBulletProof(true);
	this->setShipProof(false);
	this->setSendPriority(0);
	this->setFaction(WALL);
}


Bullet::~Bullet(void)
{
}
