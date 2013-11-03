#pragma once

#include <string>
#include "rtype_common.h"

class Client
{
	std::string	_name;
	t_coord		resolution; // par defaut, le jeu sera en 1600 / 900
	// TCPSocket _tcpSocket;
public:
	Client();
	~Client();
};

