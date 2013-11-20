#include "ESprites.h"
#include "Wave.h"

Wave::Wave(std::list<float> timePopWave)
: _timePopWave(timePopWave)
{
	this->_pos._posX = 1650;
	this->_pos._posY = 450;
}

Wave::~Wave()
{
}

void	Wave::action(std::list<Ennemy*> ennemies, std::list<Bullet*> bullets, float gameTime)
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
