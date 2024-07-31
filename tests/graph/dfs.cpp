#include "../../src/graph/dfs.cpp"
#include <gtest/gtest.h>

class DfsTest : public testing::Test {
  protected:
    DfsTest() {}
    const std::vector<std::vector<u32>> pgb = {
        {2, 4, 5}, {4, 5}, {0, 3, 4}, {2},    {0, 1, 2, 5, 7},
        {0, 1, 4}, {7},    {4, 6, 8}, {7, 9}, {8}};
    const vector<u32> expected = {1, 5, 2, 3, 4, 6, 8, 7, 9, 10};
};

TEST_F(DfsTest, DfsPGB) {
    vector<u32> test = dfs(pgb, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}

TEST_F(DfsTest, DfsPGBisConnected) { EXPECT_TRUE(isConnected(pgb)); }

TEST_F(DfsTest, DfsPGBisReachable) { EXPECT_TRUE(isReachable(pgb, 0, 9)); }

TEST_F(DfsTest, DfsPGBNoRecursion) {
    vector<u32> test = dfsNoRecursion(pgb, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
