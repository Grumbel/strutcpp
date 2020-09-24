#include <gtest/gtest.h>

#include "strut/tokenize.hpp"

TEST(TokenizeTest, tokenize)
{
  EXPECT_EQ(strut::tokenize("a b c d", ' '), (std::vector<std::string>{"a", "b", "c", "d"}));
  EXPECT_EQ(strut::tokenize("  a1   b2  c3  d4  ", ' '), (std::vector<std::string>{"a1", "b2", "c3", "d4"}));
  EXPECT_EQ(strut::tokenize("xxa1xxxb2xxc3xxd4xxx", 'x'), (std::vector<std::string>{"a1", "b2", "c3", "d4"}));
  EXPECT_EQ(strut::tokenize("abc", ' '), (std::vector<std::string>{"abc"}));
  EXPECT_EQ(strut::tokenize("   abc", ' '), (std::vector<std::string>{"abc"}));
  EXPECT_EQ(strut::tokenize(" abc", ' '), (std::vector<std::string>{"abc"}));
  EXPECT_EQ(strut::tokenize("abc ", ' '), (std::vector<std::string>{"abc"}));
  EXPECT_EQ(strut::tokenize("abc    ", ' '), (std::vector<std::string>{"abc"}));
  EXPECT_EQ(strut::tokenize("   ", ' '), (std::vector<std::string>{}));
  EXPECT_EQ(strut::tokenize("", ' '), (std::vector<std::string>{}));
}

/* EOF */
