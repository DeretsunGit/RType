#include <iostream>
#include <sstream>
#include <fstream>
#include "Debugger.h"
#include "Opcodes.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<Debugger>;

Debugger::Debugger(const char* hostname, unsigned short port)
  : _th(*this, &Debugger::networkThread), _tcp(hostname, port), _udp(NULL), _live(true)
{
  this->_TCPcomm.setHandler(this);
  this->_TCPcomm.setDefaultCallback(&Debugger::defaultHandler);
  this->_UDPcomm.setHandler(this);
  this->_UDPcomm.setDefaultCallback(&Debugger::defaultHandler);

  // set TCP callback
  _TCPcomm.setCallback(Opcodes::roomList, &Debugger::handleRoomList);
  _TCPcomm.setCallback(Opcodes::roomState, &Debugger::handleRoomState);
  _TCPcomm.setCallback(Opcodes::wrongMap, &Debugger::handleWrongMap);
  _TCPcomm.setCallback(Opcodes::startLoading, &Debugger::handleStartLoading);
  _TCPcomm.setCallback(Opcodes::fileTrunk, &Debugger::handleFileTrunk);
  _TCPcomm.setCallback(Opcodes::assocSprite, &Debugger::handleAssocSprites);
  _TCPcomm.setCallback(Opcodes::UDPOkay, &Debugger::handleUDPOkay);
  _TCPcomm.setCallback(Opcodes::sendError, &Debugger::handleSendError);

  // set UDP callback
  _UDPcomm.setCallback(Opcodes::screenState, &Debugger::handleScreenState);
  _UDPcomm.setCallback(Opcodes::endOfGame, &Debugger::handleEndOfGame);


  // set TCP senders
  _senders["sayHello"] = &Debugger::sendSayHello;
  _senders["setRoom"] = &Debugger::sendSetRoom;
  _senders["selectRoom"] = &Debugger::sendSelectRoom;
  _senders["leaveRoom"] = &Debugger::sendLeaveRoom;
  _senders["changeDifficulty"] = &Debugger::sendChangeDifficulty;
  _senders["setMap"] = &Debugger::sendSetMap;
  _senders["fileTrunk"] = &Debugger::sendFileTrunk;
  _senders["setReady"] = &Debugger::sendSetReady;
  _senders["downloadRsrc"] = &Debugger::sendDownloadRsrc;
  _senders["UDPReady"] = &Debugger::sendUDPReady;
  _senders["letsPlay"] = &Debugger::sendLetsPlay;
  _senders["saveMap"] = &Debugger::sendSaveMap;

  // set UDP senders
  _senders["inputs"] = &Debugger::sendInputs;
}

Debugger::~Debugger()
{
  this->_live = false;
  this->_th.join();
}

void			Debugger::start()
{
  std::string		line;
  SenderMap::iterator	it;
  SenderMap::iterator	end(this->_senders.end());

  this->_th.start();
  while (std::getline(std::cin, line) && this->_tcp.isLive())
  {
    std::istringstream	input(line);
    Args		args;

    while (std::getline(input, line, ' '))
      if (!line.empty())
	args.push_back(line);
    // TO REMOVE
    // {
    //   std::cout << "Args: ";
    //   for (Args::iterator it = args.begin(); it != args.end(); ++it)
    // 	{
    // 	  if (it != args.begin())
    // 	    std::cout << ", ";
    // 	  std::cout << '[' << *it << ']';
    // 	}
    //   std::cout << std::endl;
    // }
    if (!args.empty() && (it = this->_senders.find(args[0])) != end)
      (this->*it->second)(args);
  }
}

void	      Debugger::networkThread()
{
  while (this->_live && this->_tcp.isLive())
  {
    this->_TCPcomm.interpretCommand(this->_tcp);
    if (this->_udp)
      {
	if (!this->_udp->isLive())
	  {
	    std::cerr << "UDP disconnected" << std::endl;
	    delete this->_udp;
	    this->_udp = NULL;
	  }
	this->_UDPcomm.interpretCommand(*this->_udp);
      }
    Sleep(1);
  }
  if (!this->_tcp.isLive())
    std::cerr << "TCP disconnected" << std::endl;
}

void	Debugger::defaultHandler(char opcode, IReadableSocket& sock)
{
  std::cout << "Received unknown opcode (" << static_cast<int>(opcode)
	    << ") on " << (&sock == this->_udp ? "UDP" : "TCP")
	    << " socket." << std::endl;
}

