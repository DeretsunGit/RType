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
{	this->_ready = ready; }

void	Player::setScore(int n)
{	this->_score = n; }

void	Player::incScore(int n)
{	this->_score += n; }


void	Player::move()
{
	// on check si _players[i] a ecrit dans le buffer.
	//si oui, on check le dernier message envoyé et on le fait se deplacer/tirer.
}

Player::~Player()
{
}
