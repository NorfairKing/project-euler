#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
#include "solution.c"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problem, easy) {
    EXPECT_EQ(23, solve(10));
}

TEST(problem, correct) {
    EXPECT_EQ(233168, solve(1000));
}
