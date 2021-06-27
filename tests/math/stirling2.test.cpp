#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"
#include "../../math/choose.hpp"
#include "../../math/stirling2.hpp"

using MI = ModInt<int, 1000000007>;

Choose<MI> c;

// Stirling numbers of the second kind
int main() {
    fast_io();
    int N = readi(), K = readi();
    c.init(N);
    MI ans = 0;
    for (int i = 1; i <= min(N, K); i++)
        ans += stir2(N, i, c);
    print(ans);
}
