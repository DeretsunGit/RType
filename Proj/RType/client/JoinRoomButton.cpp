#include "JoinRoomButton.h"
#include "JoinRoomMenu.h"
#include "ClientCommunication.cpp"
#include "GameLoop.h"

template class ClientCommunication<JoinRoomButton>;

JoinRoomButton::JoinRoomButton(SpriteManager *sprmgr, TCPSocketClient *tcpsock, std::list<s_room_info> list)
{
	this->setSprite(sprmgr->getSpritebyId(JOIN_ROOM));
	this->setSpriteOn(sprmgr->getSpritebyId(JOIN_ROOM_ON));
	this->_sett = new SettingsParser("assets/settings.ini");
	//this->_comm.setHandler(this);
	this->_roomname = "New Room";
	this->_tcpsock = tcpsock;
	this->_list = list;
	this->_sprmgr = sprmgr;
}

void	JoinRoomButton::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{
	JoinRoomMenu	menu(window, this->_sprmgr, this->_tcpsock, &this->_list);

	menu.menuLoop();
}

JoinRoomButton::~JoinRoomButton(void)
{
}
