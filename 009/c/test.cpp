#include "testmain.cpp"
#include "solution.c"

TEST(problem, correct) {
    EXPECT_EQ(31875000, solve(1000));
}
