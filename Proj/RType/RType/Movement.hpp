#pragma once
#include "Element.h"

enum MoveTypes
{
	PlayerMove,
	Linear
};

class Movement
{
	t_coord	_temp;

	void linearMove(Element *elem, short int mult)
	{
		this->_temp._posX = (elem->getPos()._posX - elem->getSpeed() * mult);
		this->_temp._posY = elem->getPos()._posY;
		elem->setPos(&(this->_temp));
	}

	void playerMove(Element *elem, short int x, short int y)
	{
		// 0->rien 2->haut/arriere 1->bas/avant
		//	std::cout << "x->" << x << ", y->" << y << std::endl;
		this->_temp._posX = elem->getPos()._posX;
		this->_temp._posY = elem->getPos()._posY;

		if (x == 1)
			this->_temp._posX = (elem->getPos()._posX + elem->getSpeed());
		else if (x == 2)
			this->_temp._posX = (elem->getPos()._posX - elem->getSpeed());

		if (y == 1)
			this->_temp._posY = (elem->getPos()._posY + elem->getSpeed());
		else if (y == 2)
			this->_temp._posY = (elem->getPos()._posY - elem->getSpeed());

		if (x != 0 || y != 0)
		{
			if (this->_temp._posX < 0)
				this->_temp._posX = 0;
			if (this->_temp._posX > 1500)
				this->_temp._posX = 1500;
			if (this->_temp._posY < 0)
				this->_temp._posY = 0;
			if (this->_temp._posY > 850)
				this->_temp._posY = 850;
			elem->setPos(&(this->_temp));
		}
	}
public:
	Movement()
	{

	}
	~Movement()
	{

	}

	void	genericMove(MoveTypes mt, Element *elem, short int mult = 1, short int y = 0)
	{
		if (mt == PlayerMove)
			this->playerMove(elem, mult, y);
		else if (mt == Linear)
			this->linearMove(elem, mult);
		else
		{
			std::cout << "This Movement is not yet implemented" << std::endl;
			return;
		}
		elem->checkCell();
	}
};