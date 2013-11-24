#include <iostream>
#include "RoomMenu.h"
#include "RoomButton.h"
#include "SystemException.h"
#include "ClientCommunication.cpp"
#include "CreateRoomButton.h"
#include "JoinRoomButton.h"

template class ClientCommunication<RoomMenu>;

RoomMenu::RoomMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	Packet			p;
	unsigned short	res[2] = {1600, 900};
	
	this->_tcp_success = true;
	this->_size = 0;
	this->_buttons.resize(this->_size);
	this->_spritemgr = spritemgr;
	this->_comm.setHandler(this);
	this->_comm.setCallback(Opcodes::roomList, &RoomMenu::parseRoomList);
//	this->_comm.setCallback(Opcodes::startLoading, &RoomMenu::handleStartLoading);
	this->_comm.setDefaultCallback(&RoomMenu::defaultCallback);
	try
	{
		this->_tcpsock = new TCPSocketClient("127.0.0.1", 1234);
	}
	catch (SystemException &e)
	{
		std::cout << e.what() << std::endl;
		static_cast<void>(e);
		this->_tcp_success = false;
	}
	if (this->_tcp_success)
	{
		this->_comm.TCPsayHello(p, "ledp", res);
		this->_tcpsock->send(p);
	}
}

void			RoomMenu::defaultCallback(char, IReadableSocket& sock)
{
	//std::cout << "default callbak opcode :" << (int)opcode << std::endl;
}

void			RoomMenu::parseRoomList(void *data)
{
	int	i = 0;
	std::list<s_room_info>	*list = static_cast<std::list<s_room_info>*>(data);

	this->_size = 2;
	this->_buttons.resize(this->_size);
	this->_buttons[0] = new CreateRoomButton(this->_spritemgr, this->_tcpsock);
	this->_buttons[1] = new JoinRoomButton(this->_spritemgr, this->_tcpsock, *list);
	

}

void	RoomMenu::childAction()
{
	if (this->_tcp_success && this->_size == 0)
	{
		this->_comm.interpretCommand(*this->_tcpsock);
	}
}

RoomMenu::~RoomMenu(void)
{
}
