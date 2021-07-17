#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/z_algorithm.hpp"

const int MN = 5e5 + 1;
int N;
string s;

int main() {
    fast_io();

    cin >> s; N = s.length();
    for (auto x : z_algorithm(N, s))
        cout << x << ' ';
    cout << '\n';

    return 0;
}