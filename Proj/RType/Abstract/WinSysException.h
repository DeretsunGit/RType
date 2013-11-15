#ifdef _WIN32
# pragma once
# include <Windows.h>
# include "SystemException.h"

class WinSysException: public SystemException
{
public:
  WinSysException(const std::string& msg, int code)
    : SystemException(msg, code)
  {
    formatError();
  }

  WinSysException(const std::string& msg = "")
    : SystemException(msg, GetLastError())
  {
    formatError();
  }

  WinSysException(const WinSysException& w)
    : SystemException(w)
  {}

  WinSysException&  operator=(const WinSysException& w)
  {
    if (this != &w)
      this->SystemException::operator=(w);
    return (*this);
  }

  virtual ~WinSysException()
  {}

  static std::string  GetError(int code, const std::string& msg = "")
  {
    std::string	      sent(msg);

    LPVOID lpMsgBuf;
    DWORD bufLen = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    if (bufLen)
    {
      LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
      if (sent.size())
	sent += ": ";
      sent += std::string(lpMsgStr, lpMsgStr+bufLen);
      LocalFree(lpMsgBuf);
    }
    return (sent);
  }

  static std::string  GetError(const std::string& s = "")
  {
    return (GetError(GetLastError(), s));
  }

private:
  void	formatError()
  {
    this->setWhat(GetError(this->getCode()));
  }
};

#endif // _WIN32