void		Debugger::handleRoomList(void *data)
{
  s_room_list*	list(static_cast<s_room_list*>(data));
  unsigned int	i(0);

  std::cout << "--- ROOM LIST ---" << std::endl;
  while (list->rooms[i].roomId)
    {
      std::cout << "{ Name = \"" << list->rooms[i].roomName << "\", Id = "
		<< static_cast<int>(list->rooms[i].roomId) << ", nbPlayer = "
		<< static_cast<int>(list->rooms[i].nbPlayer) << " }" << std::endl;
      ++i;
    }
  std::cout << "--- END ROOM LIST ---" << std::endl;
}

void		Debugger::handleRoomState(void *data)
{
  s_room_state*	state(static_cast<s_room_state*>(data));
  unsigned int	i(0);

  std::cout << "--- ROOM STATE ---" << std::endl;
  std::cout << "Name: \"" << state->roomName << '"' << std::endl;
  std::cout << "Players:" << std::endl << '{' << std::endl;
  while (*state->playerNames[i])
    {
      std::cout << "\tName: \"" << state->playerNames[i]
		<< "\", State: " << (state->playerStates[i]
				     ? "Ready" : "Waiting") << std::endl;
      ++i;
    }
  std::cout << '}' << std::endl;
  std::cout << "Difficulty: " << static_cast<int>(state->difficulty)
	    << std::endl;
  std::cout << "Map: " << (state->mapStatus
			   ? "File" : "Random");
  if (state->mapStatus)
    std::cout << " (\"" << state->map << "\")";
  std::cout << std::endl;
  std::cout << "--- END ROOM STATE ---" << std::endl;
}

void	Debugger::handleWrongMap(void *)
{
  std::cout << "--- WRONG MAP ---" << std::endl;
}

void			Debugger::handleStartLoading(void *data)
{
  s_start_loading*	loader(static_cast<s_start_loading*>(data));
  unsigned		i(0);

  std::cout << "--- START LOADING ---" << std::endl;
  std::cout << "UDP port: " << loader->port << std::endl;
  while (*loader->ressources[i].filename)
    {
      std::cout << "Ressource: \"" << loader->ressources[i].filename
		<< "\" (" << loader->ressources[i].md5 << ')' << std::endl;
      ++i;
    }
  std::cout << "--- END START LOADING ---" << std::endl;
}

void		Debugger::handleFileTrunk(void *data)
{
  s_file_trunk*	trunk(static_cast<s_file_trunk*>(data));

  std::cout << "--- FILE TRUNK ---" << std::endl;
  std::cout << "Filename: \"" << trunk->filename << '"' << std::endl;
  std::cout << "FileContent: [";
  std::cout.write(trunk->data, trunk->datasize) << ']' << std::endl;
  std::cout << "--- END FILE TRUNK ---" << std::endl;
}

void			Debugger::handleAssocSprites(void *data)
{
  s_assoc_sprites*	assoc(static_cast<s_assoc_sprites*>(data));
  unsigned int		i(0);

  std::cout << "--- ASSOC SPRITES ---" << std::endl;
  std::cout << "Filename: \"" << assoc->filename << '"' << std::endl;
  while (assoc->sprites[i].idSprite)
    {
      std::cout << "Sprite " << assoc->sprites[i].idSprite << ": ("
		<< assoc->sprites[i].coord[0] << ", "
		<< assoc->sprites[i].coord[1] << ", "
		<< assoc->sprites[i].coord[2] << ", "
		<< assoc->sprites[i].coord[3] << ')' << std::endl;
      ++i;
    }
  std::cout << "--- END ASSOC SPRITES ---" << std::endl;
}

void	Debugger::handleUDPOkay(void *)
{
  std::cout << "--- UDP OKAY ---" << std::endl;
}

void		Debugger::handleSendError(void *data)
{
  s_send_error*	err(static_cast<s_send_error*>(data));

  std::cout << "--- SEND ERROR ---" << std::endl;
  std::cout << "Error " << static_cast<int>(err->errorCode) << ": "
	    << err->errorDesc << std::endl;
  std::cout << "--- END SEND ERROR ---" << std::endl;
}

void			Debugger::handleScreenState(void *data)
{
  s_screen_state*	state(static_cast<s_screen_state*>(data));
  unsigned int		i(0);

  std::cout << "--- SCREEN STATE ---" << std::endl;
  std::cout << "Score: " << state->score << std::endl;
  std::cout << "Elements" << std::endl << '{' << std::endl;
  while (state->idSprite[i])
    {
      std::cout << "\tSprite " << state->idSprite[i] << " at ("
		<< state->coords[i]._posX << ", "
		<< state->coords[i]._posY << ')' << std::endl;
      ++i;
    }
  std::cout << '}' << std::endl;
  std::cout << "--- END SCREEN STATE ---" << std::endl;
}

