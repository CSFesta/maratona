#include "../template.h"
#include <vector>

struct node {
    u32 parent;
    u32 size;
};

vector<node> make_set(u32 n) {
    vector<node> result(n);
    for (u32 i = 0; i < n; ++i) {
        result[i].parent = i;
        result[i].size = 1;
    }
    return result;
}

u32 find(vector<node> &forest, u32 x) {
    while (forest[x].parent != x) {
        forest[x].parent = forest[forest[x].parent].parent;
        x = forest[x].parent;
    }
    return x;
}

void merge(vector<node> &forest, u32 x, u32 y) {
    x = find(forest, x);
    y = find(forest, y);
    if (x==y) return;

    if (forest[x].size < forest[y].size) {
        swap(x, y);
    }

    forest[y].parent = x;

    forest[x].size += forest[y].size;
    return;
}
