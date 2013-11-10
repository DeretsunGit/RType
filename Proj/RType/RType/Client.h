#pragma once

#include <string>
#include "TCPSocketClient.h"
#include "rtype_common.h"

class Client
{
	bool				_toDelete;
	const int			_id;
	bool				_isWaiting;
	t_coord				_resolution;
	std::string*		_name; // limite a 32
	ITCPSocketClient*	_tcpSocket;
public:
	Client(ITCPSocketClient*, int id);
	~Client();


	void		setDelete(bool);
	void		setWaiting(bool);
	void		setResolution(short int, short int);
	void		setName(char *);

	bool		getDelete() const;
	t_coord		getResolution() const;
	int			getId() const;
	bool		getWaiting() const;
	ITCPSocketClient*	getTCPSock();

};

