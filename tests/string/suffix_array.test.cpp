#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/suffix_array.hpp"

const int MN = 5e5 + 1;
SuffixArray<MN, 'a', 'z', SA_ONLY> sa;
int N;
string s;

int main() {
    fast_io();
    cin >> s; N = s.length();
    for (auto idx : sa.solve(N, s))
        cout << idx << ' ';
    cout << '\n';

    return 0;
}