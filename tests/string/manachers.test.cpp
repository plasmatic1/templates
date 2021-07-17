#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/manachers.hpp"

const int MN = 5e5 + 1;
int N;
string s;

int main() {
    fast_io();

    cin >> s; N = s.length();
    string t = "$";
    for (int i = 0; i < N; i++) {
        t += s[i];
        t += '$';
    }

    auto res = manachers(2*N+1, t);
    for (int i = 1; i < 2*N; i++)
        cout << res[i]-1 << ' ';
    cout << '\n';

    return 0;
}