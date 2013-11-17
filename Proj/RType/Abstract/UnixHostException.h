//
// UnixHostException.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sun Nov 17 14:19:57 2013 julien edmond
// Last update Sun Nov 17 14:42:33 2013 julien edmond
//

#ifndef	_WIN32
# pragma once
# include	<netdb.h>
# include	"SystemException.h"

class	UnixHostException: public SystemException
{
public:
  UnixHostException(const std::string& msg, int code)
    : SystemException(msg, code)
  {
    formatError();
  }

  UnixHostException(const std::string& msg = "")
    : SystemException(msg, h_errno)
  {
    formatError();
  }

  UnixHostException(const UnixHostException& u)
    : SystemException(u)
  {}

  UnixHostException&	operator=(const UnixHostException& u)
  {
    if (this != &u)
      this->SystemException::operator=(u);
    return (*this);
  }

  virtual ~UnixHostException() throw()
  {}

  static std::string	GetError(int code, const std::string& msg = "")
  {
    std::string		sent(msg);

    if (!sent.empty())
      sent += ": ";
    return (sent + hstrerror(code));
  }

  static std::string	GetError(const std::string& msg = "")
  {
    return (GetError(h_errno, msg));
  }

private:
  void	formatError()
  {
    this->setWhat(GetError(this->getCode()));
  }
};

#endif	// !_WIN32
