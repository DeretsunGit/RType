#pragma once

#include "rtype_common.h"

class Element
{
	t_coord	_pos; // point en haut a gauche
	t_coord	_hitboxSize;
	t_coord	_spritePos;
	t_coord	_center;
	char	_spriteId;
	int		_hp;
public:
	Element();
	~Element();

	void	setHP(int);

	t_coord	getPos() const;
	t_coord getHitboxSize() const;
	char	getSpriteId() const;
	int		getHP() const;
	void	move();

	bool isColision(std::list<Element*>);
};