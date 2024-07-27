#include "../../src/graph/dijkstra.cpp"
#include <gtest/gtest.h>

class DijkstraTest : public testing::Test {
  protected:
    DijkstraTest() {
        for (u32 i = 0; i < 10; ++i) {
            pgb.emplace_back();
        }
        pgb[0].emplace_back(2, 1);
        pgb[0].emplace_back(4, 2);
        pgb[0].emplace_back(5, 2);
        pgb[1].emplace_back(4, 3);
        pgb[1].emplace_back(5, 4);
        pgb[2].emplace_back(3, 5);
        pgb[3].emplace_back(7, 8);
        pgb[3].emplace_back(9, 12);
        pgb[4].emplace_back(2, 8);
        pgb[4].emplace_back(5, 10);
        pgb[4].emplace_back(6, 11);
        pgb[4].emplace_back(7, 12);
        pgb[6].emplace_back(7, 6);
        pgb[7].emplace_back(8, 1);
        pgb[8].emplace_back(9, 2);
    }
    vector<vector<wedge>> pgb;
};

TEST_F(DijkstraTest, PGB) {
    vector<u32> expected = {0, U32MAX, 1, 6, 2, 2, 13, 14, 15, 17};
    vector<u32> test = dijkstra(pgb);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}

TEST_F(DijkstraTest, PGBPart2) {
    EXPECT_EQ(dijkstraSingleDest(pgb, 0, 9), 17);
}
