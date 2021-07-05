
#include "math/matrix.hpp"
#include "math/mod.hpp"
#include "tests/test_utils.hpp"

using MI = ModInt<int, 998244353>;
//using MI = double;

void pr(Matrix<MI> &m) {
    cout << "[";
    for (int i = 0; i < m.N(); i++) {
        cout << "[";
        for (int j = 0; j < m.M(); j++)
            cout << m[i][j] << ", ";
        cout << "]\n";
    }
}

int main() {
    int N = readi(), M = readi();
    Matrix<MI> m(N, M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m[i][j];

    print("Initial : ");
    pr(m);

    m.rref();
    print("\nReduced Row-Echelon Form : ");
    pr(m);

    return 0;
}