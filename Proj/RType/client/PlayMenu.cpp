#include "PlayMenu.h"
#include "RoomButton.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<PlayMenu>;

PlayMenu::PlayMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	Packet p;
	unsigned short res[2] = {1600, 900};
	this->_size = 0;
	this->_buttons.resize(0);
	this->_comm.setHandler(this);
	this->_comm.setCallback(Opcodes::roomList, &PlayMenu::parseRoomList);
	this->_comm.setDefaultCallback(&PlayMenu::defaultCallback);
	this->_tcpsock = new TCPSocketClient("127.0.0.1", 1234);
	this->_comm.TCPsayHello(p, "ledp", res);
	this->_tcpsock->send(p);
}

void			PlayMenu::defaultCallback(char opcode, IReadableSocket& sock)
{
	std::cout << "default callbak opcode :" << (int)opcode << std::endl;
}

void			PlayMenu::parseRoomList(void *data)
{
	int	i = 0;
	std::cout << "parseroomlist" <<std::endl;
	std::list<s_room_info>	*list = static_cast<std::list<s_room_info>*>(data);
	this->_size = list->size();
	this->_buttons.resize(this->_size);
	std::cout << "list size = " << this->_size << std::endl;
	for (std::list<s_room_info>::iterator it = list->begin(); it != list->end(); it++)
	{
		this->_buttons[i] = new RoomButton(this->_spritemgr, "TkhTo");
		i = i + 1;
	}	
}

void	PlayMenu::childAction()
{
	this->_comm.interpretCommand(*this->_tcpsock);
}

PlayMenu::~PlayMenu(void)
{
}
