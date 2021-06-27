#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/eea.hpp"

int main() {
    fast_io();
    int a, b, x, y; cin >> a >> b;
    extgcd(a, b, x, y);
    print(x, y);
}
