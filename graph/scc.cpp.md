---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "// scc.yml\n// tested on https://judge.yosupo.jp/problem/scc\n#include \"\
    bits/stdc++.h\"\nusing namespace std;\nusing ll = long long;\nconst ll INF = 0x3f3f3f3f,\
    \ LLINF = 0x3f3f3f3f3f3f3f3f;\n\nconst int MN = 5e5 + 1;\nint N, M;\n\nvector<int>\
    \ g[MN];\nint cord = 0, ord[MN], low[MN];\nbool instk[MN];\nstack<int> stk;\n\n\
    vector<vector<int>> cs;\n\nvoid dfs(int c) {\n    ord[c] = low[c] = ++cord;\n\
    \    instk[c] = true;\n    stk.push(c);\n\n    for (auto to : g[c]) {\n      \
    \  if (!ord[to]) {\n            dfs(to);\n            low[c] = min(low[c], low[to]);\n\
    \        }\n        else if (instk[to])\n            low[c] = min(low[c], ord[to]);\n\
    \    }\n\n    if (low[c] == ord[c]) {\n        int u;\n        cs.push_back(vector<int>());\n\
    \        do {\n            u = stk.top();\n            instk[u] = false; stk.pop();\n\
    \            cs.back().push_back(u);\n        } while (u != c);\n    }\n}\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\n  \
    \  cin >> N >> M;\n    for (int i = 0; i < M; i++) {\n        int a, b; cin >>\
    \ a >> b;\n        g[a].push_back(b);\n    }\n\n    for (int i = 0; i < N; i++)\n\
    \        if (!ord[i])\n            dfs(i);\n\n    // for (int i = 0; i < N; i++)\
    \ {\n    //     printf(\"i=%d ord=%d low=%d\\n\", i,ord[i],low[i]);\n    // }\n\
    \n    reverse(cs.begin(), cs.end());\n    cout << cs.size() << '\\n';\n    for\
    \ (auto v : cs) {\n        cout << v.size() << ' ';\n        for (auto x : v)\
    \ cout << x << ' ';\n        cout << '\\n';\n    }\n\n    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: graph/scc.cpp
---
