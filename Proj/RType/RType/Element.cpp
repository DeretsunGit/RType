#include "Element.h"

Element::Element()
{
	this->_shipProof	 =		false;
	this->_bulletProof =		false;
	this->_hp =				0;
	this->_sendPriority =	1;
	this->_speed =			1;
	this->_id =				0;
	this->_spriteId =		0;
}

Element::~Element()
{
}

bool	Element::isCollision(Element* elem)
{
	if ((this->getFaction() != elem->getFaction()))
	{
/*		std::cout << "x->" << this->_pos._posX << "/"<< elem->getPos()._posX << "--"
		 << "y->" << this->_pos._posY << "/"<< elem->getPos()._posY << std::endl;
		 */
		if ((this->_pos._posX < (elem->getPos())._posX &&
			this->_pos._posX + this->_hitboxSize._posX > (elem->getPos())._posX) ||
			(this->_pos._posX < (elem->getPos())._posX + (elem->getHitboxSize())._posX &&
			this->_pos._posX + this->_hitboxSize._posX > (elem->getPos())._posX  + (elem->getHitboxSize())._posX))
		{
			if ((this->_pos._posY < (elem->getPos())._posY &&
				this->_pos._posY + this->_hitboxSize._posY > (elem->getPos())._posY) ||
				(this->_pos._posY < (elem->getPos())._posY + (elem->getHitboxSize())._posY &&
				this->_pos._posY + this->_hitboxSize._posY > (elem->getPos())._posY  + (elem->getHitboxSize())._posY))
			{
				return (true);
			}
		}
	}
	return (false);
}

void	Element::checkCell()
{
	t_coord		temp;

	this->_isToUp = false;
	temp._posX = this->_pos._posX / 100;
	temp._posY = this->_pos._posY / 50;
	// si il ya changement de case
	if (temp._posX != this->_cellPosTL._posX || temp._posY != this->_cellPosTL._posY)
	{
		this->cleanCurrentCell();
		setCell(temp);
	}

	temp._posX = (this->_pos._posX + this->_hitboxSize._posX) / 100;
	temp._posY = (this->_pos._posY + this->_hitboxSize._posY) / 50;
	// si il ya  changement de case
	if (temp._posX != this->_cellPosBR._posX || temp._posY != this->_cellPosBR._posY)
	{
		this->cleanCurrentCell();
		setCell(temp);
	}
}

void Element::setCell(t_coord temp)
{
	this->_isToUp = true;
	this->_cellPosTL._posX = this->_pos._posX / 100;
	this->_cellPosTL._posY = this->_pos._posY / 100;
	this->addToCurrentCell(this->_cellPosTL);
	this->_cellPosBR._posX = (this->_pos._posX + this->_hitboxSize._posX) / 100;
	this->_cellPosBR._posY = (this->_pos._posY + this->_hitboxSize._posY) / 50;
	this->addToCurrentCell(this->_cellPosBR);

	if (this->_cellPosTL._posX != this->_cellPosBR._posX &&
		this->_cellPosTL._posY != this->_cellPosBR._posY)
	{
		temp._posX = this->_pos._posX / 100;
		temp._posY = (this->_pos._posY + this->_hitboxSize._posY) / 50;
		this->addToCurrentCell(temp);
		temp._posX = (this->_pos._posX + this->_hitboxSize._posX) / 100;
		temp._posY = this->_pos._posY / 50;
		this->addToCurrentCell(temp);
	}
}

void	Element::addToCurrentCell(t_coord coord)
{
	this->_currentCells.push_back(coord);
}

void	Element::cleanCurrentCell()
{
	this->_currentCells.clear();
}

void	Element::setSpeed(short int newSpeed)
{
	this->_speed = newSpeed;
}

void	Element::setHP(int hp)
{
	this->_hp = hp;
}

void	Element::setHitboxSize(t_coord *newHitbox)
{
	this->_hitboxSize = *newHitbox;
}

void	Element::setId(int id)
{
this->_id = id;
}

void	Element::setFaction(char faction)
{
	this->_faction = faction;
}

void	Element::setBulletProof(bool b)
{
	this->_bulletProof = b;
}

void	Element::setShipProof(bool b)
{
	this->_shipProof = b;
}

void	Element::setSendPriority(char newPriority)
{
	this->_sendPriority = newPriority;
}

void	Element::setPos(const t_coord *newCoord)
{
	this->_pos._posX = newCoord->_posX;
	this->_pos._posY = newCoord->_posY;
}

void		Element::setColor(char color)
{
	this->_color = color;
}

void		Element::setSide(bool side)
{
	this->_side = side;
}

void		Element::setSprite(std::list<eSprites> sprites)
{
	this->_sprites = sprites;
}

void		Element::addSprite(eSprites newsprite)
{
	this->_sprites.push_front(newsprite);
}

const t_coord&	Element::getPos() const
{
	return (this->_pos);
}

const t_coord&	Element::getHitboxSize() const
{
	return (this->_hitboxSize);
}

char	Element::getSpriteId() const
{
	return (this->_spriteId);
}

int		Element::getHP() const
{
	return (this->_hp);
}

int		Element::getId() const
{
	return (this->_id);
}

bool	Element::getBulletProof() const
{
return (this->_bulletProof);
}

bool	Element::getShipProof() const
{
return (this->_shipProof);
}

char	Element::getFaction() const
{
return (this->_faction);
}

std::vector<t_coord>	Element::getCurrentCell() const
{
	return (this->_currentCells);
}

char	Element::getSendPriority() const
{
	return (this->_sendPriority);
}

short int	Element::getSpeed() const
{
	return(this->_speed);
}

char		Element::getColor() const
{
	return (this->_color);
}

bool		Element::getSide() const
{
	return (this->_side);
}

std::list<eSprites>	Element::getSprite() const
{
	return (this->_sprites);
}
