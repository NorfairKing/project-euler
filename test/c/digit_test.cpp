#include <gtest/gtest.h>

// Hide main
#define TESTING
// Hide the io function since this will segfault in testing
#include "digit.h"

TEST(digit, nr_of_digits_some) {
    int i;
    for (i = 0; i < 10; i++){
        EXPECT_EQ(1, nr_of_digits(i));
    }
    EXPECT_EQ(2, nr_of_digits(89));
    EXPECT_EQ(3, nr_of_digits(123));
    EXPECT_EQ(5, nr_of_digits(46587));
    EXPECT_EQ(7, nr_of_digits(4568987));
}

TEST(digit, digit_some) {
    int i;
    for (i = 0; i < 10; i++){
        EXPECT_EQ(i, digit(0,i));
    }
    EXPECT_EQ(1,digit(0,1));
    EXPECT_EQ(0,digit(1,1));
    EXPECT_EQ(2,digit(1,21));
    EXPECT_EQ(4,digit(1,4941));
}

TEST(digit, from_digits) {
    int digits1[] = {4,5,6,6};
    EXPECT_EQ(4566, from_digits(digits1, 4));
    int digits2[] = {2};
    EXPECT_EQ(2, from_digits(digits2, 1));
}
