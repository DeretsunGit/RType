#include  <algorithm>
#include  <functional>
#include  "ThreadPool.h"

ThreadPool::ThreadPool(unsigned int size)
  : _ths(size, Thread(*this, &ThreadPool::poolLoop)), _living(true)
{
  std::for_each(this->_ths.begin(), this->_ths.end(), std::mem_fun_ref(&Thread::start));
}

ThreadPool::~ThreadPool()
{
  this->_living = false;
  this->_cond.broadcast();
  std::for_each(this->_ths.begin(), this->_ths.end(), std::mem_fun_ref(&Thread::join));
}

void	    ThreadPool::poolLoop()
{
  ICaller*  action;

  while (this->_living)
  {
    this->_m.lock();
    if (this->_toDo.empty())
      this->_cond.wait(ThreadPool::_m);
    if (!this->_toDo.empty())
    {
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
  this->_m.unlock();
}
