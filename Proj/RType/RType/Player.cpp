#pragma message ("KUKU")
#include "Player.h"
#pragma message ("KOUKOU")
#include "rtype_common.h"

Player::Player()
{
	t_coord	temp;

	temp._posX = 50;
	temp._posY = 30;
	this->setFaction(PLAYER);
	this->setHitboxSize(temp);
	temp._posX = 100;
	temp._posY = 450;
	this->setPos(temp);
}

bool	Player::getIsShooting() const
{
	return(this->_isShooting);
}

bool	Player::getReady() const
{ return this->_ready; }

int		Player::getId() const
{ return this->_id; }

int		Player::getScore() const
{ return this->_score; }

bool	Player::isAlive() const
{
	return this->_alive;
}

bool	Player::isWinner() const
{
	return false;
}

bool	Player::isDefeated() const
{
	return false;
}

bool	Player::getShield() const
{
	return (this->_shield);
}

void	Player::setReady(bool ready)
{
	this->_ready = ready;
}

void	Player::setIsShooting(bool shooting)
{
	this->_isShooting = shooting;
}

void	Player::setClient(Client *newClient)
{
	this->_client = newClient;
}

void	Player::setUDPsocket()
{
//	this->_udpSock
	//	UTCPSocketServer(port = 0)
	//methode getport qui retourne le port reelement utilisé
}

Player::~Player()
{
}
