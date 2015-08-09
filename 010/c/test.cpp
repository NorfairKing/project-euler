TEST(problem, easy) {
    EXPECT_EQ(17, solve(10));
}

TEST(problem, correct) {
    EXPECT_EQ(142913828922, solve(2000000));
}
