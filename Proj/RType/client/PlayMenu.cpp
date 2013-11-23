#include "PlayMenu.h"
#include "RoomButton.h"
#include "SystemException.h"
#include "ClientCommunication.cpp"
#include "CreateRoomButton.h"
#include "JoinRoomButton.h"
#include <sstream>


template class ClientCommunication<PlayMenu>;

PlayMenu::PlayMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	Packet			p;
	unsigned short	res[2] = {1600, 900};

	
	this->_set = new SettingsParser("assets/settings.ini");
	this->_tcp_success = true;
	this->_size = 0;
	this->_buttons.resize(this->_size);
	this->_spritemgr = spritemgr;
	this->_comm.setHandler(this);
	this->_comm.setCallback(Opcodes::roomList, &PlayMenu::parseRoomList);
//	this->_comm.setCallback(Opcodes::startLoading, &PlayMenu::handleStartLoading);
	this->_comm.setDefaultCallback(&PlayMenu::defaultCallback);
	try
	{
		std::istringstream buffer(this->_set->getPort());
		short port;
		buffer >> port;
		this->_tcpsock = new TCPSocketClient(this->_set->getServer().c_str(), port);
	}
	catch (SystemException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_tcp_success = false;

	}
	if (this->_tcp_success)
	{
		this->_comm.TCPsayHello(p, this->_set->getNick().c_str(), res);
		this->_tcpsock->send(p);
	}
}

bool			PlayMenu::getTcpSuccess(void) const
{
	return this->_tcp_success;
}

void			PlayMenu::defaultCallback(unsigned int opcode, IReadableSocket& sock)
{
	//std::cout << "default callbak opcode :" << (int)opcode << std::endl;
}

void			PlayMenu::parseRoomList(void *data)
{
	std::list<s_room_info>	*list = static_cast<std::list<s_room_info>*>(data);

	this->_size = 2;
	this->_buttons.resize(this->_size);
	this->_buttons[0] = new CreateRoomButton(this->_spritemgr, this->_tcpsock);
	this->_buttons[1] = new JoinRoomButton(this->_spritemgr, this->_tcpsock, *list);
}

void	PlayMenu::childAction()
{
	if (this->_tcp_success && this->_size == 0)
	{
		this->_comm.interpretCommand(*this->_tcpsock);
	}
}

PlayMenu::~PlayMenu(void)
{
}
