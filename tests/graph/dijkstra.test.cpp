#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/dijkstra.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 1e5 + 1;
int N, M, s;
vector<pair<int, ll>> g[MN];

int main() {
    fast_io();
    N = readi(); M = readi(); s = readi()+1;
    for (int i = 0; i < M; i++) {
        int a = readi()+1, b = readi()+1, w = readi();
        g[a].eb(b, w);
    }

    auto res = dijkstra<vector<pair<int, ll>>[MN], WeightedEdge<ll>>(N, g, {s}, LLINF);
    for (int i = 1; i <= N; i++) {
        if (res[i] == LLINF) print("INF");
        else print(res[i]);
    }
}
