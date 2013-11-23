#include "ESprites.h"
#include "Wave.h"
#include "Randomisation.cpp"
template class Randomisation<bool>;

Wave::Wave(int id, std::list<float> &timePopWave)
: _id(id), _timePopWave(timePopWave)
{
	this->_pos._posX =					1650;
	this->_pos._posY =					450;
	this->_nbEnnemies =					10;
	this->_popInterval =				1;
	this->_fireInterval =				1;
	this->_live = false;

	this->_ennemy.hitBoxSize._posX =	10;
	this->_ennemy.hitBoxSize._posY =	10;
	this->_ennemy.firstSprite =			ENEMY_RED_1;
	this->_ennemy.nbSprites =			8;
	this->_ennemy.hp =					1;
	this->_ennemy.speed =				1;

	this->_bullet.hitBoxSize._posX =	5;
	this->_bullet.hitBoxSize._posY =	5;
	this->_bullet.hp =					1;
	this->_bullet.speed =				2;
}

Wave::~Wave()
{
}

bool	Wave::checkEnemiesStillAlive(std::list<Ennemy*> &ennemies)
{
	std::list<Ennemy*>::iterator	it;

	for (it = ennemies.begin(); it != ennemies.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
			return (true);
	}
	return (false);
}

void	Wave::action(std::list<Ennemy*> &ennemies, std::list<Bullet*> &bullets, float gameTime)
{
	if (!this->_live && this->_timePopWave.front() >= gameTime)
	{
		this->_timePopWave.pop_front();
		this->_timePopEnnemy.initialise();
		this->_timeFireEnnemy.initialise();
		this->_live = true;
		this->popEnnemy(ennemies);
		--this->_nbEnnemies;
	}
	if (this->_nbEnnemies <= 0 && !this->checkEnemiesStillAlive(ennemies))
		this->_live = false;
	if (this->_live)
	{
		if (this->_timeFireEnnemy.getTimeBySec() >= this->_fireInterval)
		{
			this->shoot(ennemies, bullets);
			this->_timeFireEnnemy.initialise();
		}
		if (this->_timePopEnnemy.getTimeBySec() >= this->_popInterval)
		{
			this->popEnnemy(ennemies);
			--this->_nbEnnemies;
			this->_timePopEnnemy.initialise();
		}
		this->moveEnnemy(ennemies);
		this->moveBullet(bullets);
	}
}

std::list<eSprites>	Wave::fillSpriteEnemy(eSprites firstSprite, int nb)
{
	int cpt = 0;
	std::list<eSprites> sprites;

	while (cpt < nb)
	{
		sprites.push_back(static_cast<eSprites>(firstSprite + cpt));
		++cpt;
	}
	return (sprites);
}

void	Wave::popEnnemy(std::list<Ennemy*> &ennemies)
{
	std::list<Ennemy*>::iterator	it;
	Randomisation<bool>				rand;

	for (it = ennemies.begin(); ((it != ennemies.end()) && ((*it)->getHP() == 0)); ++it) {}
	if ((*it)->getHP() == 0)
	{
		(*it)->setHP(this->_ennemy.hp);
		(*it)->setPos(&this->_pos);
		(*it)->setFaction(ENNEMY);
		(*it)->setSpeed(this->_ennemy.speed);
		(*it)->setSide(rand.tRand(1));
		(*it)->setSprite(this->fillSpriteEnemy(this->_ennemy.firstSprite, this->_ennemy.nbSprites));
		(*it)->setIdWave(this->_id);
		(*it)->setHitboxSize(&this->_ennemy.hitBoxSize);
	}
}

void	Wave::moveEnnemy(std::list<Ennemy*> &ennemies)
{
	std::list<Ennemy*>::iterator	it;

	for (it = ennemies.begin(); it != ennemies.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
		{
			//l� il faut coder les mouvements des ennemies
		}
	}
}

void	Wave::moveBullet(std::list<Bullet*> &bullets)
{
	std::list<Bullet*>::iterator	it;

	for (it = bullets.begin(); it != bullets.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
		{
			//l� il faut coder les mouvements des boulettes
		}
	}
}

void	Wave::shoot(std::list<Ennemy*> &ennemies, std::list<Bullet*> &bullets)
{
	std::list<Ennemy*>::iterator	it;

	for (it = ennemies.begin(); it != ennemies.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
			(*it)->setBullet(bullets, this->_bullet);
	}
}

int		Wave::getNbEnnemies()
{
	return (this->_nbEnnemies);
}