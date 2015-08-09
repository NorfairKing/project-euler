#include "testmain.cpp"
#include "solution.c"

TEST(problem, easy) {
    EXPECT_EQ(13, solve(6));
}

TEST(problem, correct) {
    EXPECT_EQ(104743, solve(10001));
}
