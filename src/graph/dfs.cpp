#include "../template.h"

void dfs(const vector<vector<u32>> &graph, const u32 v, vector<u32> &result,
         u32 &i) {
    if (result[v] != 0) {
        return;
    }
    result[v] = ++i;

    for (const u32 adj : graph[v]) {
        if (result[adj] != 0) {
            continue;
        }
        dfs(graph, adj, result, i);
    }
    return;
}
vector<u32> dfsNoRecursion(const vector<vector<u32>> &graph, u32 start) {
    assert(graph.size() > start && start >= 0);
    vector<u32> result(graph.size(), 0);
    stack<u32> dfs_stack;
    dfs_stack.push(start);
    u32 i = 0;
    u32 current, adj;
    while (!dfs_stack.empty()) {
        current = dfs_stack.top();
        dfs_stack.pop();
        if (result[current] != 0) continue;
        result[current] = ++i;
        assert(i <= graph.size());
        for (i32 j = graph[current].size()-1; j >= 0; --j) {
            adj = graph[current][j];
            if (result[adj] != 0) {
                continue;
            }
            dfs_stack.push(adj);
        }
    }
    return result;
}

vector<u32> dfs(const vector<vector<u32>> &graph, const u32 start) {
    assert(graph.size() > start && start >= 0);
    vector<u32> result(graph.size(), 0);
    u32 i = 0;
    dfs(graph, start, result, i);
    return result;
}

vector<u32> dfs(vector<vector<u32>> &graph) {
    vector<u32> result(graph.size(), 0);
    u32 i;
    for (u32 j = 0; j < result.size(); ++j) {
        dfs(graph, j, result, i);
    }
    return result;
}

bool isReachable(vector<vector<u32>> &graph, u32 start, u32 end) {
    return dfs(graph, start)[end] != 0;
}

bool isConnected(vector<vector<u32>> &graph) {
    vector<u32> result = dfs(graph, 0);
    return find(result.begin(), result.end(), 0u) == result.end();
}
