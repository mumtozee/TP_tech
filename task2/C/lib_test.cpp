#include "A/index.h"
#include "B/lib.h"

#include <gtest/gtest.h>

TEST(TestIndex, IsTrue) {
  EXPECT_TRUE(index_f(0));
}

TEST(TestMainLib, IsLibTrue) {
  EXPECT_TRUE(lib_f());
}
