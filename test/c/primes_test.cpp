#include <gtest/gtest.h>

// Hide main
#define TESTING
// Hide the io function since this will segfault in testing
#include "primes.h"

TEST(primes, is_prime_under20) {
    EXPECT_FALSE(is_prime(1));
    EXPECT_TRUE(is_prime(2));
    EXPECT_TRUE(is_prime(3));
    EXPECT_FALSE(is_prime(4));
    EXPECT_TRUE(is_prime(5));
    EXPECT_FALSE(is_prime(6));
    EXPECT_TRUE(is_prime(7));
    EXPECT_FALSE(is_prime(8));
    EXPECT_FALSE(is_prime(9));
    EXPECT_FALSE(is_prime(10));
    EXPECT_TRUE(is_prime(11));
    EXPECT_FALSE(is_prime(12));
    EXPECT_TRUE(is_prime(13));
    EXPECT_FALSE(is_prime(14));
    EXPECT_FALSE(is_prime(15));
    EXPECT_FALSE(is_prime(16));
    EXPECT_TRUE(is_prime(17));
    EXPECT_FALSE(is_prime(18));
    EXPECT_TRUE(is_prime(19));
    EXPECT_FALSE(is_prime(20));
}

TEST(primes, sieve) {
    int n = 100;

    bool under_test[n];

    sieve(under_test, n);

    int i;
    for (i = 2; i < n; i++) {
        EXPECT_EQ(is_prime(i), under_test[i]);
    }
}
