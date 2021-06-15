#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3022"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/tarjan_undirected.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 1e5 + 1;
int N, M;
ll A[MN];
vector<pii> g[MN];

vector<int> g2[MN*2];
int par[MN*2];
ll sz[MN*2];
bool artic[MN];

void dfs(int c, int p) {
    par[c] = p;
    if (c <= N) sz[c] += A[c];
    for (auto to : g2[c]) {
        if (to != p) {
            dfs(to, c);
            sz[c] += sz[to];
        }
    }
}

int main() {
    fast_io();
    cin >> N >> M;
    ll tsum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        tsum += A[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].eb(b, i);
        g[b].eb(a, i);
    }

    // run tarjan and build biconnected component tree
    Tarjan<vector<pii>[MN], IndexedEdge, BICONNECTED_COMPONENTS | ARTICULATION_POINTS> tarj; tarj.solve(N, g);
    for (auto x : tarj.articulation_points)
        artic[x] = true;
    int ctr = N;
    for (auto es : tarj.components) {
        set<int> ns;
        for (auto [a, b] : es) {
            ns.insert(a);
            ns.insert(b);
        }
        ctr++;
        for (auto x : ns) {
            g2[ctr].pb(x);
            g2[x].pb(ctr);
        }
    }

    // DFS and get ans
    dfs(1, -1);
    for (int i = 1; i <= N; i++) {
        if (!artic[i])
            print(tsum - A[i]);
        else {
            ll mx = 0;
            for (auto to : g2[i])
                if (to != par[i])
                    maxa(mx, sz[to]);
            if (par[i] != -1)
                maxa(mx, tsum-sz[i]);
            print(mx);
        }
    }
}
