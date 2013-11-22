#pragma once
#include "Element.h"

enum MoveTypes
{
	Player,
	Linear
};

class Movement
{
	t_coord	_temp;
	void	playerMove(Element *, short int, short int);
	void	linearMove(Element *, short int);
public:
	Movement();
	~Movement();

	void	genericMove(MoveTypes, Element *, short int, short int);
};