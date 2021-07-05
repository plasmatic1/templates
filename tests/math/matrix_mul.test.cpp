#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/mod.hpp"
#include "../../math/matrix.hpp"

using MI = ModInt<int, 998244353>;

int main() {
    fast_io();
    int N = readi(), M = readi(), K = readi();
    Matrix<MI> a(N, M), b(M, K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> b[i][j];
    a *= b;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
