#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "template.hpp"
#include "test_utils.hpp"
#include "rank_compression.hpp"

Ranks<ll> r;
using T = tuple<int, ll, ll>;
vector<T> qs;

int main() {
    fast_io();
    int Q = readi();
    for (int i = 0; i < Q; i++) {
        if (readi() == 0) {
            ll k = readl(); ll v = readl();
            r.add(k);
            qs.eb(0, k, v);
        }
        else {
            ll k = readl();
            r.add(k);
            qs.eb(1, k, -1);
        }
    }
    r.init();

    vector<ll> A(SZ(r)+1);
    for (auto [t, a, b] : qs) {
        a = r.get(a);
        if (t == 0) A[a] = b;
        else print(A[a]);
    }
}