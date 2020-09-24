#include <gtest/gtest.h>

#include "strut/numeric_less.hpp"

TEST(NumericLessTest, numeric_less)
{
  EXPECT_TRUE(strut::numeric_less("1", "2"));
  EXPECT_TRUE(strut::numeric_less("001", "002"));
  EXPECT_TRUE(strut::numeric_less("999", "1111"));
  EXPECT_TRUE(strut::numeric_less("01", "002"));
  EXPECT_TRUE(strut::numeric_less("01", "02"));

  // FIXME: strut::numeric_less() doesn't deal with leading zero, i.e. "01" > "2"
  // EXPECT_TRUE(strut::numeric_less("01", "2"));
  // EXPECT_TRUE(strut::numeric_less("text01", "text2"));

  EXPECT_TRUE(strut::numeric_less("text10-5", "text10-10"));

  EXPECT_FALSE(strut::numeric_less("1111", "999"));
}

/* EOF */
