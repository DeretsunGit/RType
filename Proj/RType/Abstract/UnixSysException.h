//
// UnixSysException.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sun Nov 17 14:19:57 2013 julien edmond
// Last update Sun Nov 17 14:37:21 2013 julien edmond
//

#ifndef	_WIN32
# pragma once
# include	<errno.h>
# include	<string.h>
# include	"SystemException.h"

class	UnixSysException: public SystemException
{
public:
  UnixSysException(const std::string& msg, int code)
    : SystemException(msg, code)
  {
    formatError();
  }

  UnixSysException(const std::string& msg = "")
    : SystemException(msg, errno)
  {
    formatError();
  }

  UnixSysException(const UnixSysException& u)
    : SystemException(u)
  {}

  UnixSysException&	operator=(const UnixSysException& u)
  {
    if (this != &u)
      this->SystemException::operator=(u);
    return (*this);
  }

  virtual ~UnixSysException() throw()
  {}

  static std::string	GetError(int code, const std::string& msg = "")
  {
    std::string		sent(msg);

    if (!sent.empty())
      sent += ": ";
    return (sent + strerror(code));
  }

  static std::string	GetError(const std::string& msg = "")
  {
    return (GetError(errno, msg));
  }

private:
  void	formatError()
  {
    this->setWhat(GetError(this->getCode()));
  }
};

#endif	// !_WIN32
