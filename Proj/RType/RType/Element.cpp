#include "Element.h"


Element::Element(void)
{

}

t_coord Element::getPos()
{	return (_pos); }

short Element::getHp()
{	return(_hp); }

void Element::setPos(t_coord newPos)
{	this->_pos = newPos; }

void Element::setHitbox(t_coord newHitbox)
{	this->_hitboxSize = newHitbox; }

void Element::setHp(short newHp)
{	this->_hp = newHp; }

void Element::decHp(short val)
{	this->_hp -= val; }

bool Element::isColision(char map[18][17])
{
	// on check les collisions par rapport a l'environnement uniquement
	// on determine dans quel partie de l'ecran on se trouve, et on renvoie la liste des cellules recouvertes par la hitbox
	short xCell;
	short yCell;

	xCell = this->_pos._posX / 16;
	yCell = this->_pos._posY / 18;

	if (map[yCell][xCell] != '0')
		return (true);
	if (this->_hitboxSize._posX != 0 || this->_hitboxSize._posY != 0)
	{
	// check de hitbox sur le rectangle
	}
	return (false);
}

Element::~Element(void)
{

}
