#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"
#include "../../math/choose.hpp"

using MI = ModInt<int, 1000000007>;
Choose<MI> c;

int main() {
    fast_io();
    c.init(1000);
    int N = readi(), K = readi();
    if (K < N) print(0);
    else print(c.permute(K, N));
}
