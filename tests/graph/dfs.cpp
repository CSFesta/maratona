#include "../../src/graph/dfs.cpp"
#include <gtest/gtest.h>

class DfsTest : public testing::Test {
  protected:
    DfsTest() {
        pgb.reserve(10);
        for (u32 i = 0; i < 10; ++i) {
            pgb.emplace_back();
        }
        pgb[0].push_back(2);
        pgb[0].push_back(4);
        pgb[0].push_back(5);
        pgb[1].push_back(4);
        pgb[1].push_back(5);
        pgb[2].push_back(0);
        pgb[2].push_back(3);
        pgb[2].push_back(4);
        pgb[3].push_back(2);
        pgb[4].push_back(0);
        pgb[4].push_back(1);
        pgb[4].push_back(2);
        pgb[4].push_back(5);
        pgb[4].push_back(7);
        pgb[5].push_back(0);
        pgb[5].push_back(1);
        pgb[5].push_back(4);
        pgb[6].push_back(7);
        pgb[7].push_back(4);
        pgb[7].push_back(6);
        pgb[7].push_back(8);
        pgb[8].push_back(7);
        pgb[8].push_back(9);
        pgb[9].push_back(8);
    }
    vector<vector<u32>> pgb;
};

TEST_F(DfsTest, DfsPGB) {
    vector<u32> expected = {1, 5, 2, 3, 4, 6, 8, 7, 9, 10};
    vector<u32> test = dfs(pgb, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}

TEST_F(DfsTest, DfsPGBisConnected) {
    EXPECT_TRUE(isConnected(pgb));
}

TEST_F(DfsTest, DfsPGBisReachable) {
    EXPECT_TRUE(isReachable(pgb, 0, 9));
}

TEST_F(DfsTest, DfsPGBNoRecursion) {
    vector<u32> expected = {1, 5, 2, 3, 4, 6, 8, 7, 9, 10};
    vector<u32> test = dfsNoRecursion(pgb, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
