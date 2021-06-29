#pragma once
#include "../template.hpp"

// Due to some limitations with the current format of the templates, I cannot use the sparse_table.hpp template here
template <typename GraphType, typename EdgeType> struct LCASparseTable {
    EdgeType E;
    vector<int> dep, tour, fst;
    vector<vector<int>> tb;
    int N, lg;
    int minByDep(int a, int b) { return dep[a] < dep[b] ? a : b; }
    void init(int N, GraphType &g, int rt) {
        dep.assign(N+1, 0); fst.assign(N+1, 0); tour.clear();
        function<void(int, int)> dfs = [&] (int c, int p) {
            tour.push_back(c);
            fst[c] = tour.size();
            for (auto to : g[c]) {
                int v = E.v(to);
                if (v != p) {
                    dep[v] = dep[c] + 1;
                    dfs(v, c);
                    tour.push_back(c);
                }
            }
        };
        dfs(rt, -1);

        N = tour.size(); lg = __lg(N);
        tb.assign(lg+1, vector<int>(N+1));
        copy(tour.begin(), tour.end(), tb[0].begin()+1);
        for (auto i = 1; i <= lg; i++) {
            int jmp = 1 << (i-1), end = N - (1<<i) + 1;
            for (auto j = 1; j <= end; j++)
                tb[i][j] = minByDep(tb[i-1][j], tb[i-1][j+jmp]);
        }
    }
    int lca(int a, int b) {
        a = fst[a]; b = fst[b];
        if (a > b) swap(a, b);
        int bit = __lg(b-a+1);
        return minByDep(tb[bit][a], tb[bit][b-(1<<bit)+1]);
    }
};
