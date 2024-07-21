#include <bits/stdc++.h>
#include <queue>
#include <vector>

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef float       f32;
typedef double      f64;
typedef long double f80;

#define I8MAX INT8_MAX
#define I8MIN INT8_MIN
#define I16MAX INT16_MAX
#define I16MIN INT16_MIN
#define I32MAX INT32_MAX
#define I32MIN INT32_MIN
#define I64MAX INT64_MAX
#define I64MIN INT64_MIN
#define U8MAX UINT8_MAX
#define U16MAX UINT16_MAX
#define U32MAX UINT32_MAX
#define U64MAX UINT64_MAX

using namespace std;

// weighted edge
typedef pair<u32, u32> wedge;

u32 prim(vector<vector<wedge>> &graph) {
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
        printf("%u %u\n", cur.first, cur.second);
        pq.pop();
        if (visited[cur.first]) {
            continue;
        }
        visited[cur.first] = true;
        printf("banana bread %u %u\n", cur.first, cur.second);

        for (const wedge adj : graph[cur.first]) {
            if (visited[adj.first]) {
                continue;
            }
            if (min_dist[adj.first] <= adj.second) {
                continue; 
            }
            min_dist[adj.first] = adj.second;
            pq.push(adj);
        }
    }
    u32 acc = 0;
    for (u32 v : min_dist) acc += v;
    return acc;
}

// tests
int main(void) {
    u32 nof_v, nof_e, v, u, w;

    scanf("%u %u", &nof_v, &nof_e);

    vector<vector<wedge>> graph(nof_v);

    for (u32 i = 0; i < nof_e; ++i) {
        scanf("%u %u %u", &v, &u, &w);
        graph[v].emplace_back(u, w);
        graph[u].emplace_back(v, w);
    }

    printf("%u\n", prim(graph));
    
    return 0;
}
