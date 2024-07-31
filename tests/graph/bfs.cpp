#include "../../src/graph/bfs.cpp"
#include <gtest/gtest.h>

class BfsTest : public testing::Test {
  protected:
    BfsTest() {}
    const std::vector<std::vector<u32>> pgb = {
        {2, 4, 5}, {4, 5}, {0, 3, 4}, {2},    {0, 1, 2, 5, 7},
        {0, 1, 4}, {7},    {4, 6, 8}, {7, 9}, {8}};
    const vector<u32> expected = {0, 2, 1, 2, 1, 1, 3, 2, 3, 4};
};

TEST_F(BfsTest, BfsPGB) {
    vector<u32> test = bfs(pgb, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
