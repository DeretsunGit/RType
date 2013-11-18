#pragma once

#include  <string>
#include  "Singleton.h"

class Debug: private Singleton<Debug>
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

  static void		      log(const std::string& msg, Level lvl);
  static void		      setLevel(Level lvl);
  static Level		      getLevel();
  static void		      setLogFile(const std::string& filename);
  static const std::string&   getLogFile();

private:
  void		      _log(const std::string& msg, Level lvl) const;
  void		      _setLevel(Level lvl);
  Level		      _getLevel() const;
  void		      _setLogFile(const std::string& filename);
  const std::string&  _getLogFile() const;

  static const	char*  _strLevel[emerg + 1];

  Level	      _level;
  std::string _filename;

  Debug(const Debug&);
  Debug&  operator=(const Debug&);
};