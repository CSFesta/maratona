#include "../../src/graph/dijkstra.cpp"
#include <gtest/gtest.h>

TEST(DijkstraTest, PGB) {
    vector<u32> expected = {0, U32MAX, 1, 6, 2, 2, 13, 14, 15, 17};
    vector<vector<wedge>> graph(10);
    graph[0].emplace_back(2, 1);
    graph[0].emplace_back(4, 2);
    graph[0].emplace_back(5, 2);
    graph[1].emplace_back(4, 3);
    graph[1].emplace_back(5, 4);
    graph[2].emplace_back(3, 5);
    graph[3].emplace_back(7, 8);
    graph[3].emplace_back(9, 12);
    graph[4].emplace_back(2, 8);
    graph[4].emplace_back(5, 10);
    graph[4].emplace_back(6, 11);
    graph[4].emplace_back(7, 12);
    graph[6].emplace_back(7, 6);
    graph[7].emplace_back(8, 1);
    graph[8].emplace_back(9, 2);
    vector<u32> test = dijkstra(graph);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
