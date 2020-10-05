// strut - Collection of string utilities
// Copyright (C) 2020 Ingo Ruhnke <grumbel@gmail.com>
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
// License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_STRUT_TOKENIZE_HPP
#define HEADER_STRUT_TOKENIZE_HPP

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
