#include "../../src/graph/prim.cpp"
#include <gtest/gtest.h>

TEST(PrimTest, CodeAtNight2024_2) {
    const vector<vector<wedge>> graph = {{{1, 10}, {2, 40}},
                                         {{0, 10}, {3, 30}},
                                         {{0, 40}, {3, 20}},
                                         {{1, 30}, {2, 20}}};
    EXPECT_EQ(prim(graph), 60);
}

TEST(PrimTest, MadeUp1) {
    const vector<vector<wedge>> graph = {
        {{3, 1}, {1, 8}},          {{3, 2}, {4, 3}, {0, 8}, {2, 7}},
        {{4, 4}, {1, 7}},          {{0, 1}, {1, 2}, {4, 10}},
        {{1, 3}, {2, 4}, {3, 10}},
    };
    EXPECT_EQ(prim(graph), 10);
}
