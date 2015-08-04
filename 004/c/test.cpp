#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
#include "solution.c"

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problem, easy) {
    EXPECT_EQ(9009, solve(2));
}

TEST(problem, correct) {
    EXPECT_EQ(906609, solve(3));
}
