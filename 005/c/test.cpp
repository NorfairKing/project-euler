#include "testmain.cpp"
#include "solution.c"

TEST(problem, easy) {
    EXPECT_EQ(2520, solve(10));
}

TEST(problem, correct) {
    EXPECT_EQ(232792560, solve(20));
}
