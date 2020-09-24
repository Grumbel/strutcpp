#ifndef HEADER_PARSE_HPP
#define HEADER_PARSE_HPP

#include <sstream>

namespace strut {

template<class T>
bool from_string(const std::string& s, T& t)
{
  std::istringstream str(s);
  T tmp;
  str >> tmp;
  if (str.fail())
  {
    return false;
  }
  else
  {
    t = tmp;
    return true;
  }
  return false;
}

} // namespace strut

#endif

/* EOF */
