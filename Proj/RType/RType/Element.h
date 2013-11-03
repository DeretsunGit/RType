#pragma once

#include "rtype_common.h"

class Element
{
	short	_hp;
	short	_speed;
	char	_id;
	char	_skinId;

	t_coord	_pos; // la position du centre de l'element
	t_coord	_hitboxSize; // la taille de la hitbox, centrée sur le _pos
	t_coord	_spritePos; // le décalage par rapport a _pos pour l'affichage du skin

public:
	Element();
	~Element();


	t_coord getPos();
	short	getHp();
	
	void	setPos(t_coord);
	void	setHitbox(t_coord);
	void	setHp(short);
	void	decHp(short);

	bool	isColision(char map[18][17]);
	bool	move();
};