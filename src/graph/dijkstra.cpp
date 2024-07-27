#include "../template.h"

typedef uint32_t    u32;

#define U32MAX UINT32_MAX

using namespace std;

// weighted edge
typedef pair<u32, u32> wedge;

vector<u32> dijkstra(vector<vector<wedge>> &graph) {
    const auto min_cmp = [](const wedge& a, const wedge& b) {
        return a.second > b.second;
    };
    priority_queue<wedge, vector<wedge>, decltype(min_cmp)> pq{min_cmp};
    vector<bool> visited(graph.size());
    vector<u32> min_dist(graph.size(), U32MAX);
    min_dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        wedge cur = pq.top();
        pq.pop();
        if (visited[cur.first]) {
            continue;
        }
        visited[cur.first] = true;

        for (const wedge adj : graph[cur.first]) {
            if (visited[adj.first]) {
                continue;
            }
            u32 distance = adj.second + cur.second;
            if (min_dist[adj.first] <= distance) {
                continue; 
            }
            min_dist[adj.first] = distance;
            pq.emplace(adj.first, distance);
        }
    }
    return min_dist;
}
