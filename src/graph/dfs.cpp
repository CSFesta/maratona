#include "../template.h"

void dfs(vector<vector<u32>> &graph, u32 v, vector<u32> &result, u32 &i) {
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

vector<u32> dfs(vector<vector<u32>> &graph, u32 start) {
    vector<bool> visited(graph.size());
    vector<u32> result(graph.size(), 0);
    result[start] = 0;
    u32 i;
    dfs(graph, start, result, i);
    return result;
}
