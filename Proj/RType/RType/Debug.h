#pragma once

#include  <string>
#include  "Singleton.h"

class Debug: public Singleton<Debug>
{
public:
  enum Level
  {
    debug,
    info,
    notice,
    warn,
    err,
    crit,
    alert,
    emerg
  };

  Debug();
  ~Debug();
  void		      log(const std::string& msg, Level lvl) const;
  void		      setLevel(Level lvl);
  Level		      getLevel() const;
  void		      setLogFile(const std::string& filename);
  const std::string&  getLogFile() const;

private:
  Level	      _level;
  std::string _filename;

  Debug(const Debug&);
  Debug&  operator=(const Debug&);
};