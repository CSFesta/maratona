#include "../../src/graph/scc.cpp"
#include <gtest/gtest.h>

class SccTest : public testing::Test {
  protected:
    SccTest() {}
    const vector<vector<u32>> pgb = {
        {1}, {2}, {0}, {4, 7}, {5}, {0, 6}, {0, 2, 4}, {3, 5},
    };
    const vector<u32> expected = {1, 1, 1, 4, 5, 5, 5, 4};
};

TEST_F(SccTest, ThreeSccs) {
    vector<u32> test = tarjan(pgb);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
