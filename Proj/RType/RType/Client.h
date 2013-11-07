#pragma once

#include <string>
#include "TCPSocketClient.h"
#include "rtype_common.h"

class Client
{
	std::string	_name; // limite a 32
	t_coord resolution;
	bool _isWaiting;
	const int		_id;
	ITCPSocketClient*	_tcpSocket;
public:
	Client(ITCPSocketClient*, int id);
	ITCPSocketClient *getTCPSock();

	void setWaiting(bool);

	int getId();
	bool getWaiting();

	~Client();
};

