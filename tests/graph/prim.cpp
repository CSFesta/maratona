#include <gtest/gtest.h>
#include "../../src/graph/prim.cpp"

TEST(PrimTestCodeAtNight2024_2, Graph) {
    vector<vector<wedge>> graph(4);
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 40);
    graph[1].emplace_back(0, 10);
    graph[1].emplace_back(3, 30);
    graph[2].emplace_back(0, 40);
    graph[2].emplace_back(3, 20);
    graph[3].emplace_back(1, 30);
    graph[3].emplace_back(2, 20);
    EXPECT_EQ(prim(graph), 60);
}

TEST(PrimTestMadeUp1, Graph) {
    vector<vector<wedge>> graph(5);
    graph[0].emplace_back(3, 1);
    graph[3].emplace_back(0, 1);
    graph[3].emplace_back(1, 2);
    graph[1].emplace_back(3, 2);
    graph[1].emplace_back(4, 3);
    graph[4].emplace_back(1, 3);
    graph[4].emplace_back(2, 4);
    graph[2].emplace_back(4, 4);
    graph[1].emplace_back(2, 7);
    graph[2].emplace_back(1, 7);
    graph[1].emplace_back(0, 8);
    graph[0].emplace_back(1, 8);
    graph[3].emplace_back(4, 10);
    graph[4].emplace_back(3, 10);
    EXPECT_EQ(prim(graph), 10);
}
