#include "RTypeServer.h"

RTypeServer::RTypeServer(int port, int maxRoom, std::string blPath)/* : _port(port), _maxRoom(maxRoom)
*/{
	// convertir le blPath en ofstream
}

bool	RTypeServer::start()
{
	ITCPSocketClient*	newClient;
	// création du prompt
	// load des librairies dynamiques

	// gestion socket
	while (42)
	{
		if ((newClient = this->_TCPsocket->accept()) != NULL)
		{
			this->_waitingList.push_back(new Client(newClient));
		}
		if (this->_waitingList.size() == 2)
		{
			this->createRoom();
		}
	}
	return (1);
}

void RTypeServer::createRoom()
{
	//Thread* newThread;
	Room newRoom;

	newRoom.addClient(_waitingList.front());
	newRoom.addClient(_waitingList.back());
	_waitingList.empty();
	newRoom.roomLoop();
}

bool	RTypeServer::loadDynEnnemy(std::string filename)
{
	return (1);
}

RTypeServer::~RTypeServer()
{
	// quitter tous les clients proprement
}

