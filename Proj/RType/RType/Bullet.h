#pragma once

#include "Element.h"

class Bullet : public Element
{
private:
	int		_idWave;
public:
	Bullet();
	~Bullet();

	void	setIdWave(int);

	int		getIdWave() const;
};