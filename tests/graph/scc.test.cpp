#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/scc.hpp"
#include "../../graph/edge_types.hpp"

const int MN = 5e5 + 1;
int N, M;
vector<int> g[MN];

int main() {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a++; b++;
        g[a].pb(b);
    }

    SCC<vector<int>[MN], Edge> scc;
    auto ans = scc.solve(N, g); reverse(all(ans));
    print(ans.size());
    for (auto c : ans) {
        cout << c.size();
        for (auto x : c) cout << ' ' << x-1;
        cout << '\n';
    }
}
