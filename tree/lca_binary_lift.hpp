#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> struct LCABinaryLift {
    EdgeType E;
    int lg;
    vector<int> dep;
    vector<vector<int>> tb;
    void init(int N, GraphType &g, int rt) {
        lg = 31 - __builtin_clz(N) + 1;
        tb.assign(lg, vector<int>(N + 1, -1)); dep.assign(N + 1, 0);
        function<void(int, int)> dfs = [&] (int c, int p) {
            tb[0][c] = p;
            for (auto to : g[c]) {
                int v = E.v(to);
                if (v != p) {
                    dep[v] = dep[c] + 1;
                    dfs(v, c);
                }
            }
        };
        dfs(rt, -1);
        for (auto i = 1; i < lg; i++) {
            for (auto j = 1; j <= N; j++) {
                int pp = tb[i - 1][j];
                tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
            }
        }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        if (dep[a] > dep[b]) swap(a, b);
        int delta = dep[b] - dep[a];
        for (auto i = 0; i < lg; i++)
            if ((delta >> i) & 1)
                b = tb[i][b];
        if (a == b) return a;
        for (auto i = lg-1; i >= 0; i--) {
            if (tb[i][a] != tb[i][b]) {
                a = tb[i][a];
                b = tb[i][b];
            }
        }
        return tb[0][a];
    }

#if __cplusplus == 201703L // CPP17 only things
    void bind(opt_ref<vector<int>> dep0, opt_ref<vector<vector<int>>> tb0) {
        if (dep0) dep.swap(*dep0);
        if (tb0) tb.swap(*tb0);
    }
#endif
};
