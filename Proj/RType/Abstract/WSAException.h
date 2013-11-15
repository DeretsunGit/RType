#ifdef _WIN32
# pragma    once

# include   "WinSysException.h"

class WSAException: public WinSysException
{
public:
  WSAException(const std::string& msg, int code)
    : WinSysException(msg, code)
  {}

  WSAException(const std::string& msg = "")
    : WinSysException(msg, WSAGetLastError())
  {}

  WSAException(const WSAException& w)
    : WinSysException(w)
  {}

  WSAException&  operator=(const WSAException& w)
  {
    if (this != &w)
      this->WSAException::operator=(w);
    return (*this);
  }

  virtual ~WSAException()
  {}

  static std::string  GetError(const char* msg)
  {
    return (WinSysException::GetError(WSAGetLastError(), msg));
  }
};

#endif // _WIN32
