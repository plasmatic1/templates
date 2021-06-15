#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/tarjan_undirected.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 1e5 + 1;
int N, M,
    A[MN], B[MN];
vector<pii> g[MN];

int main() {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a++; b++;
        g[a].eb(b, i);
        g[b].eb(a, i);
        A[i] = a; B[i] = b;
    }

    Tarjan<vector<pii>[MN], IndexedEdge, BRIDGES> brid; brid.solve(N, g);
    vector<pii> res;
    for (auto x : brid.bridges)
        res.eb(min(A[x], B[x])-1, max(A[x], B[x])-1);
    sort(all(res));
    for (auto [a, b] : res)
        print(a, b);
}
