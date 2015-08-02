#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
#include "solution.c"

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problem, easy) {
    EXPECT_EQ(29, solve(13195));
}

TEST(problem, correct) {
    EXPECT_EQ(6857, solve(600851475143));
}
