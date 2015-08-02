#include <gtest/gtest.h>

// Hide main
#define TESTING
// Hide the io function since this will segfault in testing
#include "factors.h"
#include "primes.h"

TEST(factors, divides_zero) {
    EXPECT_TRUE(divides(1, 0));
    EXPECT_TRUE(divides(2, 0));
    EXPECT_TRUE(divides(3, 0));
    EXPECT_FALSE(divides(0, 0));
    EXPECT_FALSE(divides(0, 1));
    EXPECT_FALSE(divides(0, 2));
    EXPECT_FALSE(divides(0, 3));
}

TEST(factors, divides_l_zero) {
    EXPECT_TRUE(divides_l(1, 0));
    EXPECT_TRUE(divides_l(2, 0));
    EXPECT_TRUE(divides_l(3, 0));
    EXPECT_FALSE(divides_l(0, 0));
    EXPECT_FALSE(divides_l(0, 1));
    EXPECT_FALSE(divides_l(0, 2));
    EXPECT_FALSE(divides_l(0, 3));
}

TEST(factors, divides_simple) {
    EXPECT_TRUE(divides(1, 1));
    EXPECT_TRUE(divides(1, 2));
    EXPECT_TRUE(divides(1, 3));
    EXPECT_TRUE(divides(2, 2));
    EXPECT_TRUE(divides(2, 4));
    EXPECT_TRUE(divides(3, 3));
    EXPECT_TRUE(divides(3, 6));
    EXPECT_FALSE(divides(2, 1));
    EXPECT_FALSE(divides(3, 1));
    EXPECT_FALSE(divides(2, 3));
    EXPECT_FALSE(divides(4, 6));
    EXPECT_FALSE(divides(5, 6));
    EXPECT_FALSE(divides(7, 6));
}

TEST(factors, divides_l_simple) {
    EXPECT_TRUE(divides_l(1, 1));
    EXPECT_TRUE(divides_l(1, 2));
    EXPECT_TRUE(divides_l(1, 3));
    EXPECT_TRUE(divides_l(2, 2));
    EXPECT_TRUE(divides_l(2, 4));
    EXPECT_TRUE(divides_l(3, 3));
    EXPECT_TRUE(divides_l(3, 6));
    EXPECT_FALSE(divides_l(2, 1));
    EXPECT_FALSE(divides_l(3, 1));
    EXPECT_FALSE(divides_l(2, 3));
    EXPECT_FALSE(divides_l(4, 6));
    EXPECT_FALSE(divides_l(5, 6));
    EXPECT_FALSE(divides_l(7, 6));
}

TEST(factors, nr_divisors_primes) {
    int n = 100;  // arbitrary
    int i;
    for (i = 2; i < n; i++) {
        if (is_prime(i)) {
            EXPECT_EQ(1, nr_divisors(i));
        }
    }
}

TEST(factors, nr_divisors_until_20) {
    EXPECT_EQ(0, nr_divisors(0));   // none
    EXPECT_EQ(1, nr_divisors(1));   // 1
    EXPECT_EQ(1, nr_divisors(2));   // prime
    EXPECT_EQ(1, nr_divisors(3));   // prime
    EXPECT_EQ(2, nr_divisors(4));   // 1, 2
    EXPECT_EQ(1, nr_divisors(5));   // prime
    EXPECT_EQ(3, nr_divisors(6));   // 1, 2, 3
    EXPECT_EQ(1, nr_divisors(7));   // prime
    EXPECT_EQ(3, nr_divisors(8));   // 1, 2, 4
    EXPECT_EQ(2, nr_divisors(9));   // 1, 3
    EXPECT_EQ(3, nr_divisors(10));  // 1, 2, 5
    EXPECT_EQ(1, nr_divisors(11));  // prime
    EXPECT_EQ(5, nr_divisors(12));  // 1, 2, 3, 4, 6
    EXPECT_EQ(1, nr_divisors(13));  // prime
    EXPECT_EQ(3, nr_divisors(14));  // 1, 2, 7
    EXPECT_EQ(3, nr_divisors(15));  // 1, 3, 5
    EXPECT_EQ(4, nr_divisors(16));  // 1, 2, 4, 8
    EXPECT_EQ(1, nr_divisors(17));  // prime
    EXPECT_EQ(5, nr_divisors(18));  // 1, 2, 3, 6, 9
    EXPECT_EQ(1, nr_divisors(19));  // prime
    EXPECT_EQ(5, nr_divisors(20));  // 1, 2, 4, 5, 10
}

TEST(factors, fill_nr_divisors) {
    int n = 100;

    int under_test[n];
    
    fill_nr_divisors(under_test, n);

    int i;
    for (i = 0; i < n; i++) {
        EXPECT_EQ(nr_divisors(i), under_test[i]);
    }
}

TEST(factors, sum_divisors_until_20) {
    EXPECT_EQ(0, sum_divisors(0));   // none
    EXPECT_EQ(1, sum_divisors(1));   // 1
    EXPECT_EQ(1, sum_divisors(2));   // prime
    EXPECT_EQ(1, sum_divisors(3));   // prime
    EXPECT_EQ(3, sum_divisors(4));   // 1, 2
    EXPECT_EQ(1, sum_divisors(5));   // prime
    EXPECT_EQ(6, sum_divisors(6));   // 1, 2, 3
    EXPECT_EQ(1, sum_divisors(7));   // prime
    EXPECT_EQ(7, sum_divisors(8));   // 1, 2, 4
    EXPECT_EQ(4, sum_divisors(9));   // 1, 3
    EXPECT_EQ(8, sum_divisors(10));  // 1, 2, 5
    EXPECT_EQ(1, sum_divisors(11));  // prime
    EXPECT_EQ(16, sum_divisors(12)); // 1, 2, 3, 4, 6
    EXPECT_EQ(1, sum_divisors(13));  // prime
    EXPECT_EQ(10, sum_divisors(14)); // 1, 2, 7
    EXPECT_EQ(9, sum_divisors(15));  // 1, 3, 5
    EXPECT_EQ(15, sum_divisors(16)); // 1, 2, 4, 8
    EXPECT_EQ(1, sum_divisors(17));  // prime
    EXPECT_EQ(21, sum_divisors(18)); // 1, 2, 3, 6, 9
    EXPECT_EQ(1, sum_divisors(19));  // prime
    EXPECT_EQ(22, sum_divisors(20));  // 1, 2, 4, 5, 10
}

TEST(factors, fill_sum_divisors) {
    int n = 100;

    int under_test[n];
    
    fill_sum_divisors(under_test, n);

    int i;
    for (i = 0; i < n; i++) {
        EXPECT_EQ(sum_divisors(i), under_test[i]);
    }
}
