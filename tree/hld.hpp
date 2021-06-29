template <typename GraphType, typename EdgeType> struct HLD {
    EdgeType E;
    int cpos;
    vector<int> par, dep, head, heavy, pos;
    void init(int N, GraphType &g, int rt) {
        cpos = 0;
        par.assign(N + 1, 0); dep.assign(N + 1, 0); head.assign(N + 1, 0); heavy.assign(N + 1, -1); pos.assign(N + 1, 0);
        function<int(int, int)> dfs = [&] (int c, int p) {
            par[c] = p;
            int sz = 1, mxsz = 0;
            for (auto to : g[c]) {
                int v = E.v(to);
                if (v != p) {
                    dep[v] = dep[c] + 1;
                    int csz = dfs(v, c); sz += csz;
                    if (csz > mxsz) heavy[c] = v, mxsz = csz;
                }
            }
            return sz;
        };
        function<void(int, int)> build = [&] (int c, int chead) {
            pos[c] = ++cpos; head[c] = chead;
            if (heavy[c] != -1) build(heavy[c], chead);
            for (auto to : g[c]) {
                int v = E.v(to);
                if (v != par[c] && v != heavy[c])
                    build(v, v);
            }
        };
        dfs(rt, -1);
        build(rt, rt);
    }
    int lca(int a, int b) {
        while (head[a] != head[b]) {
            if (dep[head[a]] > dep[head[b]]) swap(a, b);
            b = par[head[b]];
        }
        return dep[a] < dep[b] ? a : b;
    }

#if __cplusplus == 201703L // CPP17 only things
    void bind(opt_ref<vector<int>> par0, opt_ref<vector<int>> dep0, opt_ref<vector<int>> head0, opt_ref<vector<int>> heavy0, opt_ref<vector<int>> pos0) {
        if (par0) par.swap(*par0);
        if (dep0) dep.swap(*dep0);
        if (head0) head.swap(*head0);
        if (heavy0) heavy.swap(*heavy0);
        if (pos0) pos.swap(*pos0);
    }
#endif
};
