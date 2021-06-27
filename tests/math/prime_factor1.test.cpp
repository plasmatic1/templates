#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/prime_factor.hpp"

int main() {
    fast_io();
    int N = readi();
    cout << N << ':';
    for (auto [v, c] : primeFactor1(N)) {
        while (c--)
            cout << ' ' << v;
    }
    cout << '\n';
}
