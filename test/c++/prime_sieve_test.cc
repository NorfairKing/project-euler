#include <gtest/gtest.h>
#define TESTING

#include "prime_sieve.h"

#include <iostream>

TEST(prime_sieve, is_prime_under20) {
  prime_sieve is_prime;

  EXPECT_FALSE(is_prime[1]);
  EXPECT_TRUE (is_prime[2]);
  EXPECT_TRUE (is_prime[3]);
  EXPECT_FALSE(is_prime[4]);
  EXPECT_TRUE (is_prime[5]);
  EXPECT_FALSE(is_prime[6]);
  EXPECT_TRUE (is_prime[7]);
  EXPECT_FALSE(is_prime[8]);
  EXPECT_FALSE(is_prime[9]);
  EXPECT_FALSE(is_prime[10]);
  EXPECT_TRUE (is_prime[11]);
  EXPECT_FALSE(is_prime[12]);
  EXPECT_TRUE (is_prime[13]);
  EXPECT_FALSE(is_prime[14]);
  EXPECT_FALSE(is_prime[15]);
  EXPECT_FALSE(is_prime[16]);
  EXPECT_TRUE (is_prime[17]);
  EXPECT_FALSE(is_prime[18]);
  EXPECT_TRUE (is_prime[19]);
  EXPECT_FALSE(is_prime[20]);
}

TEST(prime_sieve, is_prime_under20_jumps) {
  prime_sieve is_prime;

  EXPECT_FALSE(is_prime[1]);
  EXPECT_FALSE(is_prime[10]);
  EXPECT_TRUE (is_prime[11]);
  EXPECT_TRUE (is_prime[17]);
  EXPECT_TRUE (is_prime[29]);
  EXPECT_FALSE(is_prime[20]);
  EXPECT_FALSE(is_prime[200]);
  EXPECT_TRUE (is_prime[317]);
  EXPECT_FALSE(is_prime[2000]);
}
