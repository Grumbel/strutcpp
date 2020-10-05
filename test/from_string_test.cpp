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

#include <gtest/gtest.h>

#include <strut/from_string.hpp>

TEST(FromStringTest, from_string)
{
  EXPECT_EQ(strut::from_string<int>("123"), 123);
  EXPECT_EQ(strut::from_string<float>("1.25"), 1.25f);

  float fv;
  EXPECT_TRUE(strut::from_string("1.25", fv));
  EXPECT_EQ(fv, 1.25f);

  int iv;
  EXPECT_TRUE(strut::from_string("123", iv));
  EXPECT_EQ(iv, 123);

  EXPECT_THROW(strut::from_string<int>("abc"), std::invalid_argument);
  EXPECT_THROW(strut::from_string<float>("abc"), std::invalid_argument);
}

/* EOF */
