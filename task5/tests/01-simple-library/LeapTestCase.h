#ifndef LEAP_TEST_CASE
#define LEAP_TEST_CASE

#include <gtest/gtest.h>

class LeapTestCase : public ::testing::Test {
public:
    static bool LeapYear(int year);
};

#endif
