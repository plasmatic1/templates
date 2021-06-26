#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"

using MI = ModInt<int, 1000000007>;

int main() {
    fast_io();
    int N = readi(), K = readi();
    print(MI::pow(K, N));
}
