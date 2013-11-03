#pragma once



#include <string>
#include "Element.h"
#include "Client.h"

class Player : public Element, public Client
{
	std::string		_name;
	int				_id;
	bool			_ready;
	int				_score;
	// TCPSocket		_tcpSock;
	// UDPSocket		_udpSock;

public:
	// Player(std::string, TCPSocket);
	Player();
	~Player();

	bool	getFile(std::string);
	bool	getReady();
	int		getId();
	int		getScore();

	void	setId(int);
	void	setScore(int);
	void	setReady(bool);

	void	move();
	void	incScore(int);
};