#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/segment_tree_lazy.hpp"

// A = (ax+b), B = (cx+d)
// c(ax+b)+d = acx + bc + d
const ll MOD = 998244353;
struct AffineComp {
    using Data = ll;
    using Lazy = pll;
    const Data vdef = 0;
    const Lazy ldef = {1, 0};
    Data merge(Data l, Data r) const { return (l + r) % MOD; }
    Lazy mergeLazy(Lazy to, Lazy v) const {
        auto [a, b] = to;
        auto [c, d] = v;
        return {a * c % MOD, (b * c + d) % MOD};
    }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to = (v.first * to + (r - l + 1) * v.second) % MOD; }
};

int main() {
    fast_io();
    int N = readi(), Q = readi();
    LazySegmentTree<AffineComp> seg; seg.init(N);
    for (auto [i, v] : enumerate(readv<int>(N), 1))
        seg.setPoint(i, v);
    while (Q--) {
        if (readi() == 0) {
            int l = readi() + 1, r = readi(), b = readi(), c = readi();
            seg.update(l, r, {b, c});
        }
        else {
            int l = readi()+1, r = readi();
            print(seg.query(l, r));
        }
    }
}
