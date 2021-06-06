// ./summer-institute-17-contest-3-p4-customs.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const int MN = 2e4 + 1;
int N, M;
vector<int> g[MN];

vector<vector<pii>> cs;

int cord = 0, ord[MN], low[MN];
stack<pii> stk;
void dfs(int c, int p) {
    ord[c] = low[c] = ++cord;
    for (auto to : g[c]) {
        if (to != p) {
            if (!ord[to]) {
                stk.emplace(c, to);
                dfs(to, c);
                low[c] = min(low[c], low[to]);
                
                // we got an articulation point bois :sunglasses:
                if (low[to] >= ord[c]) {
                    cs.push_back(vector<pii>());
                    int u, v;
                    do {
                        auto _e = stk.top(); stk.pop();
                        tie(u, v) = _e;
                        cs.back().emplace_back(u, v);
                    } while (u != c || v != to);
                }
            }
            else if (ord[to] < ord[c]) {
                stk.emplace(c, to);
                low[c] = min(low[c], ord[to]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);
    for (int i = 0; i < N; i++) {
        if (!ord[i]) {
            cout << "safe\n";
            return 0;
        }
    }

    ll ans = 1;
    for (auto c : cs) {
        set<int> nodes;
        for (auto e : c) {
            nodes.insert(e.first); nodes.insert(e.second);
        }
        if (c.size() > nodes.size()) { // complex(?) cycle
            cout << "safe\n";
            return 0;
        }
        else if (c.size() == nodes.size()) // SIMPle cycle
            ans = (ans * c.size()) % MOD;
    }
    cout << ans << '\n';

    return 0;
}

