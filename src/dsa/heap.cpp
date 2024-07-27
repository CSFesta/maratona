#include "../template.h"

void bottom_up(std::vector<int> &v, int pos) {
    while (v[pos] > v[(pos-1)/2]) {
        std::swap(v[(pos-1)/2], v[pos]);
        pos = (pos-1)/2;
    }
}


void top_down(std::vector<int> &v, int end, int pos) {
    while (pos*2+2 < end && (v[pos] < v[pos*2+1] || v[pos] < v[pos*2+2])) {
        if (v[pos*2+1] < v[pos*2+2]) {
            std::swap(v[pos], v[pos*2+2]);
            pos = pos*2+2;
            continue;
        }
        std::swap(v[pos], v[pos*2+1]);
        pos = pos*2+1;
    }
    if (pos*2+1 < end && v[pos] < v[pos*2+1]) {
        std::swap(v[pos], v[pos*2+1]);
    }
}

void top_down(std::vector<int> &v, int pos) {
    top_down(v, v.size(), pos);
}

void push_heap(std::vector<int> &v, int value) {
    v.push_back(value);
    bottom_up(v, v.size()-1);
}

int pop_heap(std::vector<int> &v) {
    const int ret = v[0];
    std::swap(v[0], v[v.size()-1]);
    v.pop_back();
    top_down(v, 0);
    return ret;
}

void sort(std::vector<int> &v) {
    int size = v.size();
    while (size > 1) {
        std::swap(v[0], v[size-1]);
        top_down(v, --size, 0);
    }
}

void heapify(std::vector<int> &v) {
    for (int i = v.size()/2; i >= 0; --i) {
        top_down(v, i);
    }
}
