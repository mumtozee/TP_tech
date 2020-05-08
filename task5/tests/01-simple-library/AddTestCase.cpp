// Arslan Khabutdinov krasavcik
// Pavel Akhtyamov krasavcik

#include "AddTestCase.h"
#include "Functions.h"

int AddTestCase::TestAdd(int x, int y) {
    return x + y;
}

TEST(AddTestCase, Negative_Plus_Positive) {
    ASSERT_EQ(Add(-1, 2), AddTestCase::TestAdd(-1, 2));
}

TEST(AddTestCase, Positive_Plus_Negative) {
    ASSERT_EQ(Add(2, -3), AddTestCase::TestAdd(2, -3));
}

TEST(AddTestCase, Zero_Plus_Positive) {
    ASSERT_EQ(Add(0, 11), AddTestCase::TestAdd(0, 11));
}

TEST(AddTestCase, Negative_Plus_Zero) {
    ASSERT_EQ(Add(-12, 0), AddTestCase::TestAdd(-12, 0));
}

TEST(AddTestCase, Zero_Plus_Zero) {
    ASSERT_EQ(Add(0, 0), AddTestCase::TestAdd(0, 0));
}

TEST(AddTestCase, Positive_Plus_Positive) {
    ASSERT_EQ(Add(10, 30), AddTestCase::TestAdd(10, 30));
}

TEST(AddTestCase, Negative_Plus_Negative) {
    ASSERT_EQ(Add(-100, -300), AddTestCase::TestAdd(-100, -300));
}
