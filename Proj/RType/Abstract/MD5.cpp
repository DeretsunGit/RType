#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "MD5.h"

Hash::MD5::MD5()
{
  memset(this->_buff, 0, sizeof(this->_buff));
}

Hash::MD5::MD5(const MD5& m)
{
  memcpy(this->_buff, m._buff, sizeof(this->_buff));
}

Hash::MD5::MD5(const std::string& str)
{
  this->hash(str.c_str(), static_cast<unsigned int>(str.size()));
}

Hash::MD5::MD5(const char* src, unsigned int size)
{
  this->hash(src, size);
}

Hash::MD5&  Hash::MD5::operator=(const MD5& m)
{
  if (this != &m)
    memcpy(this->_buff, m._buff, sizeof(this->_buff));
  return (*this);
}

Hash::MD5::~MD5()
{}

#ifdef _WIN32
# include <Windows.h>
# include <wincrypt.h>
# include "WinSysException.h"

void	      Hash::MD5::hash(const char* src, unsigned int size)
{
  HCRYPTPROV  hProv = NULL;
  HCRYPTHASH  hHash = NULL;
  DWORD	      cbHash;

  if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)
      || !CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash)
      || !CryptHashData(hHash, reinterpret_cast<const BYTE *>(src), size, 0))
  {
    int	code(GetLastError());

    if (hProv)
      CryptReleaseContext(hProv, 0);
    if (hHash)
      CryptDestroyHash(hHash);
    throw WinSysException("MD5 Hash", code);
  }
  cbHash = sizeof(this->_buff);
  if (!CryptGetHashParam(hHash, HP_HASHVAL, this->_buff, &cbHash, 0))
  {
    int	code(GetLastError());

    CryptReleaseContext(hProv, 0);
    CryptDestroyHash(hHash);
    throw WinSysException("MD5 Hash", code);
  }
  CryptReleaseContext(hProv, 0);
  CryptDestroyHash(hHash);
}

#else	// _WIN32
# include <openssl/md5.h>

void  Hash::MD5::hash(const char* src, unsigned int size)
{
  ::MD5(reinterpret_cast<const unsigned char*>(src), size, this->_buff);
}

#endif	// _WIN32

void  Hash::MD5::copyTo(unsigned char* dest) const
{
  memcpy(dest, this->_buff, sizeof(this->_buff));
}

std::ostream&		operator<<(std::ostream& os, const Hash::MD5& m)
{
  unsigned char		buff[16];
  int			i(-1);
  std::ios::char_type	fill(os.fill());
  std::streamsize	width(os.width());
  std::ios::fmtflags	flags(os.flags());

  m.copyTo(buff);
  os << std::setfill(' ') << std::hex << std::setw(2);
  while (++i < sizeof(buff))
    os << static_cast<unsigned int>(buff[i]);
  os.fill(fill);
  os.width(width);
  os.flags(flags);
  return (os);
}
