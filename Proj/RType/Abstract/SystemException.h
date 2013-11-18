#pragma once

#include  <stdexcept>
#include  <string>

class SystemException: std::runtime_error
{
public:
  SystemException(const std::string& msg = "", int code = 0, const std::string& what = "An error occured") throw()
    : std::runtime_error(msg.empty() ? what : msg + ": " + what), _str(msg), _code(0),
      _strerror(what), _res(this->std::runtime_error::what())
  {}

  SystemException(const SystemException& s) throw()
    : std::runtime_error(s), _str(s._str), _code(s._code), _strerror(s._strerror), _res(s._res)
  {}

  SystemException&  operator=(const SystemException& s) throw()
  {
    if (this != &s)
    {
      this->std::runtime_error::operator=(s);
      this->_str = s._str;
      this->_code = s._code;
      this->_strerror = s._strerror;
      this->_res = s._res;
    }
    return (*this);
  }

  virtual ~SystemException() throw()
  {}

  virtual const char* what() const throw()
  {
    return (_res.c_str());
  }

  virtual int getCode() const throw()
  {
    return (_code);
  }

protected:

  void	setWhat(const std::string& str)
  {
    _strerror = str;
    _res = _str.empty() ? _strerror : _str + ": " + _strerror;
  }

private:
  std::string _str;
  int	      _code;
  std::string _strerror;
  std::string _res;
};