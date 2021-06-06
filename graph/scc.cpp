// scc.yml
// tested on https://judge.yosupo.jp/problem/scc
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 5e5 + 1;
int N, M;

vector<int> g[MN];
int cord = 0, ord[MN], low[MN];
bool instk[MN];
stack<int> stk;

vector<vector<int>> cs;

void dfs(int c) {
    ord[c] = low[c] = ++cord;
    instk[c] = true;
    stk.push(c);

    for (auto to : g[c]) {
        if (!ord[to]) {
            dfs(to);
            low[c] = min(low[c], low[to]);
        }
        else if (instk[to])
            low[c] = min(low[c], ord[to]);
    }

    if (low[c] == ord[c]) {
        int u;
        cs.push_back(vector<int>());
        do {
            u = stk.top();
            instk[u] = false; stk.pop();
            cs.back().push_back(u);
        } while (u != c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 0; i < N; i++)
        if (!ord[i])
            dfs(i);

    // for (int i = 0; i < N; i++) {
    //     printf("i=%d ord=%d low=%d\n", i,ord[i],low[i]);
    // }

    reverse(cs.begin(), cs.end());
    cout << cs.size() << '\n';
    for (auto v : cs) {
        cout << v.size() << ' ';
        for (auto x : v) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}

