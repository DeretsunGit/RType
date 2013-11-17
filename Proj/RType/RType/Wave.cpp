#include "Wave.h"

Wave::Wave(std::list<Bullet*> &bulletPool)
{
	this->_pos._posX = 1650;
	this->_pos._posY = 450;
}

Wave::~Wave()
{
}

void	Wave::init()
{
	
}

void	Wave::action()
{
	this->popEnnemy();
	this->moveEnnemy();
	this->moveBullet();
}

void	Wave::popEnnemy()
{

}

void	Wave::moveEnnemy()
{

}

void	Wave::moveBullet()
{

}
