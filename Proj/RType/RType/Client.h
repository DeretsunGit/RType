#pragma once

#include <string>

class Client
{
	std::string	_name;
	int			resolution;
	// TCPSocket _tcpSocket;
public:
	Client();
	~Client();
};

