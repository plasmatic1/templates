#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../string/hash_utils.hpp"

const int MN = 5e5 + 1;
int N;
string s;
ll hs[MN];

int main() {
    fast_io();
    init_hash<RAND_BASE>(MN);

    cin >> s; N = s.length();

    for (int i = 1; i <= N; i++)
        hs[i] = happend(hs[i-1], s[i-1]);
    for (int i = 1; i <= N; i++) {
        int l = 0, r = N-i+1, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (hget(hs, i, i+mid-1) == hget(hs, 1, mid)) {
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }

        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}