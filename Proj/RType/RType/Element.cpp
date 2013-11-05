#include "Element.h"

Element::Element()
{
	this->_shipProof	 =		false;
	this->_bulletProof =		false;
	this->_hp =				1;
	this->_sendPriority =	1;
	this->_speed =			1;
}

Element::~Element()
{
}

int Element::isCollision(std::list<Element*> cell)
{
	// check uniquement pour les joueurs et les bullet du joueur et les murs
	std::list<Element*>::iterator it;
	// on check les collisions par rapport a l'environnement uniquement
	// on determine dans quel partie de l'ecran on se trouve, et on renvoie la liste des cellules recouvertes par la hitbox
	it = cell.begin();
	while (it != cell.end())
	{
		if ((this->getFaction() != (*it)->getFaction()))
		{
			if ((this->_pos._posX < ((*it)->getPos())._posX &&
				this->_pos._posX + this->_hitboxSize._posX > ((*it)->getPos())._posX) ||
				(this->_pos._posX < ((*it)->getPos())._posX + ((*it)->getHitboxSize())._posX &&
				this->_pos._posX + this->_hitboxSize._posX > ((*it)->getPos())._posX  + ((*it)->getHitboxSize())._posX))
			{
					if ((this->_pos._posY < ((*it)->getPos())._posY &&
					this->_pos._posY + this->_hitboxSize._posY > ((*it)->getPos())._posY) ||
					(this->_pos._posY < ((*it)->getPos())._posY + ((*it)->getHitboxSize())._posY &&
					this->_pos._posY + this->_hitboxSize._posY > ((*it)->getPos())._posY  + ((*it)->getHitboxSize())._posY))
					{
						return ((*it)->getId());
					}
			}
		}
		it ++;
	}
	return (-1);
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

void	Element::setHitboxSize(t_coord newHitbox)
{
	this->_hitboxSize = newHitbox;
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

void	Element::setPos(t_coord newCoord)
{
	this->_pos = newCoord;
}

t_coord	Element::getPos() const
{
	return (this->_pos);
}

t_coord	Element::getHitboxSize() const
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
