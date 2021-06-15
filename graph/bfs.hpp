#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> vector<int> bfs(int N, GraphType &g, initializer_list<int> start) {
    static EdgeType E;
    vector<int> dis(N+1, -1);
    queue<int> q;
    for (auto s : start) {
        q.push(s);
        dis[s] = 0;
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (auto _to : g[c]) {
            int to = E.v(_to);
            if (dis[to] == -1) {
                dis[to] = dis[c] + 1;
                q.push(to);
            }
        }
    }
    return dis;
}
