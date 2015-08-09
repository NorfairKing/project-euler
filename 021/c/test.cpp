#include "testmain.cpp"
#include "solution.c"

TEST(problem, correct) {
    EXPECT_EQ(31626, solve(10000));
}
