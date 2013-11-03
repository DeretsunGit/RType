#pragma once

#include <stdexcept>

template<typename Type>
class Singleton
{
public:
  Singleton()
  {
    if (Singleton<Type>::_instanciated)
      throw std::runtime_error("A singleton can only be instanciate once");
    Singleton<Type>::_instanciated = true;
  }

  ~Singleton()
  {}

  static Type&	getInstance()
  {
    return (dynamic_cast<Type&>(*this));
  }

private:
  Singleton(const Singleton&);
  Singleton&  operator=(const Singleton&);

  static bool _instanciated;
};

template<typename Type>
bool  Singleton<Type>::_instanciated(false);