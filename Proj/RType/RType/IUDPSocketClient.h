#pragma once

#include "Socket.h"

class IUDPSocketClient : public ISocket
{
public:
	virtual ~IUDPSocketClient() {}

	virtual unsigned int	recv(char* buff, unsigned int size) = 0;
	virtual void		send(char* buff, unsigned int size) = 0;
};