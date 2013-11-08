#pragma once

#include <string>
#include "TCPSocketClient.h"
#include "rtype_common.h"

class Client
{
	const int			_id;
	bool				_isWaiting;
	t_coord				_resolution;
	std::string*		_name; // limite a 32
	ITCPSocketClient*	_tcpSocket;
public:
	Client(ITCPSocketClient*, int id);
	~Client();

	void		setWaiting(bool);

	int			getId();
	bool		getWaiting();
	ITCPSocketClient*	getTCPSock();

};

