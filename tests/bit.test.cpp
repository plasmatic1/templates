#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../template.hpp"
#include "test_utils.hpp"
#include "../ds/bit.hpp"

struct CompLL {
    using Data = ll;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};

int main() {
    fast_io();
    int N = readi(), Q = readi();
    BIT<CompLL> bit; bit.init(N);
    for (auto [i, x] : enumerate(readv<int>(N), 1))
        bit.update(i, x);
    while (Q--) {
        int t = readi(), a = readi(), b = readi();
        switch (t) {
            case 0:
                bit.update(a+1, b);
                break;
            case 1:
                print(bit.query(b) - bit.query(a));
        }
    }
}
