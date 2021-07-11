#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/suffix_array.hpp"

const int MN = 5e5 + 1;
SuffixArray<MN, 'a', 'z', LCP> sa;
int N;
string s;
vector<int> suf, lcp;

int main() {
    fast_io();
    cin >> s; N = s.length();

    suf = sa.solve(N, s);
    sa.bind(lcp);

    vector<int> ans(N);
    int idxFull = -1;
    for (int i = 0; i < N; i++)
        if (!suf[i])
            idxFull = i;

    ans[0] = N;
    int cur = INF;
    for (int i = idxFull; i < N-1; i++) {
        mina(cur, lcp[i]);
        ans[suf[i+1]] = cur;
    }
    cur = INF;
    for (int i = idxFull; i > 0; i--) {
        mina(cur, lcp[i-1]);
        ans[suf[i-1]] = cur;
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}