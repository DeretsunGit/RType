#include "Wall.h"

Wall::Wall()
{
	this->setBulletProof(true);
	this->setShipProof(true);
	this->setFaction(WALL);
	this->setSendPriority(2);
}

Wall::~Wall()
{
}