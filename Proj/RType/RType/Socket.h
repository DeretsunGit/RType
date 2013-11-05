#pragma once

class ISocket
{
public:
#ifdef _WIN32

# include <Windows.h>

  typedef SOCKET  SocketId;

#else

  typedef int	  SocketId;

#endif // _WIN32

  ISocket() {}
  virtual ~ISocket() {}
  virtual SocketId  getId() const = 0;
  virtual bool	    wantToWrite() const = 0;
  virtual void	    readFromSock() = 0;
  virtual void	    writeToSock() = 0;
  virtual bool		isLive() const = 0;

private:
  ISocket(const ISocket&);
  ISocket&  operator=(const ISocket&);
};
