#include "../../src/dsa/mdc.cpp"
#include <gtest/gtest.h>

TEST(MDCTest, Primes) {
    ASSERT_EQ(mdc(7, 13), 1);
    ASSERT_EQ(mdc(2, 199'999), 1);
    ASSERT_EQ(mdc(31, 199'999), 1);
}

TEST(MDCTest, CoPrimes) {
    ASSERT_EQ(mdc(69, 230), 23);
    ASSERT_EQ(mdc(69, 12), 3);
    ASSERT_EQ(mdc(8, 64), 8);
}

TEST(MDCTest, EdgeCases) {
    ASSERT_EQ(mdc(31, 0), 31);
    ASSERT_EQ(mdc(0, 0), 0);
    ASSERT_EQ(mdc(0, 31), 31);
    ASSERT_EQ(mdc(1, 31), 1);
}
