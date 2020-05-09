#include "LeapTestCase.h"
#include "Functions.h"

bool LeapTestCase::LeapYear(int year) {
    return IsLeap(year);
}

TEST(LeapTestCase, YearDividedByHundred) {
    ASSERT_FALSE(LeapTestCase::LeapYear(1900));
}

TEST(LeapTestCase, OddNumberedYear) {
    ASSERT_FALSE(LeapTestCase::LeapYear(2019));
}

TEST(LeapTestCase, EvenNumberedYear) {
    ASSERT_FALSE(LeapTestCase::LeapYear(2018));
}

TEST(LeapTestCase, YearDividedByFour) {
    ASSERT_TRUE(LeapTestCase::LeapYear(2020));
}

TEST(LeapTestCase, YearDividedByFourHundred) {
    ASSERT_TRUE(LeapTestCase::LeapYear(2400));
}

TEST(LeapTestCase, NegativeYear) {
    ASSERT_THROW(LeapTestCase::LeapYear(-1), std::invalid_argument);
}

TEST(LeapTestCase, ZeroYear) {
    ASSERT_THROW(LeapTestCase::LeapYear(0), std::invalid_argument);
}
