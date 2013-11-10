#pragma once

#include <string>
#include "UDPSocketServer.h"
#include "Element.h"
#include "Client.h"
#include "rtype_common.h"


class Player : public Element
{
	std::string		_name;
	bool			_ready;
	int				_score;
	bool			_alive;
	bool			_shield;
	bool			_isShooting;
	Client *		_client;
	
public:
	// Player(std::string, TCPSocket);
	//Player();
	Player(Client* c, int);
	~Player();
	bool	getIsShooting() const;
	bool	getFile(std::string) const;
	bool	getReady() const;
	int		getScore() const;
	bool	isAlive() const;
	bool	isWinner() const;
	bool	isDefeated() const;
	bool	getShield() const;
	const std::string& getName() const;
	Client	*getClient() const;

	void	setClient(Client *);
	void	setIsShooting(bool);
	void	setScore(int);
	void	setReady(bool);
};