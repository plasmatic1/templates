#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/bfs.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 101;
int N;
vector<int> g[MN];

int main() {
    fast_io();
    N = readi();
    for (int i = 1; i <= N; i++) {
        int v = readi(), n = readi();
        for (auto to : readv<int>(n))
            g[v].pb(to);
    }

    auto res = bfs<vector<int>[MN], Edge>(N, g, {1});
    for (int i = 1; i <= N; i++)
        print(i, res[i]);
}
