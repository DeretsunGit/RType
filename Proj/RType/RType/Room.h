#pragma once

#include <vector>
#include "Thread.h"
#include "Mutex.h"
#include "Player.h"
#include "ServerCommunication.hpp"

//template<typename T>
//class ServerCommunication;

class Room
{
private:
	const char	_id;
	bool		_isRandom;
	char		_nbReady;
	char		_difficulty;
	std::string	*_name; //limite 32
	std::string	*_map; //limite 128
	std::vector<Player*> _party;

	Client *	_currentClient;

	Thread*		_th;
	Mutex		_m;
	ServerCommunication<Room>	_RoomCom;
	Packet		_pack;

public:
	Room(char);
	~Room();

	void	roomLoop();
	bool	startGame();

	// callBack Gestion
	void	leaveRoom(void *);
	void	changeDifficulty(void *);
	void	setMap(void *);
	void	getFileTrunk(void *);
	void	setReady(void *);
	void	downloadRessource(void *);
	void	ready(void *);
	void	letsPlay(void *);
	void	saveMap(void *);
	void	callBackError(char, IReadableSocket&);

	// send gestion
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
	const std::string& getMap() const;
	bool	getMapStatus() const;
	const std::string&	getName() const;
	const std::vector<Player*>& getPlayers() const;

	bool	setName(const char *);

	//Packet* TCPsendRoomList(const std::list<Room>& rooms) const;
};
