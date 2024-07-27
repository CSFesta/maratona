#include "../template.h"

typedef uint32_t    u32;

#define U32MAX UINT32_MAX

using namespace std;

// weighted edge
typedef pair<u32, u32> wedge;

vector<u32> dijkstra(const vector<vector<wedge>> &graph, const u32 start, const u32 dest) {
    const auto min_cmp = [](const wedge& a, const wedge& b) {
        return a.second > b.second;
    };
    priority_queue<wedge, vector<wedge>, decltype(min_cmp)> pq{min_cmp};
    vector<bool> visited(graph.size());
    vector<u32> min_dist(graph.size(), U32MAX);
    min_dist[start] = 0;
    pq.emplace(start, 0);
    while (!pq.empty()) {
        wedge cur = pq.top();
        pq.pop();
        if (visited[cur.first]) {
            continue;
        }
        if (cur.first == dest) {
            return min_dist;
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

vector<u32> dijkstra(const vector<vector<wedge>> &graph, const u32 start) {
    return dijkstra(graph, start, graph.size());
}

vector<u32> dijkstra(const vector<vector<wedge>> &graph) {
    return dijkstra(graph, 0);
}

u32 dijkstraSingleDest(const vector<vector<wedge>> &graph, const u32 start, const u32 dest) {
    return dijkstra(graph, start, dest)[dest];
}
