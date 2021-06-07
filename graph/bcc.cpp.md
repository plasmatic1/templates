---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "// ./summer-institute-17-contest-3-p4-customs.yml\n#include \"bits/stdc++.h\"\
    \nusing namespace std;\nusing ll = long long;\nconst ll INF = 0x3f3f3f3f, LLINF\
    \ = 0x3f3f3f3f3f3f3f3f;\nusing pii = pair<int, int>;\n\nconst ll MOD = 1e9 + 7;\n\
    const int MN = 2e4 + 1;\nint N, M;\nvector<int> g[MN];\n\nvector<vector<pii>>\
    \ cs;\n\nint cord = 0, ord[MN], low[MN];\nstack<pii> stk;\nvoid dfs(int c, int\
    \ p) {\n    ord[c] = low[c] = ++cord;\n    for (auto to : g[c]) {\n        if\
    \ (to != p) {\n            if (!ord[to]) {\n                stk.emplace(c, to);\n\
    \                dfs(to, c);\n                low[c] = min(low[c], low[to]);\n\
    \                \n                // we got an articulation point bois :sunglasses:\n\
    \                if (low[to] >= ord[c]) {\n                    cs.push_back(vector<pii>());\n\
    \                    int u, v;\n                    do {\n                   \
    \     auto _e = stk.top(); stk.pop();\n                        tie(u, v) = _e;\n\
    \                        cs.back().emplace_back(u, v);\n                    }\
    \ while (u != c || v != to);\n                }\n            }\n            else\
    \ if (ord[to] < ord[c]) {\n                stk.emplace(c, to);\n             \
    \   low[c] = min(low[c], ord[to]);\n            }\n        }\n    }\n}\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\n    cin\
    \ >> N >> M;\n    for (int i = 0; i < M; i++) {\n        int a, b; cin >> a >>\
    \ b;\n        a--; b--;\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \    }\n\n    dfs(0, -1);\n    for (int i = 0; i < N; i++) {\n        if (!ord[i])\
    \ {\n            cout << \"safe\\n\";\n            return 0;\n        }\n    }\n\
    \n    ll ans = 1;\n    for (auto c : cs) {\n        set<int> nodes;\n        for\
    \ (auto e : c) {\n            nodes.insert(e.first); nodes.insert(e.second);\n\
    \        }\n        if (c.size() > nodes.size()) { // complex(?) cycle\n     \
    \       cout << \"safe\\n\";\n            return 0;\n        }\n        else if\
    \ (c.size() == nodes.size()) // SIMPle cycle\n            ans = (ans * c.size())\
    \ % MOD;\n    }\n    cout << ans << '\\n';\n\n    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bcc.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bcc.cpp
layout: document
redirect_from:
- /library/graph/bcc.cpp
- /library/graph/bcc.cpp.html
title: graph/bcc.cpp
---
