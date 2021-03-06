#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/segment_tree.hpp"
#include "../../math/mod.hpp"

// A(x) = ax+b, B(x) = cx+d
// B(A(x)) = c(ax+b)+d = acx + bc + d
using MI = ModInt<int, 998244353>;
using pm = pair<MI, MI>;
struct CompComp {
    using Data = pm;
    using Update = pm;
    const Data vdef = {1, 0};
    Data merge(Data l, Data r) {
        auto [a, b] = l;
        auto [c, d] = r;
        return {a * c, b * c + d};
    }
    void applyUpdate(Data &l, Update &r) { l = r; }
};

int main() {
    fast_io();
    int N = readi(), Q = readi();
    SegmentTree<CompComp> seg; seg.init(N);
    for (auto [i, v] : enumerate(readv<pll>(N), 1))
        seg.update(i, v);
    while (Q--) {
        if (readi() == 0) {
            int p = readi()+1, b = readi(), c = readi();
            seg.update(p, {b, c});
        }
        else {
            int l = readi()+1, r = readi(); ll x = readl();
            auto [a, b] = seg.query(l, r);
            print(a * x + b);
        }
    }
}
