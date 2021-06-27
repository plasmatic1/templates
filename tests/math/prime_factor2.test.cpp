#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/prime_factor.hpp"

int main() {
    fast_io();
    int N = readi();
    cout << N << ':';
    for (auto v : primeFactor2(N)) cout << ' ' << v;
    cout << '\n';
}
