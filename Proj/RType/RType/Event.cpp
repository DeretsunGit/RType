#include "Event.h"


Event::Event(void)
{
}

float Event::getSecFromStrHour(const std::string& hours) const
{
	std::stringstream ss(hours);
	float value;

	ss >> value;
	value = value * 60 * 60;
	return (value);
}

float Event::getSecFromStrMin(const std::string& min) const
{
	std::stringstream ss(min);
	float value;

	ss >> value;
	value = value * 60;
	return (value);
}

float Event::getSecFromStrMSec(const std::string& msec) const
{
	std::stringstream ss(msec);
	float value;
	ss >> value;
	value = value / 100;
	return (value);
}

float Event::transformFormat(const std::string& toTranform) const
{
	// string sous la forme de HH:MM:SS:MS
	std::stringstream ss_tmp, ss(toTranform);
	std::string format;
	float f_tmp, value = 0.0;

	std::getline(ss, format, ':');
	value += getSecFromStrHour(format);
	std::getline(ss, format, ':');
	value += getSecFromStrMin(format);
	std::getline(ss, format, ':');
	ss_tmp.str(format);
	ss_tmp >> f_tmp;
	value += f_tmp;
	std::getline(ss, format, ':');
	value += getSecFromStrMSec(format);

	return (value);
}


Event::~Event(void)
{
}

void	Event::start()
{
  std::map<float, std::string>::iterator ite;

  if (!_clock.initialise())
    return ;
  while (_clock.getTimeBySec())  /*< execution time*/
    {
      if (_events.size() != 0)
	{
	  ite = _events.begin();
	}
      while (ite != _events.end())
	{
	  if (ite->first <= _clock.getTimeBySec())
	    {
	      std::cout << ite->second << std::endl;
	      _events.erase(ite);
	      break ;
	    }
	  ++ite;
	}
    }
}
