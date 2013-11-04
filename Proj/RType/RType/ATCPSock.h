#pragma once

#include "Socket.h"
#include "IOBuff.h"

#define DATA_BUFSIZE 1024

class ATCPSock : public ASocket
{
private:

protected:
	IOBuff<> _buff;
public:
	virtual ~ATCPSock() {}

	virtual void send(char *buff, unsigned int size) = 0;
	virtual unsigned int recv(char *buff, unsigned int size) = 0;
};
