#include "Player.h"
#include "rtype_common.h"

Player::Player(Client* c, int id)
  : _client(c)
{
	// id et name defined where ?
	t_coord	temp;
	this->_ready =		false;
	this->_score =		0;
	this->_alive =		true;
	this->_isShooting = false;
	this->_shield =		LIGHT;
	this->setSpeed(8);

	temp._posX = 45;
	temp._posY = 25;
	this->setHitboxSize(&temp);
	temp._posX = 100;
	temp._posY = 450;
	this->setFaction(PLAYER);
	this->setPos(&temp);
	this->setHP(	3);
	this->setId(id);
	if (id == 1)
		this->addSprite(SHIP_BLUE_IDLE);
	if (id == 2)
		this->addSprite(SHIP_RED_IDLE);
	if (id == 3)
		this->addSprite(SHIP_GREEN_IDLE);
	if (id == 4)
		this->addSprite(SHIP_YELLOW_IDLE);
}

bool	Player::getIsShooting() const
{
	return(this->_isShooting);
}

bool	Player::getReady() const
{ return this->_ready; }

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

const std::string& Player::getName() const
{
	return this->_name;
}

Client	*Player::getClient() const
{
	return (this->_client);
}

Player::~Player()
{
}
