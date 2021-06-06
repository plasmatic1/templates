struct Graph {
    using Edge = int; // Edge object in adjacency list (i.e. vector<int> g[MN], Edge type would be int)
    int v(Edge &e) { return e; } // Returns the adjacent node in an edge object
};
template <class Graph> struct LCA {
    using Edge = typename Graph::Edge; Graph G;
    vector<int> dep;
    vector<Edge> *g;
    vector<vector<int>> tb;
    int N, lg;
    void dfs(int c, int p) {
        tb[0][c] = p;
        for (auto to : g[c]) {
            int v = G.v(to);
            if (v != p) {
                dep[v] = dep[c] + 1;
                dfs(v, c);
            }
        }
    }
    void init(int N0, vector<Edge> *g0) {
        N = N0; g = g0;
        lg = 31 - __builtin_clz(N) + 1;
        tb.assign(lg, vector<int>(N + 1, -1)); dep.assign(N + 1, 0);
        dfs(1, -1);
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
};
