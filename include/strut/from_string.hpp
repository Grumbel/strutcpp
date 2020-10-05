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

#ifndef HEADER_STRUT_FROM_STRING_HPP
#define HEADER_STRUT_FROM_STRING_HPP

#include <typeinfo>
#include <sstream>

namespace strut {

template<typename T>
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

template<typename T>
T from_string(std::string const& text)
{
  T tmp;
  if (from_string(text, tmp)) {
    return tmp;
  } else {
    std::ostringstream oss;
    oss << "couldn't convert '" << text << "' to " << typeid(T).name();
    throw std::invalid_argument(oss.str());
  }
}

} // namespace strut

#endif

/* EOF */
