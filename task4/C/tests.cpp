#include <gtest/gtest.h>
#include "main.h"

TEST(DefaultCheck, TestClass) {
    ASSERT_EQ(2 + 2, 4);
}

TEST(CheckClass, TestClass) {
    ClassLib x;
    x.Set(6);

    ASSERT_EQ(x.Get(), 6);
}
