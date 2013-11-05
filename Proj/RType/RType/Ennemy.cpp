#include "Ennemy.h"


Ennemy::Ennemy(void)
{
	this->setBulletProof(false);
	this->setShipProof(false);
	this->setFaction(ENNEMY);
	this->setSendPriority(1);
}


Ennemy::~Ennemy(void)
{
}
