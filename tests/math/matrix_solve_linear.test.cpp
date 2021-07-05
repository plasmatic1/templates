#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"
#include "../../math/matrix.hpp"

using MI = ModInt<int, 998244353>;

int main() {
    fast_io();
    assert(0); // I'm just going to make this completely explode so people knows this code doesn't work
    // This problem confuses me because I'm very bad at linear algebra :(

    int N = readi();
    Matrix<MI> m(N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m[i][j];

    auto res = Matrix<MI>::inv(m);
    if (res.invalid()) print(-1);
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << res[i][j] << ' ';
            cout << '\n';
        }
    }
}
