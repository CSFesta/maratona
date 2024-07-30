#include "../template.h"
#include <vector>

void dfs(const vector<vector<u32>> &graph, const u32 v, vector<u32> &result,
         u32 &i, stack<u32> &tarjan_stack, vector<bool> &on_stack, vector<u32> &lowest) {
    tarjan_stack.push(v);
    on_stack[v] = true;
    lowest[v] = result[v] = ++i;

    for (const u32 adj : graph[v]) {
        if (result[adj] == 0) {
            dfs(graph, adj, result, i, tarjan_stack, on_stack, lowest);
        }
        if (on_stack[adj]) {
            lowest[v] = min(lowest[v], lowest[adj]); 
        }
    }
    if (result[v] == lowest[v]) {
        u32 node = tarjan_stack.top();
        tarjan_stack.pop();
        for (;; node = tarjan_stack.top(), tarjan_stack.pop()) {
            on_stack[node] = false;
            //lowest[node] = result[v];
            if (node == v) break;
        }
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

vector<u32> tarjan(vector<vector<u32>> &graph) {
    vector<u32> result(graph.size(), 0);
    vector<u32> lowest(graph.size(), 0);
    u32 i;
    stack<u32> tarjan_stack;
    vector<bool> on_stack(graph.size());
    for (u32 j = 0; j < result.size(); ++j) {
        if (result[j] != 0) continue;
        dfs(graph, j, result, i, tarjan_stack, on_stack, lowest);
    }
    return lowest;
}
