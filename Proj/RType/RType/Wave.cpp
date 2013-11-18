#include "Wave.h"
#include "Randomisation.cpp"
template class Randomisation<char>;

Wave::Wave(std::list<Bullet*> &bulletPool)
{
	Randomisation<char>	rand;

	this->_pos._posX = 1650;
	this->_pos._posY = 450;
	this->_color = rand.tRand(4);
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
