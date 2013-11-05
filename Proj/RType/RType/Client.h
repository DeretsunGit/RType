#pragma once

#include <string>
#include "TCPSocketClient.h"

class Client
{
//	std::string	_name;
	ITCPSocketClient* _tcpSocket;
public:
	Client();
	Client(ITCPSocketClient*);
	~Client();
};

