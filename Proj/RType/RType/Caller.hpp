//
// Caller.hpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:58:58 2013 julien edmond
// Last update Sat Oct 26 15:17:09 2013 julien edmond
//

#pragma once

#include	<functional>

class ICaller
{
public:
  ~ICaller() {}

  virtual void	call() = 0;
  virtual ICaller*	clone() = 0;
};

template<typename Callable>
class BasicCaller : public ICaller
{
public:
  BasicCaller(Callable c)
    : _call(c)
  {}

  BasicCaller(const BasicCaller& c)
    : _call(c._call)
  {}

  ~BasicCaller()
  {}

  void		call()
  {
    this->_call();
  }

  ICaller*  clone()
  { return (new BasicCaller(this->_call)); }
  
private:
  BasicCaller();
  BasicCaller&	operator=(const BasicCaller&);

protected:
  Callable	_call;
};

template<typename Callable>
ICaller*  getCaller(Callable c)
{
  return (new BasicCaller<Callable>(c));
}

template<typename Callable, typename Arg>
class Caller : public ICaller
{
public:
  Caller(Callable c, Arg a)
    : _call(c), _arg(a)
  {}

  Caller(const Caller& c)
    : _call(c._call), _arg(c._arg)
  {}

  ~Caller()
  {}

  void		call()
  {
    this->_call(this->_arg);
  }

  ICaller*  clone()
  { return (new Caller(this->_call, this->_arg)); }

private:
  Caller();
  Caller&	operator=(const Caller&);
  
protected:
  Callable	_call;
  Arg		_arg;
};

template <typename Callable, typename Arg>
ICaller*  getCaller(Callable c, Arg a)
{ return (new Caller(c, a)); }

template <typename Obj>
class MthdPtrCaller: public Caller<std::mem_fun_t<void, Obj>, Obj*>
{
public:
  MthdPtrCaller(Obj& o, void (Obj::*m)())
    : Caller<std::mem_fun_t<void, Obj>, Obj*>(std::mem_fun_t<void, Obj>(m), &o)
  {}

  MthdPtrCaller(const MthdPtrCaller& m)
    : Caller(m)
  {}

  ICaller*  clone()
  { return (new Caller(this->_call, this->_arg)); }

private:
  MthdPtrCaller();
  MthdPtrCaller&	operator=(const MthdPtrCaller&);
};

template <typename Obj>
ICaller*  getCaller(Obj& o, void (Obj::*m)())
{ return (new MthdPtrCaller(o, m)); }

template <typename Obj, typename Param>
class MthdPtrCaller2: public Caller<std::binder1st<std::mem_fun1_t<void, Obj, Param> >, Param>
{
public:
  MthdPtrCaller2(Obj& o, void (Obj::*m)(Param), Param p)
    : Caller<std::binder1st<std::mem_fun1_t<void, Obj, Param> >, Param>(std::bind1st(std::mem_fun1_t<void, Obj, Param>(m), &o), p)
  {}

  MthdPtrCaller2(const MthdPtrCaller2& m)
    : Caller(m)
  {}

  ICaller*  clone()
  { return (new Caller(this->_call, this->_arg)); }

private:
  MthdPtrCaller2();
  MthdPtrCaller2&	operator=(const MthdPtrCaller2&);
};

template <typename Obj, typename Param>
ICaller*  getCaller(Obj& o, void (Obj::*m)(Param), Param p)
{ return (new MthdPtrCaller2(o, m, p)); }
