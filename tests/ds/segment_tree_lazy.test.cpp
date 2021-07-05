#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/segment_tree_lazy.hpp"
#include "../../math/mod.hpp"

// A = (ax+b), B = (cx+d)
// c(ax+b)+d = acx + bc + d
using MI = ModInt<int, 998244353>;
using pm = pair<MI, MI>;
struct AffineComp {
    using Data = MI;
    using Lazy = pm;
    const Data vdef = 0;
    const Lazy ldef = {1, 0};
    Data merge(Data l, Data r) const { return l + r; }
    Lazy mergeLazy(Lazy to, Lazy v) const {
        auto [a, b] = to;
        auto [c, d] = v;
        return {a * c, b * c + d};
    }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to = v.first * to + (r - l + 1) * v.second; }
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
