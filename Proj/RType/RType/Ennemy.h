#pragma once

# include "Element.h"
# include <map>

class Ennemy : public Element
{
private:
	std::map<int, std::string>	_skins;
public:
	Ennemy(int);
	~Ennemy();

	void setShipAttributes();
	void setBullet();
};