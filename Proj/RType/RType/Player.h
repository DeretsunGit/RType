#pragma once

#include <string>
//#include "UDPSocketServer.h"
#include "Element.h"
#include "Client.h"


class Player : public Element
{
	std::string		_name;
	int				_id;
	bool			_ready;
	int				_score;
	bool			_alive;
	bool			_shield;
	bool			_isShooting;
	Client *		_client;
//	UDPSocketServer*	_udpSock;
public:
	// Player(std::string, TCPSocket);
	Player();
	~Player();
	bool	getIsShooting() const;
	bool	getFile(std::string) const;
	bool	getReady() const;
	int		getId() const;
	int		getScore() const;
	bool	isAlive() const;
	bool	isWinner() const;
	bool	isDefeated() const;
	bool	getShield() const;

	void	setClient(Client *);
	void	setUDPsocket();
	void	setIsShooting(bool);
	void	setId(int);
	void	setScore(int);
	void	setReady(bool);
};