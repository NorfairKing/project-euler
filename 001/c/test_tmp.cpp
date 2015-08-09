#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "solution.c"
TEST(problem, easy) {
    EXPECT_EQ(23, solve(10));
}

TEST(problem, correct) {
    EXPECT_EQ(233168, solve(1000));
}
