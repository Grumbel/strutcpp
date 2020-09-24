#ifndef HEADER_TOKENIZE_HPP
#define HEADER_TOKENIZE_HPP

#include <vector>
#include <string_view>

namespace strut {

inline
std::vector<std::string> tokenize(std::string_view text, char delimiter)
{
  std::vector<std::string> result;

  for(std::string::size_type i = 0; i != text.size();)
  {
    while(text[i] == delimiter && i != text.size()) { ++i; }
    const std::string::size_type start = i;
    while(text[i] != delimiter && i != text.size()) { ++i; }
    const std::string::size_type end = i;
    if (start != end) {
      result.emplace_back(text.substr(start, end - start));
    }
  }

  return result;
}

} // namespace strut

#endif

/* EOF */
