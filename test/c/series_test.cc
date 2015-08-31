#include <gtest/gtest.h>
#define TESTING

#include "series.h"

TEST(series, sum_naturals_some) {
  int sum = 0; int i;
  for (i = 0; i < 100; i++) {
    sum += i;
    EXPECT_EQ(sum, sum_naturals(i));
  }
}

