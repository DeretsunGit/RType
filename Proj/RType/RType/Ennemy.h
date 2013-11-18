#pragma once

# include "Element.h"
# include "Bullet.h"
# include <map>

class Ennemy : public Element
{
private:
	std::map<int, std::string>	_skins;
	unsigned short				_powerShoot;
public:
	Ennemy(int, char); // id, color
	~Ennemy();

	void setShipAttributes();
	void setBullet(std::list<Bullet*> &);
};