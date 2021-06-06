struct TwoSat {
    int N, cord, ccomp;
    vector<int> ord, low, instk, res, stk, comp;
    vector<vector<int>> g;
    void init(int N0) {
        N = N0; cord = ccomp = 0;
        g.assign(N*2+1, vector<int>());
        ord.assign(N*2+1, 0);
        low.assign(N*2+1, 0);
        instk.assign(N*2+1, 0);
        comp.assign(N*2+1, 0);
        res.assign(N+1, 0);
        stk.clear();
    }
    void addEdge(int a, int b) {
        if (a < 0) a = N-a;
        if (b < 0) b = N-b;
        g[a].push_back(b);
    }
    void addOr(int a, int b) {
        addEdge(-a, b);
        addEdge(-b, a);
    }
    void tarjan(int c) {
        ord[c] = low[c] = ++cord;
        instk[c] = true; stk.push_back(c);
        for (auto to : g[c]) {
            if (!ord[to]) {
                tarjan(to);
                low[c] = min(low[c], low[to]);
            }
            else if (instk[to])
                low[c] = min(low[c], ord[to]);
        }

        if (low[c] == ord[c]) {
            int u, cc = ++ccomp;
            do {
                u = stk.back(); stk.pop_back(); instk[u] = false;
                comp[u] = cc;
            } while (u != c);
        }
    }
    void solve() {
        for (auto i = 1; i <= 2*N; i++)
            if (!ord[i])
                tarjan(i);
        for (auto i = 1; i <= N; i++) {
            if (comp[i] == comp[i+N]) {
                res.assign(N+1, -1);
                return;
            }
        }
        for (auto i = 1; i <= N; i++)
            res[i] = comp[i] < comp[i+N]; // 1 > 0
    }
};
