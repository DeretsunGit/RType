#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>
# include "WinTCPSocketClient.h"
# include "SocketPool.h"
# include "WSAException.h"

WinTCPSocketClient::WinTCPSocketClient(SocketId sock)
	: _sock(sock), _live(true)
{
}

WinTCPSocketClient::WinTCPSocketClient(const char *hostName, unsigned short port)
{
	sockaddr_in	clientService;
	struct hostent	*ent;

	if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)) == INVALID_SOCKET)
	  throw WSAException("TCPSocket: WSASocket");
	if (!(ent = gethostbyname(hostName)))
	  throw WSAException("TCPSocket: gethostbyname");
	clientService.sin_family = AF_INET;
	clientService.sin_addr = *reinterpret_cast<struct in_addr*>(ent->h_addr);
	WSAHtons(this->_sock, port, &clientService.sin_port);
	if (WSAConnect(this->_sock, (SOCKADDR *) & clientService, sizeof (clientService), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
	{
	  int errcode = WSAGetLastError();
	  if (closesocket(this->_sock) == SOCKET_ERROR)
	    throw WSAException("TCPSocket: closesocket");
	  throw WSAException("TCPSocket: WSAConnect");
	}
	this->_live = true;
}

WinTCPSocketClient::~WinTCPSocketClient()
{
  SocketPool::getInstance().releaseSocket(this);
  if (closesocket(this->_sock) == SOCKET_ERROR)
    std::cerr << WSAException::GetError("~TCPSocket: closesocket: ") << std::endl;
}

void	      WinTCPSocketClient::putback(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_lock);

  this->_buff._input.putBack(buff, size);
}

void  WinTCPSocketClient::send(const Packet& p)
{
  unsigned int			    size(p.getSize());
  std::list<char*>::const_iterator  it(p.getBuffer().begin());
  unsigned int			    sent;

  while (size > 0 && it != p.getBuffer().end())
  {
    sent = std::min<unsigned int>(size, 1024);
    this->send(*it, sent);
    size -= sent;
    ++it;
  }
}

void WinTCPSocketClient::send(const char *buff, unsigned int size)
{
	this->_lock.lock();
	this->_buff._output.writeSome(buff, size);
	this->_lock.unlock();
}

unsigned int WinTCPSocketClient::recv(char *buff, unsigned int size)
{
	unsigned int rc = 0;

	this->_lock.lock();
	rc = this->_buff._input.readSome(buff, size);
	this->_lock.unlock();
	return (rc);
}

WinTCPSocketClient::SocketId  WinTCPSocketClient::getId() const
{
	return (this->_sock);
}

unsigned int	WinTCPSocketClient::readable() const
{
  return (this->_buff._input.readableSize());
}

bool	WinTCPSocketClient::isLive() const
{
	return (this->_live);
}

bool		WinTCPSocketClient::wantToWrite() const
{
	if (!this->_live)
		return (false);
	return (this->_buff._output.readableSize() > 0 ? true : false);
}

void	    WinTCPSocketClient::readFromSock()
{
	int		rc, err;
	DWORD	recvBytes, flags;
	WSABUF	dataBuf;
	char	buffer[DATA_BUFSIZE] = { 0 };

	if (!this->_live)
		return ;
	dataBuf.len = DATA_BUFSIZE;
	dataBuf.buf = buffer;
	flags = 0;
	rc = WSARecv(this->_sock, &dataBuf, 1, &recvBytes, &flags, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		this->_live = false;
		return ;
	}
	if (recvBytes == 0)
	{
		this->_live = false;
		return ;
	}
	this->_lock.lock();
	this->_buff._input.writeSome(dataBuf.buf, recvBytes);
	this->_lock.unlock();
}

void	    WinTCPSocketClient::writeToSock()
{
	int		rc, err;
	DWORD	sendBytes;
	WSABUF	dataBuf;
	char	buffer[DATA_BUFSIZE] = { 0 };

	if (!this->_live)
		return ;
	this->_lock.lock();
	dataBuf.len = this->_buff._output.readSome(buffer, DATA_BUFSIZE);
	this->_lock.unlock();
  	dataBuf.buf = buffer;
	rc = WSASend(this->_sock, &dataBuf, 1, &sendBytes, 0, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		this->_live = false;
		return ;
	}
}

#endif // _WIN32
