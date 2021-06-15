#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/tarjan_undirected.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 1e5 + 1;
int N, M;
vector<pii> g[MN];

int main() {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a++; b++;
        g[a].eb(b, i);
        g[b].eb(a, i);
    }

    Tarjan<vector<pii>[MN], IndexedEdge, ARTICULATION_POINTS> art; art.solve(N, g);
    sort(all(art.articulation_points));
    for (auto x : art.articulation_points)
        print(x-1);
}
