#ifndef HEADER_STRUT_SPLIT_HPP
#define HEADER_STRUT_SPLIT_HPP

#include <string_view>

namespace strut {

std::vector<std::string> split(std::string_view text, char delimiter)
{
  std::vector<std::string> result;

  std::string::size_type start = 0;
  for(std::string::size_type i = 0; i != text.size(); ++i)
  {
    if (text[i] == delimiter)
    {
      result.emplace_back(text.substr(start, i - start));
      start = i + 1;
    }
  }

  result.emplace_back(text.substr(start));

  return result;
}

} // namespace strut

#endif

/* EOF */
