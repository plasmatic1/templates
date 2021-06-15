#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> vector<typename EdgeType::WeightType> spfa(int N, GraphType &g, initializer_list<int> start, typename EdgeType::WeightType initDis) {
    static EdgeType E;
    using w_t = typename EdgeType::WeightType;
    vector<w_t> dis(N+1, initDis);
    vector<int> inq(N+1, false);
    queue<int> q;
    for (auto s : start) {
        q.push(s);
        dis[s] = 0;
        inq[s] = false;
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        inq[c] = false;
        for (auto _to : g[c]) {
            int to = E.v(_to); w_t alt = dis[c] + E.w(_to);
            if (alt < dis[to]) {
                dis[to] = alt;
                if (!inq[to]) {
                    inq[to] = true;
                    q.push(to);
                }
            }
        }
    }
    return dis;
}
