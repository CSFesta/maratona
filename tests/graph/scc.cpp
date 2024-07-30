#include "../../src/graph/scc.cpp"
#include <gtest/gtest.h>

class SccTest : public testing::Test {
  protected:
    SccTest() {
        pgb.reserve(8);
        for (u32 i = 0; i < 8; ++i) {
            pgb.emplace_back();
        }
        pgb[0].push_back(1);
        pgb[1].push_back(2);
        pgb[2].push_back(0);
        pgb[3].push_back(4);
        pgb[3].push_back(7);
        pgb[4].push_back(5);
        pgb[5].push_back(0);
        pgb[5].push_back(6);
        pgb[6].push_back(0);
        pgb[6].push_back(2);
        pgb[6].push_back(4);
        pgb[7].push_back(3);
        pgb[7].push_back(5);
    }
    vector<vector<u32>> pgb;
};

TEST_F(SccTest, ThreeSccs) {
    vector<u32> expected = {1, 1, 1, 4, 5, 5, 5, 4};
    vector<u32> test = tarjan(pgb);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
