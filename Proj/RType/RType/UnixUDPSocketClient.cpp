#ifndef _WIN32

# include	<iostream>
# include	<stdexcept>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>
# include	<cstring>
# include	"UnixUDPSocketClient.h"
# include	"SocketPool.h"

#define	READ_SIZE 500

UnixUDPSocketClient::UnixUDPSocketClient(const char* hostname, unsigned short port)
  : _sock(socket(AF_INET, SOCK_DGRAM, 0)), _live(true), _port(port)
{
  struct hostent* ent;

  if (this->_sock == -1)
    throw std::runtime_error("UDPSocketClient: failed to create socket"); // UNIXEXCEPT
  if (!(ent = gethostbyname(hostname)))
    throw std::runtime_error("UDPScoektClient: could not find host"); // UNIXEXCEPT
  this->_host = *reinterpret_cast<IN_ADDR*>(ent->h_addr);
}

UnixUDPSocketClient::~UnixUDPSocketClient()
{
  if (close(this->_sock))
    std::cerr << "UDPSocketClient: failed to close socket" << std::endl; // UNIXEXCEPT
}

unsigned int  UnixUDPSocketClient::readable() const
{
  return (this->_buff._input.readableSize());
}

unsigned int  UnixUDPSocketClient::recv(char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  return (this->_buff._input.readSome(buff, size));
}

void	      UnixUDPSocketClient::putback(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  this->_buff._input.putBack(buff, size);
}

void  UnixUDPSocketClient::send(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  this->_buff._output.writeSome(buff, size);
}

void  UnixUDPSocketClient::send(const Packet& p)
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

ISocket::SocketId UnixUDPSocketClient::getId() const
{
  return (this->_sock);
}

bool  UnixUDPSocketClient::wantToWrite() const
{
  return (!!this->_buff._output.readableSize());
}

void  UnixUDPSocketClient::readFromSock()
{
  char		      buff[READ_SIZE];
  struct sockaddr_in  sin;
  ssize_t	      red;
  socklen_t	      size = sizeof(sin);

  if ((red = recvfrom(this->_sock, buff, READ_SIZE, 0, reinterpret_cast<struct sockaddr*>(&sin), &size)) <= 0)
    this->_live = false;
  else if (sin.sin_addr.s_addr == this->_host.s_addr)
  {
    this->_m.lock();
    this->_buff._input.writeSome(buff, red);
    this->_buff._port = sin.sin_port;
    this->_m.unlock();
  }
}

void	UnixUDPSocketClient::writeToSock()
{
  char		      buff[READ_SIZE];
  struct sockaddr_in  sin;
  int		      len;

  memset(&sin, 0, sizeof(sin));
  sin.sin_addr.s_addr = this->_host.s_addr;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(this->_port);
  this->_m.lock();
  len = this->_buff._output.readSome(buff, READ_SIZE);
  this->_m.unlock();
  if (sendto(this->_sock, buff, len, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin)) == -1)
    this->_live = false;
}

bool  UnixUDPSocketClient::isLive() const
{
  return (this->_live);
}

#endif // !_WIN32
