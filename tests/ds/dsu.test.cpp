#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/dsu.hpp"

int main() {
    fast_io();
    int N = readi(), Q = readi();
    DSU d; d.init(N);
    while (Q--) {
        int t = readi(), a = readi(), b = readi();
        switch (t) {
            case 0:
                d.merge(a, b);
                break;
            case 1:
                print(d.con(a, b));
        }
    }
}
