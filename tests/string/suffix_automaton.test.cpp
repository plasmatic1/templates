#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/suffix_automaton.hpp"

const int MN = 5e5 + 1;
int N;
string s;
SAM<MN> sam;

int main() {
    fast_io();
    cin >> s; N = s.length();
    sam.init();
    for (auto x : s) sam.extend(x);
    ll ans = 0;
    for (int i = 1; i < sam.sz; i++)
        ans += sam.st[i].len - sam.st[sam.st[i].link].len;
    print(ans);

    return 0;
}