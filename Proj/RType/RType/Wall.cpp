#include "Wall.h"

Wall::Wall()
{
	this->setBulletProof(true);
	this->setShipProof(true);
	this->setFaction(0);
	this->setSendPriority(2);
}

Wall::~Wall()
{
}