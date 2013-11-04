#pragma once

#include "rtype_common.h"

class Element
{
	t_coord	_pos;
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
	char	getSpriteId() const;
	int		getHP() const;
	void	move();
};