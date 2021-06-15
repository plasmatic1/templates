#pragma once
#include "../template.hpp"

const int BICONNECTED_COMPONENTS = 1 << 0, ARTICULATION_POINTS = 1 << 1, BRIDGES = 1 << 2;
template <typename GraphType, typename EdgeType, int MODE> struct Tarjan {
    EdgeType E;
    int cord = 0;
    vector<int> ord, low;
    vector<pii> stk;

    vector<int> articulation_points;
    vector<int> bridges;
    vector<vector<pii>> components;

    void solve(int N, GraphType &g) {
        cord = 0;
        ord.assign(N+1, 0); low.assign(N+1, 0);
        stk.clear();
        if (MODE & BICONNECTED_COMPONENTS) components.clear();
        if (MODE & ARTICULATION_POINTS) articulation_points.clear();
        if (MODE & BRIDGES) bridges.clear();

        function<void(int, int)> tarjan = [&] (int c, int pi) {
            bool artic = false;
            int cc = 0;

            ord[c] = low[c] = ++cord;
            for (auto _to : g[c]) {
                int to = E.v(_to), toi = E.i(_to);
                if (toi != pi) {
                    if (!ord[to]) {
                        if (MODE & BICONNECTED_COMPONENTS) stk.emplace_back(c, to);
                        if (MODE & ARTICULATION_POINTS) cc++;
                        tarjan(to, toi);
                        low[c] = min(low[c], low[to]);

                        // we got an articulation point bois :sunglasses:
                        if (low[to] >= ord[c]) {
                            if (MODE & ARTICULATION_POINTS) artic = true;
                            if (MODE & BICONNECTED_COMPONENTS) {
                                components.push_back(vector<pii>());
                                int u, v;
                                do {
                                    auto _e = stk.back();
                                    stk.pop_back();
                                    tie(u, v) = _e;
                                    components.back().emplace_back(u, v);
                                } while (u != c || v != to);
                            }
                        }
                        if (MODE & BRIDGES) {
                            if (low[to] > ord[c])
                                bridges.push_back(toi);
                        }
                    } else if (ord[to] < ord[c]) {
                        if (MODE & BICONNECTED_COMPONENTS) stk.emplace_back(c, to);
                        low[c] = min(low[c], ord[to]);
                    }
                }
            }

            if (MODE & ARTICULATION_POINTS)
                if ((pi != -1 && artic) || (pi == -1 && cc > 1))
                    articulation_points.push_back(c);
        };
        for (int i = 1; i <= N; i++)
            if (!ord[i])
                tarjan(i, -1);
    }

    void bind(opt_ref<vector<int>> ord0, opt_ref<vector<int>> low0) {
        if (ord0) ord.swap(*ord0);
        if (low0) low.swap(*low0);
    }
};
