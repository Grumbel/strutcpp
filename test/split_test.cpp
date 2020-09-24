#include <gtest/gtest.h>

#include "strut/split.hpp"

TEST(SplitTest, string_split)
{
  EXPECT_EQ(strut::split("a:b:c:d", ':'), (std::vector<std::string>{"a", "b", "c", "d"}));
  EXPECT_EQ(strut::split("a:b:c:d", ':'), (std::vector<std::string>{"a", "b", "c", "d"}));
  EXPECT_EQ(strut::split(":a:b:c:d:", ':'), (std::vector<std::string>{"", "a", "b", "c", "d", ""}));
  EXPECT_EQ(strut::split("", ':'), (std::vector<std::string>{""}));
  EXPECT_EQ(strut::split(":", ':'), (std::vector<std::string>{"", ""}));
  EXPECT_EQ(strut::split("::", ':'), (std::vector<std::string>{"", "", ""}));
  EXPECT_EQ(strut::split("abc:", ':'), (std::vector<std::string>{"abc", ""}));
  EXPECT_EQ(strut::split(":xyz", ':'), (std::vector<std::string>{"", "xyz"}));
  EXPECT_EQ(strut::split("abc", ':'), (std::vector<std::string>{"abc"}));
}

/* EOF */
