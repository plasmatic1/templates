#pragma once
#include "../template.hpp"

template <typename GraphType, typename EdgeType> struct SCC {
    EdgeType E;
    int cord = 0;
    vector<int> ord, low, stk;
    vector<bool> instk;

    vector<vector<int>> solve(int N, GraphType &g) {
        ord.assign(N+1, 0);
        low.assign(N+1, 0);
        instk.assign(N+1, false);
        stk.clear();
        cord = 0;

        vector<vector<int>> cs;
        function<void(int)> tarjan = [&] (int c) {
            ord[c] = low[c] = ++cord;
            instk[c] = true;
            stk.push_back(c);

            for (auto _to : g[c]) {
                int to = E.v(_to);
                if (!ord[to]) {
                    tarjan(to);
                    low[c] = min(low[c], low[to]);
                } else if (instk[to])
                    low[c] = min(low[c], ord[to]);
            }

            if (low[c] == ord[c]) {
                int u;
                cs.push_back(vector<int>());
                do {
                    u = stk.back();
                    instk[u] = false;
                    stk.pop_back();
                    cs.back().push_back(u);
                } while (u != c);
            }
        };
        for (int i = 1; i <= N; i++)
            if (!ord[i])
                tarjan(i);

        return cs;
    }

#if __cplusplus == 201703L // CPP17 only things
    void bind(opt_ref<vector<int>> ord0, opt_ref<vector<int>> low0) {
        if (ord0) ord.swap(*ord0);
        if (low0) low.swap(*low0);
    }
#endif
};
