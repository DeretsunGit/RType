#include "ESprites.h"
#include "Wave.h"
#include "Randomisation.cpp"
template class Randomisation<bool>;

Wave::Wave(int id, std::list<float> timePopWave)
: _id(id), _timePopWave(timePopWave)
{
	this->_pos._posX = 1650;
	this->_pos._posY = 450;
	this->_nbEnnemies = 10;
}

Wave::~Wave()
{
}

void	Wave::action(std::list<Ennemy*> ennemies, std::list<Bullet*> bullets, float gameTime)
{
	//il faut faire la gestion des clocks pour appeler les methodes
	this->popEnnemy(ennemies);
	this->moveEnnemy(ennemies);
	this->moveBullet(bullets);
	this->shoot(ennemies, bullets);
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

void	Wave::popEnnemy(std::list<Ennemy*> ennemies)
{
	std::list<Ennemy*>::iterator	it;
	Randomisation<bool>				rand;
	t_coord							hitBoxSize;

	for (it = ennemies.begin(); ((it != ennemies.end()) || ((*it)->getHP() == 0)); ++it) {}
	if ((*it)->getHP() == 0)
	{
		(*it)->setHP(1);
		(*it)->setPos(&this->_pos);
		(*it)->setFaction(ENNEMY);
		(*it)->setSpeed(1);
		(*it)->setSide(rand.tRand(1));
		(*it)->setSprite(this->fillSpriteEnemy(ENEMY_RED_1, 8));
		(*it)->setIdWave(this->_id);
		hitBoxSize._posX = 10;
		hitBoxSize._posY = 10;
		(*it)->setHitboxSize(&hitBoxSize);
	}
}

void	Wave::moveEnnemy(std::list<Ennemy*> ennemies)
{
	std::list<Ennemy*>::iterator	it;

	for (it = ennemies.begin(); it != ennemies.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
		{
			//l� il faut faire un truc (ou pas) !
		}
	}
}

void	Wave::moveBullet(std::list<Bullet*> bullets)
{
	std::list<Bullet*>::iterator	it;

	for (it = bullets.begin(); it != bullets.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
		{
			//l� il faut faire un truc (ou pas) !
		}
	}
}

void	Wave::shoot(std::list<Ennemy*> ennemies, std::list<Bullet*> bullets)
{
	std::list<Ennemy*>::iterator	it;

	for (it = ennemies.begin(); it != ennemies.end(); ++it)
	{
		if (((*it)->getIdWave() == this->_id) && ((*it)->getHP() > 0))
			(*it)->setBullet(bullets);
	}
}

int		Wave::getNbEnnemies()
{
	return (this->_nbEnnemies);
}