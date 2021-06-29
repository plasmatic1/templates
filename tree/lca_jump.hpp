#pragma once
#include "../template.hpp"

// Source: https://codeforces.com/blog/entry/74847
template <typename GraphType, typename EdgeType> struct LCAJump {
    EdgeType E;
    vector<int> dep, par, jmp;
    void init(int N, GraphType &g, int rt) {
        dep.assign(N+1, 0); par.assign(N+1, -1); jmp.assign(N+1, -1);
        function<void(int, int)> dfs = [&] (int c, int p) {
            par[c] = p;
            if (c != rt) {
                if (dep[p] - dep[jmp[p]] == dep[jmp[p]] - dep[jmp[jmp[p]]])
                    jmp[c] = jmp[jmp[p]];
                else
                    jmp[c] = p;
            }
            for (auto to : g[c]) {
                int v = E.v(to);
                if (v != p) {
                    dep[v] = dep[c] + 1;
                    dfs(v, c);
                }
            }
        };
        jmp[rt] = rt;
        dfs(rt, -1);
    }
    int findFirst(int u, function<bool(int)> check) {
        while (!check(u)) {
            if (!check(jmp[u])) u = jmp[u];
            else u = par[u];
        }
        return u;
    }
    int up(int u, int want) {
        while (dep[u] > want) {
            if (dep[jmp[u]] >= want) u = jmp[u];
            else u = par[u];
        }
        return u;
    }
    int lca(int a, int b) {
        if (dep[a] > dep[b]) swap(a, b);
        b = up(b, dep[a]);
        while (a != b) {
            if (jmp[a] != jmp[b]) {
                a = jmp[a];
                b = jmp[b];
            }
            else {
                a = par[a];
                b = par[b];
            }
        }
        return a;
    }
};
