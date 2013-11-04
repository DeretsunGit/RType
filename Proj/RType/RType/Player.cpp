#include "Player.h"

Player::Player()
{
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

Player::~Player()
{
}
