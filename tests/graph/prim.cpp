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

TEST(PrimTest, Lucas) {
    vector<vector<wedge>> graph(7);
    graph[0].emplace_back(1, 28);
    graph[1].emplace_back(0, 28);
    graph[0].emplace_back(5, 10);
    graph[5].emplace_back(0, 10);
    graph[1].emplace_back(2, 16);
    graph[2].emplace_back(1, 16);
    graph[1].emplace_back(6, 14);
    graph[6].emplace_back(1, 14);
    graph[2].emplace_back(3, 12);
    graph[3].emplace_back(2, 12);
    graph[3].emplace_back(4, 22);
    graph[4].emplace_back(3, 22);
    graph[3].emplace_back(6, 18);
    graph[6].emplace_back(3, 18);
    graph[4].emplace_back(5, 25);
    graph[5].emplace_back(4, 25);
    graph[4].emplace_back(6, 24);
    graph[6].emplace_back(4, 24);
    EXPECT_EQ(prim(graph), 99);
}
TEST(PrimTest, Lucas2) {
    vector<vector<wedge>> graph(7);
    graph[0].emplace_back(1, 1);
    graph[1].emplace_back(0, 1);
    graph[0].emplace_back(2, 5);
    graph[2].emplace_back(0, 5);
    graph[1].emplace_back(2, 4);
    graph[2].emplace_back(1, 4);
    graph[1].emplace_back(3, 8);
    graph[3].emplace_back(1, 8);
    graph[1].emplace_back(4, 7);
    graph[4].emplace_back(1, 7);
    graph[2].emplace_back(3, 6);
    graph[3].emplace_back(2, 6);
    graph[2].emplace_back(5, 2);
    graph[5].emplace_back(2, 2);
    graph[3].emplace_back(4, 11);
    graph[4].emplace_back(3, 11);
    graph[3].emplace_back(5, 9);
    graph[5].emplace_back(3, 9);
    graph[4].emplace_back(5, 3);
    graph[5].emplace_back(4, 3);
    graph[4].emplace_back(6, 10);
    graph[6].emplace_back(4, 10);
    graph[5].emplace_back(6, 12);
    graph[6].emplace_back(5, 12);

    EXPECT_EQ(prim(graph), 26);
}
