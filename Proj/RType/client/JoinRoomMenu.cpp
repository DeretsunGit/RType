#include "JoinRoomMenu.h"
#include "RoomButton.h"
#include "SystemException.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<JoinRoomMenu>;

JoinRoomMenu::JoinRoomMenu(sf::RenderWindow *window, SpriteManager *spritemgr, TCPSocketClient *socket, std::list<s_room_info> *list) : Menu(window, spritemgr)
{
	int	i = 0;

	this->_size = list->size();
	this->_buttons.resize(this->_size);

	for (std::list<s_room_info>::iterator it = list->begin(); it != list->end(); it++)
	{
		this->_buttons[i] = new RoomButton(this->_spritemgr, it->name, socket, it->id);
		i = i + 1;
	}
}

JoinRoomMenu::~JoinRoomMenu(void)
{
}
