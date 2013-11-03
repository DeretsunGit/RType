#pragma once

class Element
{
	short	_pos[2];
	short	_hitboxSize[2];
	short	_spritePos[2];
	short	_center[2];
public:
	Element();
	~Element();

	void	move();
};