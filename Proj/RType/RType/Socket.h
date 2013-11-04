#pragma once

class ASocket
{
public:
#ifdef _WIN32

# include <Windows.h>

  typedef SOCKET  SocketId;

#else

  typedef int	  SocketId;

#endif // _WIN32

  ASocket();
  virtual ~ASocket();
  virtual SocketId  getId() const = 0;
  virtual bool	    wantToWrite() const = 0;
  virtual void	    readFromSock() = 0;
  virtual void	    writeToSock() = 0;
  virtual bool		isLive() const = 0;

private:
  ASocket(const ASocket&);
  ASocket&  operator=(const ASocket&);
};
