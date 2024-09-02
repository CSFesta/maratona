#include "../../src/dsa/pow.cpp"
#include <gtest/gtest.h>

TEST(PowTest, BigNumbers) {
    ASSERT_EQ(pow(2, 1024, 1e9+7), 812734592ull);
    ASSERT_EQ(pow(2, 2048, 1e9+7), 409643880ull);
    ASSERT_EQ(pow(1e9, 893450, 1e9+7), 368097559ull);
}

TEST(PowTest, EdgeCases) {
    ASSERT_EQ(pow(2, 0, 1e9+7), 1ull);
    ASSERT_EQ(pow(0, 2048, 1e9+7), 0ull);
    ASSERT_EQ(pow(0, 0, 1e9+7), 1ull);
}
