#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
#include "factors.h"
#include "solution.c"

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problem, easy) {
    EXPECT_EQ(44, solve(100));
}

TEST(problem, correct) {
    EXPECT_EQ(4613732, solve(4000000));
}
