#include "ESprites.h"
#include "Wave.h"

Wave::Wave(std::list<Bullet*> &bulletPool)
{
	this->_pos._posX = 1650;
	this->_pos._posY = 450;
}

Wave::~Wave()
{
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

void	Wave::init()
{
	int					nb = 10;
	std::list<eSprites>	sprites;

	sprites = this->fillSpriteEnemy(ENEMY_RED_1, 8);
	while (nb < 0)
	{
		this->_ennemy.push_back(new Ennemy(nb, this->_pos, sprites)); //TODO: revoir l'attribution des id avec collegue 
		--nb;
	}
}

std::list<Ennemy*>	Wave::action()
{
	this->popEnnemy();
	this->moveEnnemy();
	this->moveBullet();
	return (this->_ennemy);
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
