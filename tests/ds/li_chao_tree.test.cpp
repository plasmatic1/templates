#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/li_chao_tree.hpp"

int main() {
    fast_io();
    int N = readi(), Q = readi();
    LiChaoTree<ll, -ll(1e9), ll(1e9)> li;
    for (auto [m, b] : readv<pll>(N))
        li.insert({m, b});
    while (Q--) {
        if (readi() == 0) {
            ll a = readl(), b = readl();
            li.insert({a, b});
        }
        else {
            int p = readi();
            print(li.query(p));
        }
    }
}
