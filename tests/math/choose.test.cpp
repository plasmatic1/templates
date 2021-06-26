#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"
#include "../../math/choose.hpp"

using MI = ModInt<int, 1000000007>;
Choose<MI> c;

int main() {
    fast_io();
    c.init(2000);
    int N = readi(), K = readi();
    print(c.choose(N+K-1, K-1));
}
