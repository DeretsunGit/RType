#include "PlayMenu.h"
#include "RoomButton.h"

PlayMenu::PlayMenu(sf::RenderWindow *window, SpriteManager *spritemgr, eMenus menu) : Menu(window, spritemgr, menu)
{
	Packet p;
	unsigned short res[2] = {1600, 900}; //recup via seufeumeul
	this->_size = 4;
	this->_buttons.resize(this->_size);
	this->_tcpsock = new TCPSocketClient("127.0.0.1", 1234);
	this->_comm.TCPsayHello(p, "ledp", res);
	this->_tcpsock->send(p);
	this->_buttons[0] = new RoomButton(this->_spritemgr, "LA ROOM 2 LA MOR");
	this->_buttons[1] = new RoomButton(this->_spritemgr, "[EASY][NO AWP][16000$]");
	this->_buttons[2] = new RoomButton(this->_spritemgr, "only fags");
	this->_buttons[3] = new RoomButton(this->_spritemgr, "give diretide");
	this->_comm.setHandler(this);
	this->_comm.setCallback(Opcodes::roomList, &Menu::parseRoomList);
	this->_comm.setDefaultCallback(&Menu::defaultCallback);
	this->_tcpsock;
}

void			PlayMenu::defaultCallback(char opcode, IReadableSocket& sock)
{
		std::cout << "default call bak" <<std::endl;
}

void			PlayMenu::parseRoomList(void *data)
{
	std::cout << "parseroomlist" <<std::endl;
	std::list<s_room_info>	*list = static_cast<std::list<s_room_info>*>(data);
}

void	PlayMenu::childAction()
{
		this->_comm.interpretCommand(*this->_tcpsock);
}

PlayMenu::~PlayMenu(void)
{
}
