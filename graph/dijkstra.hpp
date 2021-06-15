#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> vector<typename EdgeType::WeightType> dijkstra(int N, GraphType &g, initializer_list<int> start, typename EdgeType::WeightType initDis) {
    static EdgeType E;
    using w_t = typename EdgeType::WeightType; using st = pair<w_t, int>;
    vector<w_t> dis(N+1, initDis);
    priority_queue<st, vector<st>, greater<st>> pq;
    for (auto s : start) {
        pq.emplace(0, s);
        dis[s] = 0;
    }
    while (!pq.empty()) {
        auto [w, c] = pq.top(); pq.pop();
        if (w > dis[c]) continue;
        for (auto _to : g[c]) {
            int to = E.v(_to); w_t alt = dis[c] + E.w(_to);
            if (alt < dis[to]) {
                dis[to] = alt;
                pq.emplace(alt, to);
            }
        }
    }
    return dis;
}
