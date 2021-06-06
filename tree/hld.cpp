struct Graph {
    using Edge = int; // Edge type
    int v(Edge &e) { return e; } // Get vertex of edge
};
template <class Graph> struct HLD {
    using Edge = typename Graph::Edge; Graph G;
    int N, cpos;
    vector<Edge> *g;
    vector<int> par, dep, head, heavy, pos;
    int dfs(int c, int p) {
        par[c] = p;
        int sz = 1, mxsz = 0;
        for (auto to : g[c]) {
            int v = G.v(to);
            if (v != p) {
                dep[v] = dep[c] + 1;
                int csz = dfs(v, c); sz += csz;
                if (csz > mxsz) heavy[c] = v, mxsz = csz;
            }
        }
        return sz;
    }
    void build(int c, int chead) {
        pos[c] = ++cpos; head[c] = chead;
        if (heavy[c] != -1) build(heavy[c], chead);
        for (auto to : g[c]) {
            int v = G.v(to);
            if (v != par[c] && v != heavy[c])
                build(v, v);
        }
    }
    void init(int n0, vector<Edge> *g0) {
        N = n0; g = g0; cpos = 0;
        par.assign(N + 1, 0); dep.assign(N + 1, 0); head.assign(N + 1, 0); heavy.assign(N + 1, -1); pos.assign(N + 1, 0);
        dfs(1, -1); build(1, 1);
    }
    int lca(int a, int b) {
        while (head[a] != head[b]) {
            if (dep[head[a]] > dep[head[b]]) swap(a, b);
            b = par[head[b]];
        }
        return dep[a] < dep[b] ? a : b;
    }
};
