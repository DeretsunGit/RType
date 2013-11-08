#pragma once

#include <map>
#include <vector>
#include <string>
#include "ClientCommunication.hpp"
#include "Thread.h"
#include "TCPSocketClient.h"
#include "UDPSocketClient.h"

template<typename T>
T		      stringTo(const std::string& str)
{
  std::istringstream  stream(str);
  T		      sent;

  stream >> sent;
  return (sent);
}

class Debugger
{
public:
  Debugger(const char* host, unsigned short port);
  ~Debugger();

  void	start();

private:
  typedef std::vector<std::string>	Args;
  typedef void				(Debugger::*Sender)(const Args&);
  typedef std::map<std::string, Sender>	SenderMap;

  Thread			_th;
  TCPSocketClient		_tcp;
  UDPSocketClient*		_udp;
  bool				_live;
  ClientCommunication<Debugger>	_TCPcomm;
  ClientCommunication<Debugger>	_UDPcomm;
  SenderMap			_senders;

  void	networkThread();

  Debugger();
  Debugger(const Debugger&);
  Debugger& operator=(const Debugger&);

  void	defaultHandler(char opcode, IReadableSocket& sock);

  // TCP Handlers
  void	handleRoomList(void *);
  void	handleRoomState(void *);
  void	handleWrongMap(void *);
  void	handleStartLoading(void *);
  void	handleFileTrunk(void *);
  void	handleAssocSprites(void *);
  void	handleUDPOkay(void *);
  void	handleSendError(void *);

  // UDP Handlers
  void	handleScreenState(void *);
  void	handleEndOfGame(void *);

  // TCP Senders
  void	sendSayHello(const Args&);
  void	sendSetRoom(const Args&);
  void	sendSelectRoom(const Args&);
  void	sendLeaveRoom(const Args&);
  void	sendChangeDifficulty(const Args&);
  void	sendSetMap(const Args&);
  void	sendFileTrunk(const Args&);
  void	sendSetReady(const Args&);
  void	sendDownloadRsrc(const Args&);
  void	sendUDPReady(const Args&);
  void	sendLetsPlay(const Args&);
  void	sendSaveMap(const Args&);

  // UDP Senders
  void	sendInputs(const Args&);
};
