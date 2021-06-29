#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/edge_types.hpp"
#include "../../tree/lca_sparse_table.hpp"

const int MN = 5e5 + 1;
vector<int> g[MN];

int main() {
    fast_io();
    int N = readi(), Q = readi();

    // Randomizer to make sure code does not fail on trees where par_i < i does not always hold
    mt19937 mt(26022021);
    vector<int> P(N+1), iP(N+1); iota(P.begin()+1, P.end(), 1);
    shuffle(P.begin()+1, P.end(), mt);
    for (int i = 1; i <= N; i++)
        iP[P[i]] = i;

    for (int i = 2; i <= N; i++) {
        int p = readi()+1, a = P[i], b = P[p];
        g[a].push_back(b);
        g[b].push_back(a);
    }

    LCASparseTable<vector<int>[MN], Edge> lca; lca.init(N, g, P[1]);

    while (Q--) {
        int u = P[readi()+1];
        int v = P[readi()+1];
        print(iP[lca.lca(u, v)]-1);
    }
}
