#include "testmain.cpp"
#include "solution.c"

TEST(problem, easy) {
    EXPECT_EQ(44, solve(100));
}

TEST(problem, correct) {
    EXPECT_EQ(4613732, solve(4000000));
}
