#pragma once

#include  <ostream>
#include  <string>

namespace Hash
{
  class MD5
  {
  public:
    MD5();
    MD5(const MD5&);
    MD5(const std::string& str);
    MD5(const char* src, unsigned int size);
    MD5&  operator=(const MD5&);
    ~MD5();

    void  hash(const char* src, unsigned int size);
    void  copyTo(unsigned char* _dest) const;

  private:
    unsigned char _buff[16];
  };
}

std::ostream&	operator<<(std::ostream&, const Hash::MD5&);
