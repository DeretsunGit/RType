#include  <algorithm>
#include  <functional>
#include  "ThreadPool.h"

ThreadPool::ThreadPool(unsigned int size)
  : _ths(size, Thread(*this, &ThreadPool::poolLoop)), _living(true), _wait(size), _maxWait(size)
{
  std::for_each(this->_ths.begin(), this->_ths.end(), std::mem_fun_ref(&Thread::start));
}

ThreadPool::~ThreadPool()
{
  this->_living = false;
  this->_m.lock();
  this->_cond.broadcast();
  this->_m.unlock();
  std::for_each(this->_ths.begin(), this->_ths.end(), std::bind2nd(std::mem_fun_ref(&Thread::timedJoin), 10));
}

void	    ThreadPool::poolLoop()
{
  ICaller*  action(NULL);

  while (this->_living)
  {
    this->_m.lock();
    if (this->_toDo.empty())
    {
      this->_waitLock.lock();
      if (action && ++this->_wait >= this->_maxWait)
        this->_waitCond.signal();
      this->_waitLock.unlock();
      this->_cond.wait(ThreadPool::_m);
    }
    if (!this->_toDo.empty())
    {
      if (!action)
      {
	this->_waitLock.lock();
	--this->_wait;
	this->_waitLock.unlock();
      }
      action = this->_toDo.front();
      this->_toDo.pop();
    }
    else
      action = NULL;
    this->_m.unlock();
    if (action)
    {
      action->call();
      delete action;
    }
  }
}

void  ThreadPool::startWorking()
{
  this->_m.lock();
  while (!this->_buff.empty())
  {
    this->_toDo.push(this->_buff.front());
    this->_buff.pop();
  }
  this->_cond.broadcast();
  this->_m.unlock();
}

void  ThreadPool::wait()
{
  this->_waitLock.lock();
  this->_waitCond.wait(this->_waitLock);
  this->_waitLock.unlock();
}