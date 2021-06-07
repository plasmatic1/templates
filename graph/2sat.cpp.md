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
  bundledCode: "#line 1 \"graph/2sat.cpp\"\nstruct TwoSat {\n    int N, cord, ccomp;\n\
    \    vector<int> ord, low, instk, res, stk, comp;\n    vector<vector<int>> g;\n\
    \    void init(int N0) {\n        N = N0; cord = ccomp = 0;\n        g.assign(N*2+1,\
    \ vector<int>());\n        ord.assign(N*2+1, 0);\n        low.assign(N*2+1, 0);\n\
    \        instk.assign(N*2+1, 0);\n        comp.assign(N*2+1, 0);\n        res.assign(N+1,\
    \ 0);\n        stk.clear();\n    }\n    void addEdge(int a, int b) {\n       \
    \ if (a < 0) a = N-a;\n        if (b < 0) b = N-b;\n        g[a].push_back(b);\n\
    \    }\n    void addOr(int a, int b) {\n        addEdge(-a, b);\n        addEdge(-b,\
    \ a);\n    }\n    void tarjan(int c) {\n        ord[c] = low[c] = ++cord;\n  \
    \      instk[c] = true; stk.push_back(c);\n        for (auto to : g[c]) {\n  \
    \          if (!ord[to]) {\n                tarjan(to);\n                low[c]\
    \ = min(low[c], low[to]);\n            }\n            else if (instk[to])\n  \
    \              low[c] = min(low[c], ord[to]);\n        }\n\n        if (low[c]\
    \ == ord[c]) {\n            int u, cc = ++ccomp;\n            do {\n         \
    \       u = stk.back(); stk.pop_back(); instk[u] = false;\n                comp[u]\
    \ = cc;\n            } while (u != c);\n        }\n    }\n    void solve() {\n\
    \        for (auto i = 1; i <= 2*N; i++)\n            if (!ord[i])\n         \
    \       tarjan(i);\n        for (auto i = 1; i <= N; i++) {\n            if (comp[i]\
    \ == comp[i+N]) {\n                res.assign(N+1, -1);\n                return;\n\
    \            }\n        }\n        for (auto i = 1; i <= N; i++)\n           \
    \ res[i] = comp[i] < comp[i+N]; // 1 > 0\n    }\n};\n"
  code: "struct TwoSat {\n    int N, cord, ccomp;\n    vector<int> ord, low, instk,\
    \ res, stk, comp;\n    vector<vector<int>> g;\n    void init(int N0) {\n     \
    \   N = N0; cord = ccomp = 0;\n        g.assign(N*2+1, vector<int>());\n     \
    \   ord.assign(N*2+1, 0);\n        low.assign(N*2+1, 0);\n        instk.assign(N*2+1,\
    \ 0);\n        comp.assign(N*2+1, 0);\n        res.assign(N+1, 0);\n        stk.clear();\n\
    \    }\n    void addEdge(int a, int b) {\n        if (a < 0) a = N-a;\n      \
    \  if (b < 0) b = N-b;\n        g[a].push_back(b);\n    }\n    void addOr(int\
    \ a, int b) {\n        addEdge(-a, b);\n        addEdge(-b, a);\n    }\n    void\
    \ tarjan(int c) {\n        ord[c] = low[c] = ++cord;\n        instk[c] = true;\
    \ stk.push_back(c);\n        for (auto to : g[c]) {\n            if (!ord[to])\
    \ {\n                tarjan(to);\n                low[c] = min(low[c], low[to]);\n\
    \            }\n            else if (instk[to])\n                low[c] = min(low[c],\
    \ ord[to]);\n        }\n\n        if (low[c] == ord[c]) {\n            int u,\
    \ cc = ++ccomp;\n            do {\n                u = stk.back(); stk.pop_back();\
    \ instk[u] = false;\n                comp[u] = cc;\n            } while (u !=\
    \ c);\n        }\n    }\n    void solve() {\n        for (auto i = 1; i <= 2*N;\
    \ i++)\n            if (!ord[i])\n                tarjan(i);\n        for (auto\
    \ i = 1; i <= N; i++) {\n            if (comp[i] == comp[i+N]) {\n           \
    \     res.assign(N+1, -1);\n                return;\n            }\n        }\n\
    \        for (auto i = 1; i <= N; i++)\n            res[i] = comp[i] < comp[i+N];\
    \ // 1 > 0\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/2sat.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/2sat.cpp
layout: document
redirect_from:
- /library/graph/2sat.cpp
- /library/graph/2sat.cpp.html
title: graph/2sat.cpp
---
