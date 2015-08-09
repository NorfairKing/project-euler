#include <stdio.h>
#include <gtest/gtest.h>

#define TESTING
GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "solution.c"
