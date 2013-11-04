#pragma once

#include <string>
#include "Element.h"

class Player : public Element
{
	std::string		_name;
	int				_id;
	bool			_ready;
	int				_score;
	bool			_alive;
	bool			_shield;
	// TCPSocket		_tcpSock;
	// UDPSocket		_udpSock;
public:
	// Player(std::string, TCPSocket);
	Player();
	~Player();

	bool	getFile(std::string) const;
	bool	getReady() const;
	int		getId() const;
	int		getScore() const;
	bool	isAlive() const;
	bool	isWinner() const;
	bool	isDefeated() const;
	bool	getShield() const;

	void	setId(int);
	void	setScore(int);
	void	setReady(bool);
};