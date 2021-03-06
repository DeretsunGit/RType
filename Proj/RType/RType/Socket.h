#pragma once

#ifdef _WIN32

# include <Windows.h>

#endif // _WIN32


class ISocket
{
public:
#ifdef _WIN32

  typedef SOCKET  SocketId;

#else

  typedef int	  SocketId;
  typedef struct in_addr IN_ADDR;

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
