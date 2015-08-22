#include <gtest/gtest.h>
#define TESTING

#include "multiple.h"
#include "series.h"

TEST(series, multiples_under_some) {
  int i;
  for (i = 0; i < 100; i++) {
    EXPECT_EQ(sum_naturals(i-1), multiples_under(i,1));
  }
}

