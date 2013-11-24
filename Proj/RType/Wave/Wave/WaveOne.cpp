#include "WaveOne.h"

WaveOne::WaveOne(int id, std::list<float> &timePopWave)
: Wave(id, timePopWave)
{
	this->_pos._posX = 1650;
	this->_pos._posY = 450;
	this->_nbEnnemies = 10;
	this->_popInterval = 1;
	this->_fireInterval = 1;
	this->_live = false;

	this->_ennemy.hitBoxSize._posX = 10;
	this->_ennemy.hitBoxSize._posY = 10;
	this->_ennemy.firstSprite = ENEMY_RED_1;
	this->_ennemy.nbSprites = 8;
	this->_ennemy.hp = 1;
	this->_ennemy.speed = 6;

	this->_bullet.hitBoxSize._posX = 5;
	this->_bullet.hitBoxSize._posY = 5;
	this->_bullet.hp = 1;
	this->_bullet.speed = 10;
}

WaveOne::~WaveOne()
{
}

extern "C"
{
#ifdef _WIN32
	__declspec(dllexport)
#endif
		WaveOne* entry_point(int id, std::list<float> &timePopWave)
	{
		return (new WaveOne(id, timePopWave));
	}
}
