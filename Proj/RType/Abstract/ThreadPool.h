#pragma once

#include  <list>
#include  <vector>
#include  <queue>
#include  "Caller.hpp"
#include  "Thread.h"
#include  "Mutex.h"
#include  "CondVar.h"

class ThreadPool
{
public:
  ThreadPool(unsigned int nbThread = 10);
  ~ThreadPool();

private:
  ThreadPool(const ThreadPool&);
  ThreadPool& operator=(const ThreadPool&);

  void	poolLoop();

  template<typename Obj>
  void addAction(Obj& o, void (Obj::*m)(), bool bufferise = true)
  {
    std::queue<ICaller*>& target((bufferise ? this->_buff : ThreadPool::_toDo));

    target.push(getCaller(o, m));
  }

  template<typename Obj, typename Param>
  void addAction(Obj& o, void (Obj::*m)(Param), Param p, bool bufferise = true)
  {
    std::queue<ICaller*>& target((bufferise ? this->_buff : ThreadPool::_toDo));

    target.push(getCaller(o, m, p));
  }

  template<typename Callable>
  void addAction(Callable& c, bool bufferise = true)
  {
    std::queue<ICaller*>& target((bufferise ? this->_buff : ThreadPool::_toDo));

    target.push(getCaller(c));
  }

  template<typename Callable, typename Param>
  void addAction(Callable c, Param p, bool bufferise = true)
  {
    std::queue<ICaller*>& target((bufferise ? this->_buff : ThreadPool::_toDo));

    target.push(getCaller(c, p));
  }

  void	startWorking();

  std::vector<Thread>	      _ths;
  std::queue<ICaller*>	      _buff;
  bool			      _living;

  Mutex			_m;
  CondVar		_cond;
  std::queue<ICaller*>	_toDo;
};
