#pragma once

#include <string>
#include "TCPSocketClient.h"

class Client
{
//	std::string	_name;
	// t_coord resolution;
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

