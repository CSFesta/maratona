#include "../../src/graph/dfs.cpp"
#include <gtest/gtest.h>

TEST(DfsPGB, Graph) {
    vector<u32> expected = {1,5,2,3,4,6,8,7,9,10};
    vector<vector<u32>> graph(10);
    graph[0].push_back(2);
    graph[0].push_back(4);
    graph[0].push_back(5);
    graph[1].push_back(4);
    graph[1].push_back(5);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(2);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(5);
    graph[4].push_back(7);
    graph[5].push_back(0);
    graph[5].push_back(1);
    graph[5].push_back(4);
    graph[6].push_back(7);
    graph[7].push_back(4);
    graph[7].push_back(6);
    graph[7].push_back(8);
    graph[8].push_back(7);
    graph[8].push_back(9);
    graph[9].push_back(8);
    vector<u32> test = dfs(graph, 0);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i;
    }
}
