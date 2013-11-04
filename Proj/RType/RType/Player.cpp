#include "Player.h"

Player::Player()
{
}

bool	Player::getReady()
{ return this->_ready; }

int		Player::getId()
{ return this->_id; }

int		Player::getScore()
{ return this->_score; }

void	Player::setReady(bool ready)
{
	this->_ready = ready;
}

Player::~Player()
{
}