void	Debugger::handleEndOfGame(void *)
{
  std::cout << "--- END OF GAME ---" << std::endl;
}

void		Debugger::sendSayHello(const Args& a)
{
  short		res[2];
  Packet	p;

  if (a.size() != 4)
    std::cout << "Usage: sayHello nickname resWidth resHeight" << std::endl;
  else
    {
      res[0] = stringTo<short>(a[2]);
      res[1] = stringTo<short>(a[3]);
      this->_TCPcomm.TCPsayHello(p, a[1].c_str(), res);
      this->_tcp.send(p);
    }
}

void		Debugger::sendSetRoom(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: setRoom roomName" << std::endl;
  else
    {
      this->_TCPcomm.TCPsetRoom(p, a[1].c_str());
      this->_tcp.send(p);
    }
}

void		Debugger::sendSelectRoom(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: selectRoom roomId" << std::endl;
  else
    {
      this->_TCPcomm.TCPselectRoom(p, stringTo<int>(a[1]));
      this->_tcp.send(p);
    }
}

void		Debugger::sendLeaveRoom(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: leaveRoom roomId" << std::endl;
  else
    {
      this->_TCPcomm.TCPselectRoom(p, stringTo<int>(a[1]));
      this->_tcp.send(p);
    }
}

void		Debugger::sendChangeDifficulty(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: changeDifficulty difficulty" << std::endl;
  else
    {
      this->_TCPcomm.TCPchangeDifficulty(p, stringTo<int>(a[1]));
      this->_tcp.send(p);
    }
}

void		Debugger::sendSetMap(const Args& a)
{
  Packet	p;

  if (a.size() < 2
      || (a[1] != "Random" && a[1] != "Map")
      || (a[1] == "Random" && a.size() != 2)
      || (a[1] == "Map" && a.size() != 3))
    std::cout << "Usage: setMap [Random | Map filename]" << std::endl;
  else
    {
      this->_TCPcomm.TCPsetMap(p, a[1] == "Map", a[2].c_str());
      this->_tcp.send(p);
    }
}

void		Debugger::sendFileTrunk(const Args& a)
{
  char		buff[1024];
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: fileTrunk file" << std::endl;
  else
    {
      std::ifstream	f(a[1].c_str());

      if (!f)
	std::cout << "Could not open " << a[1] << std::endl;
      else
	{
	  f.read(buff, sizeof(buff));
	  this->_TCPcomm.TCPsendFileTrunk(p, a[1].c_str(), buff, static_cast<size_t>(f.gcount()));
	  this->_tcp.send(p);
	}
    }
}

void		Debugger::sendSetReady(const Args& a)
{
  Packet	p;

  if (a.size() != 1)
    std::cout << "Usage: setReady" << std::endl;
  else
    {
      this->_TCPcomm.TCPsetReady(p);
      this->_tcp.send(p);
    }
}

void		Debugger::sendDownloadRsrc(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: downloadRsrc file" << std::endl;
  else
    {
      this->_TCPcomm.TCPdownloadRessource(p, a[1].c_str());
      this->_tcp.send(p);
    }
}

void		Debugger::sendUDPReady(const Args& a)
{
  Packet	p;

  if (a.size() != 1)
    std::cout << "Usage: UDPReady" << std::endl;
  else
    {
      this->_TCPcomm.UDPReady(p);
      this->_tcp.send(p);
    }
}

void		Debugger::sendLetsPlay(const Args& a)
{
  Packet	p;

  if (a.size() != 1)
    std::cout << "Usage: letsPlay" << std::endl;
  else
    {
      this->_TCPcomm.UDPReady(p);
      this->_tcp.send(p);
    }
}

void		Debugger::sendSaveMap(const Args& a)
{
  Packet	p;

  if (a.size() != 2)
    std::cout << "Usage: saveMap file" << std::endl;
  else
    {
      this->_TCPcomm.TCPsaveMap(p, a[1].c_str());
      this->_tcp.send(p);
    }
}

void		Debugger::sendInputs(const Args& a)
{
  s_inputs	in;
  Packet	p;

  if (!this->_udp)
    std::cout << "No UDP connection" << std::endl;
  else if (a.size() != 5)
    std::cout << "Usage: inputs x y fire shield" << std::endl;
  else
    {
      in.x = stringTo<int>(a[1]);
      in.y = stringTo<int>(a[2]);
      in.fire = stringTo<int>(a[3]) != 0;
      in.shield = stringTo<int>(a[4]) != 0;
      this->_UDPcomm.UDPinputs(p, in);
      this->_udp->send(p);
    }
}
