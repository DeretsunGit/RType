#pragma once

#include <vector>
#include "Thread.h"
#include "Mutex.h"
#include "Player.h"
#include "ServerCommunication.hpp"
#include "Script.h"
#include "Game.h"

//template<typename T>
//class ServerCommunication;

class Room
{
private:
	const char	_id;
	char		_nbReady;
	char		_difficulty;
	std::string	_name; //limite 32
	std::string	*_map; //limite 128
	std::vector<Player*> _party; //-
	unsigned short int	_port;
	UDPSocketServer*	_udpSock;


	Client *	_currentClient;
	Script *	_script;
	Game *		_game;
	
	Thread*		_th;
	Mutex		_m;
	ServerCommunication<Room>	_RoomCom;
	Packet		_pack;

public:
	Room(char, std::vector<t_pattern>);
	~Room();

	void	prepareRoom();
	void	roomLoop();
	bool	startGame();

	// callBack Gestion
	void	leaveRoom(void *);
	void	changeDifficulty(void *);
	void	setMap(void *);
	void	getFileTrunk(void *);
	void	setReady(void *);
	void	downloadRessource(void *);
	void	UDPReady(void *);
	void	letsPlay(void *);
	void	saveMap(void *);
	void	callBackError(unsigned int, IReadableSocket&);

	void	startLoading();

	// send gestion
	void	sendWrongMap();
	void	sendStartLoading();
	void	sendUDPok();
	void	sendError(char, const char *);

	// Client Gestion
	bool	addClient(Client*);
	bool	addPlayer(Player*);
	bool	removePlayer(int);
	bool	removeClient(int);
	int		validId();

	char	getDifficulty() const;
	char	getId() const;
	char	getNbPlayer() const;
	bool	getMapStatus() const;
	Thread	*getThread();
	const std::string&		getName() const;
	const std::string&		getMap() const;
	const std::vector<Player*>&		getPlayers() const;

	void	setName(const char *);

	//Packet* TCPsendRoomList(const std::list<Room>& rooms) const;
};
