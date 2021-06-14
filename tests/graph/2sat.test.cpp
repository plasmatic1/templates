#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../graph/2sat.hpp"

int main() {
    fast_io();
    string _, __; int N, M; cin >> _ >> __ >> N >> M;
    TwoSat solver; solver.init(N);
    for (int i = 0; i < M; i++) {
        int a, b, ___; cin >> a >> b >> ___;
        solver.addOr(a, b);
    }
    auto res = solver.solve();
    if (res[0] == -1) print("s UNSATISFIABLE");
    else {
        print("s SATISFIABLE");
        cout << "v ";
        for (int i = 1; i <= N; i++)
            cout << i*(-1 + 2*res[i]) << ' ';
        cout << "0\n";
    }
}
