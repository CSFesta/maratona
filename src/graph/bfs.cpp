#include "../template.h"

vector<u32> bfs(const vector<vector<u32>> &graph, u32 start) {
    assert(graph.size() > start && start >= 0);
    vector<u32> result(graph.size(), 0);
    vector<bool> visited(graph.size());
    queue<u32> bfs_queue;
    bfs_queue.push(start);
    visited[start] = true;
    u32 current, adj;
    while (!bfs_queue.empty()) {
        current = bfs_queue.front();
        bfs_queue.pop();
        for (i32 j = graph[current].size()-1; j >= 0; --j) {
            adj = graph[current][j];
            if (visited[adj]) {
                continue;
            }
            visited[adj] = true;
            result[adj] = result[current]+1;
            bfs_queue.push(adj);
        }
    }
    return result;
}

bool isReachable(vector<vector<u32>> &graph, u32 start, u32 end) {
    return bfs(graph, start)[end] != 0;
}

bool isConnected(vector<vector<u32>> &graph) {
    vector<u32> result = bfs(graph, 0);
    return find(result.begin(), result.end(), 0u) == result.end();
}

// TODO tile based bfs
