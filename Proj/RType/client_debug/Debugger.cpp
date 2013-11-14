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
  while (std::getline(std::cin, line) && this->_tcp.isLive() && line != "exit")
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
    else if (!args.empty())
      std::cout << "Unknown command " << args[0] << std::endl;
    std::cout << "Loop" << std::endl;
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
  throw std::exception();
}

void			  Debugger::handleRoomList(void *data)
{
  std::list<s_room_info>*  list(static_cast<std::list<s_room_info>*>(data));
  std::list<s_room_info>::iterator  it(list->begin());
  std::list<s_room_info>::iterator  end(list->end());

  std::cout << "--- ROOM LIST ---" << std::endl;
  while (it != end)
    {
      std::cout << "{ Name = \"" << it->name << "\", Id = "
		<< static_cast<int>(it->id) << ", nbPlayer = "
		<< static_cast<int>(it->nbPlayer) << " }" << std::endl;
      ++it;
    }
  std::cout << "--- END ROOM LIST ---" << std::endl;
}

void		Debugger::handleRoomState(void *data)
{
  s_room_state_info*	state(static_cast<s_room_state_info*>(data));
  unsigned int	i(0);

  std::cout << "--- ROOM STATE ---" << std::endl;
  std::cout << "Name: \"" << state->name << '"' << std::endl;
  std::cout << "Players:" << std::endl << '{' << std::endl;
  while (i < 4)
    {
      std::cout << "\tName: \"" << state->players[i]
		<< "\", State: " << (state->playerState[i]
				     ? "Ready" : "Waiting") << std::endl;
      ++i;
    }
  std::cout << '}' << std::endl;
/*  std::cout << "Difficulty: " << static_cast<int>(state->difficulty)
	    << std::endl;
  std::cout << "Map: " << (state->mapStatus
			   ? "File" : "Random");
  if (state->mapStatus)
    std::cout << " (\"" << state->map << "\")";
  std::cout << std::endl;*/
  std::cout << "--- END ROOM STATE ---" << std::endl;
}

void	Debugger::handleWrongMap(void *)
{
  std::cout << "--- WRONG MAP ---" << std::endl;
}

void			Debugger::handleStartLoading(void *data)
{
  s_start_loading*	loader(static_cast<s_start_loading*>(data));
  std::list<std::pair<char[128], char[32]> >::iterator	it(loader->files.begin());
  std::list<std::pair<char[128], char[32]> >::iterator	end(loader->files.end());

  std::cout << "--- START LOADING ---" << std::endl;
  std::cout << "UDP port: " << loader->udp << std::endl;
  while (it != end)
    {
      std::cout << "Ressource: \"" << it->first << "\" (";
      std::cout.write(it->second, 32) << ')' << std::endl;
      ++it;
    }
  std::cout << "--- END START LOADING ---" << std::endl;
}

void		Debugger::handleFileTrunk(void *data)
{
  s_file_trunk*	trunk(static_cast<s_file_trunk*>(data));

  std::cout << "--- FILE TRUNK ---" << std::endl;
  std::cout << "Filename: \"" << trunk->file << '"' << std::endl;
  std::cout << "FileContent: [";
  std::cout.write(trunk->data, trunk->size) << ']' << std::endl;
  std::cout << "--- END FILE TRUNK ---" << std::endl;
}

void			Debugger::handleAssocSprites(void *data)
{
  s_assoc_sprite*	assoc(static_cast<s_assoc_sprite*>(data));
  std::list<std::pair<char, unsigned short[4]> >::iterator  it(assoc->sprites.begin());
  std::list<std::pair<char, unsigned short[4]> >::iterator  end(assoc->sprites.end());

  std::cout << "--- ASSOC SPRITES ---" << std::endl;
  std::cout << "Filename: \"" << assoc->file << '"' << std::endl;
  while (it != end)
    {
      std::cout << "Sprite " << it->first << ": ("
		<< it->second[0] << ", "
		<< it->second[1] << ", "
		<< it->second[2] << ", "
		<< it->second[3] << ')' << std::endl;
      ++it;
    }
  std::cout << "--- END ASSOC SPRITES ---" << std::endl;
}

void	Debugger::handleUDPOkay(void *)
{
  std::cout << "--- UDP OKAY ---" << std::endl;
}

void		Debugger::handleSendError(void *data)
{
  s_error*	err(static_cast<s_error*>(data));

  std::cout << "--- SEND ERROR ---" << std::endl;
  std::cout << "Error " << static_cast<int>(err->code) << ": "
	    << err->msg << std::endl;
  std::cout << "--- END SEND ERROR ---" << std::endl;
}

void			Debugger::handleScreenState(void *data)
{
  s_screen_state*	state(static_cast<s_screen_state*>(data));
  std::list<std::pair<unsigned char, t_coord> >::iterator  it(state->elements.begin());
  std::list<std::pair<unsigned char, t_coord> >::iterator  end(state->elements.end());

  std::cout << "--- SCREEN STATE ---" << std::endl;
  std::cout << "Score: " << state->score << std::endl;
  std::cout << "Elements" << std::endl << '{' << std::endl;
  while (it != end)
    {
      std::cout << "\tSprite " << static_cast<int>(it->first) << " at ("
		<< it->second._posX << ", "
		<< it->second._posY << ')' << std::endl;
      ++it;
    }
  std::cout << '}' << std::endl;
  std::cout << "--- END SCREEN STATE ---" << std::endl;
}

void	Debugger::handleEndOfGame(void *data)
{
  std::cout << "--- END OF GAME ---" << std::endl;
  std::cout << "Score: " << *static_cast<unsigned int*>(data) << std::endl;
  std::cout << "--- END END OF GAME ---" << std::endl;
}

void		  Debugger::sendSayHello(const Args& a)
{
  unsigned short  res[2];
  Packet	  p;

  if (a.size() != 4)
    std::cout << "Usage: sayHello nickname resWidth resHeight" << std::endl;
  else
    {
      res[0] = stringTo<unsigned short>(a[2]);
      res[1] = stringTo<unsigned short>(a[3]);
      this->_TCPcomm.TCPsayHello(p, a[1].c_str(), res);
	  std::cout << "OPcode sended : " << Opcodes::sayHello << ", revEndian : " << std::endl;
      std::cout << "Size du packet: " << p.getSize() << std::endl;
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

  if (a.size() != 1)
    std::cout << "Usage: leaveRoom" << std::endl;
  else
    {
      this->_TCPcomm.TCPleaveRoom(p);
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
