#pragma once

#include "Socket.h"

class AUDPSocketClient : public ISocket
{
public:
	virtual ~AUDPSocketClient() {}

	virtual unsigned int	recv(char* buff, unsigned int size) = 0;
	virtual void		send(char* buff, unsigned int size) = 0;
};