#include "../../src/graph/cycle.cpp"
#include <gtest/gtest.h>

class CycleTest : public testing::Test {
  protected:
    CycleTest() {}
    const std::vector<std::vector<u32>> pgb = {
        {2, 4, 5}, {4, 5}, {0, 3, 4}, {2},    {0, 1, 2, 5, 7},
        {0, 1, 4}, {7},    {4, 6, 8}, {7, 9}, {8}};
    const std::vector<std::vector<u32>> degen = {{1}, {2}, {3}, {4}, {5},
                                                 {6}, {7}, {8}, {}};
    const std::vector<std::vector<u32>> ring = {{1}, {2}, {3}, {4}, {5},
                                                 {6}, {7}, {8}, {0}};
};

TEST_F(CycleTest, PGB) { EXPECT_TRUE(cycle(pgb)); }
TEST_F(CycleTest, degenerate) { EXPECT_FALSE(cycle(degen)); }
TEST_F(CycleTest, ring) { EXPECT_TRUE(cycle(ring)); }
