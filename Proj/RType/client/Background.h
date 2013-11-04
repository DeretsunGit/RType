#pragma once
#include "drawable.h"
class Background :
	public Drawable
{
private:
	float		_pos;
public:
	Background(sf::Sprite);
	void		moveBackground(void);
	~Background(void);
};

