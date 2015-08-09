TEST(problem, easy) {
    EXPECT_EQ(23, solve(10));
}

TEST(problem, correct) {
    EXPECT_EQ(233168, solve(1000));
}
