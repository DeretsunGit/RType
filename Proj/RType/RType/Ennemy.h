#pragma once

# include "Element.h"
# include "Bullet.h"
# include <map>

class Ennemy : public Element
{
private:
	int							_idWave;
	unsigned short				_powerShoot;
public:
	Ennemy(int);
	~Ennemy();

	void	setBullet(std::list<Bullet*> &);
	void	setIdWave(int);

	int		getIdWave();
};