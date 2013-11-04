#pragma once

#include "rtype_common.h"

class Element
{
	t_coord	_pos;
	t_coord	_hitboxSize;
	t_coord	_spritePos;
	t_coord	_center;
	char	_spriteId;
public:
	Element();
	~Element();

	t_coord	getPos() const;
	char	getSpriteId() const;
	void	move();
};