#include <gtest/gtest.h>
#define TESTING

#include "palindrome.h"

TEST(palindrome, is_palindrome_some) {
  int i;
  for (int i = 0; i < 10; i++){
    // All natural numbers under 10 are palindromes
    EXPECT_TRUE(is_palindrome(i));
  }

  EXPECT_TRUE(is_palindrome(22));
  EXPECT_TRUE(is_palindrome(1221));
  EXPECT_TRUE(is_palindrome(987789));
  EXPECT_FALSE(is_palindrome(20));
  EXPECT_FALSE(is_palindrome(987589));
  EXPECT_FALSE(is_palindrome(985599));
  EXPECT_FALSE(is_palindrome(995588));
}
