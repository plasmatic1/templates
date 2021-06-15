#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> vector<int> bfs01(int N, GraphType &g, initializer_list<int> start) {
    static EdgeType E;
    vector<int> dis(N+1, -1);
    deque<int> q;
    for (auto s : start) {
        q.push_back(s);
        dis[s] = 0;
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (auto _to : g[c]) {
            int to = E.v(_to), w = E.w(_to);
            if (dis[to] == -1 || dis[c]+w < dis[to]) {
                dis[to] = dis[c] + w;
                if (w == 1) q.push_back(to);
                else if (w == 0) q.push_front(to);
                else throw domain_error("in 0/1 bfs weights must be either 0 or 1")
            }
        }
    }
    return dis;
}
