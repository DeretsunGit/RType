#ifndef	_WIN32

# include	<iostream>
# include	<stdexcept>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>
# include	"UnixTCPSocketClient.h"

// TO REMOVE
# include	<stdio.h>

# define	READ_SIZE	1024

UnixTCPSocketClient::UnixTCPSocketClient(const char* hostname,
					 unsigned short port)
  : _sock(socket(AF_INET, SOCK_STREAM, 0)), _live(true)
{
  struct sockaddr_in	sin;
  struct hostent*	hostinfo;

  if (this->_sock == -1)
    throw std::runtime_error("TCPSocketClient: failed to create socket");
  if (!(hostinfo = gethostbyname(hostname)))
    throw std::runtime_error("TCPSocketClient: failed to find host");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr = *reinterpret_cast<struct in_addr*>(hostinfo->h_addr);
  if (connect(this->_sock, reinterpret_cast<const struct sockaddr *>(&sin),
	      sizeof(sin)) == -1)
    {
      perror("connect");
      throw std::runtime_error("TCPSocketClient: cannot connect to host");
    }
}

UnixTCPSocketClient::UnixTCPSocketClient(SocketId id)
  : _sock(id), _live(true)
{}

UnixTCPSocketClient::~UnixTCPSocketClient()
{
  if (close(this->_sock) == -1)
    std::cerr << "TCPSocketClient: cannot close socket" << std::endl;
}

void	UnixTCPSocketClient::send(char* buff, unsigned int size)
{
  this->_buff._output.writeSome(buff, size);
}

unsigned int	UnixTCPSocketClient::recv(char* buff, unsigned int size)
{
  return (this->_buff._input.readSome(buff, size));
}

ISocket::SocketId	UnixTCPSocketClient::getId() const
{
  return (this->_sock);
}

bool		UnixTCPSocketClient::wantToWrite() const
{
  return (this->_buff._output.readableSize() > 0);
}

void		UnixTCPSocketClient::readFromSock()
{
  char		buff[READ_SIZE];
  ssize_t	ret;

  if ((ret = ::recv(this->_sock, buff, READ_SIZE, 0)) <= 0)
    this->_live = false;
  else
    this->_buff._input.writeSome(buff, ret);
}

void		UnixTCPSocketClient::writeToSock()
{
  char		buff[READ_SIZE];
  unsigned int	ret(this->_buff._output.readSome(buff, READ_SIZE));

  if (::send(this->_sock, buff, ret, 0) <= 0)
    this->_live = false;
}

bool	UnixTCPSocketClient::isLive() const
{
  return (this->_live);
}

#endif	// !_WIN32
