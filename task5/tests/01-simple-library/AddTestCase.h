#ifndef ADD_TEST_CASE
#define ADD_TEST_CASE

#include <gtest/gtest.h>

class AddTestCase: public ::testing::Test {
public:
    static int TestAdd(int x, int y);
};

#endif
