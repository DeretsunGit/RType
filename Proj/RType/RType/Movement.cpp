#include "Movement.h"

Movement::Movement()
{

}

Movement::~Movement()
{

}

void	Movement::genericMove(MoveTypes mt, Element *elem, short int mult = 1, short int y = 0)
{
	if (mt = PlayerMove)
		playerMove(elem, mult, y);
	if (mt = Linear)
		linearMove(elem, mult);
	else
	{
		std::cout << "This Movement is not yet implemented" << std::endl;
		return;
	}
	elem->checkCell();
}

void Movement::linearMove(Element *elem, short int mult)
{
	this->_temp._posX = (elem->getPos()._posX - elem->getSpeed() * mult);
	this->_temp._posY = elem->getPos()._posY;
	elem->setPos(&(this->_temp));
}

void Movement::playerMove(Element *elem, short int x, short int y)
{
// 0->rien 2->haut/arriere 1->bas/avant
	std::cout << "//////////////////////////" << std::endl;
	if (x == 1)
		this->_temp._posX = (elem->getPos()._posX + elem->getSpeed());
	else if (x == 2)
		this->_temp._posX = (elem->getPos()._posX - elem->getSpeed());

	if (y == 1)
		this->_temp._posY = (elem->getPos()._posY + elem->getSpeed());
	else if (y == 2)
		this->_temp._posY = (elem->getPos()._posY - elem->getSpeed());
	
	elem->setPos(&(this->_temp));
}