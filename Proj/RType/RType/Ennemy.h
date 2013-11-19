#pragma once

# include "Element.h"
# include "Bullet.h"
# include <map>

class Ennemy : public Element
{
private:
	unsigned short				_powerShoot;
public:
	Ennemy(int, t_coord, std::list<eSprites>);
	~Ennemy();

	void setShipAttributes();
	void setBullet(std::list<Bullet*> &);
};