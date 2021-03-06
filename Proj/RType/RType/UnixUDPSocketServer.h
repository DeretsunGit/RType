#pragma	once

#ifndef	_WIN32

# include "IUDPSocketServer.h"
# include "IOBuff.h"
# include "Mutex.h"

class UnixUDPSocketServer : public IUDPSocketServer
{
private:
  SocketId		_sock;
  bool			_live;
  BuffMap		_map;
  Mutex			_m;
  unsigned short	_port;

  UnixUDPSocketServer();
  UnixUDPSocketServer(const UnixUDPSocketServer&);
  UnixUDPSocketServer& operator=(const UnixUDPSocketServer&);

public:
  UnixUDPSocketServer(unsigned short);
  virtual	      ~UnixUDPSocketServer();
  unsigned short	getPort() const;
  unsigned int  readableFor(const in_addr& from) const;
  unsigned int  readFrom(char* buff, unsigned int size, const in_addr& from);
  unsigned int  recvFrom(char* buff, unsigned int size, in_addr& from);
  void		broadcast(const char* buff, unsigned int size);
  void		broadcast(const Packet& p);
  void	      sendTo(const char* buff, unsigned int size, const in_addr& to);
  void	      sendTo(const Packet& p, const in_addr& to);
  UDPBindedClient&  getClient(const in_addr& c);
  SocketId      getId() const;
  bool	      wantToWrite() const;
  void	      readFromSock();
  void	      writeToSock();
  bool	      isLive() const;
  BuffMap::iterator		begin();
  BuffMap::const_iterator	begin() const;
  BuffMap::iterator		end();
  BuffMap::const_iterator	end() const;
};

#endif	// !_WIN32
