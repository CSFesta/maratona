#include "../template.h"

bool cycle(const vector<vector<u32>> &graph, u32 start) {
    assert(graph.size() > start && start >= 0);
    stack<u32> dfs_stack;
    vector<bool> visited(graph.size(), false);
    dfs_stack.push(start);
    u32 current, adj;
    while (!dfs_stack.empty()) {
        current = dfs_stack.top();
        dfs_stack.pop();
        if (visited[current]) continue;
        visited[current] = true;
        for (i32 j = graph[current].size()-1; j >= 0; --j) {
            adj = graph[current][j];
            if (visited[adj]) {
                return true;
            }
            dfs_stack.push(adj);
        }
    }
    return false;
}

bool cycle(const vector<vector<u32>> &graph) {
    bool result = false;
    u32 i;
    for (u32 j = 0; j < graph.size(); ++j) {
        result |= cycle(graph, 0);
    }
    return result;
}
