#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/edge_types.hpp"
#include "../../tree/hld.hpp"
#include "../../ds/bit.hpp"

struct CompLL {
    using Data = ll;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};

const int MN = 5e5 + 1;
int N, Q;
ll A[MN];
vector<int> g[MN];
HLD<vector<int>[MN], Edge> hld;
BIT<CompLL> bit;
vector<int> &par = hld.par, &head = hld.head, &pos = hld.pos;

ll path(int u) {
    ll res = 0;
    while (u != -1) {
        res += bit.query(pos[u]) - bit.query(pos[head[u]]-1);
        u = par[head[u]];
    }
    return res;
}

int main() {
    fast_io();
    N = readi();
    Q = readi();
    for (int i = 1; i <= N; i++) A[i] = readi();
    for (int i = 1; i <= N-1; i++) {
        int a = readi()+1;
        int b = readi()+1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    hld.init(N, g, 1);
    bit.init(N);
    for (int i = 1; i <= N; i++)
        bit.update(pos[i], A[i]);

    while (Q--) {
        int t = readi();
        int a = readi()+1;
        int b = readi() + (t == 1);
        if (t == 0) {
            bit.update(pos[a], b);
            A[a] += b;
        }
        else {
            int l = hld.lca(a, b);
            ll res = path(a) + path(b) - 2*path(l) + A[l];
            print(res);
        }
    }
}
