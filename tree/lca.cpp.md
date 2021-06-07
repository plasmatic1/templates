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
  bundledCode: "#line 1 \"tree/lca.cpp\"\nstruct Graph {\n    using Edge = int; //\
    \ Edge object in adjacency list (i.e. vector<int> g[MN], Edge type would be int)\n\
    \    int v(Edge &e) { return e; } // Returns the adjacent node in an edge object\n\
    };\ntemplate <class Graph> struct LCA {\n    using Edge = typename Graph::Edge;\
    \ Graph G;\n    vector<int> dep;\n    vector<Edge> *g;\n    vector<vector<int>>\
    \ tb;\n    int N, lg;\n    void dfs(int c, int p) {\n        tb[0][c] = p;\n \
    \       for (auto to : g[c]) {\n            int v = G.v(to);\n            if (v\
    \ != p) {\n                dep[v] = dep[c] + 1;\n                dfs(v, c);\n\
    \            }\n        }\n    }\n    void init(int N0, vector<Edge> *g0) {\n\
    \        N = N0; g = g0;\n        lg = 31 - __builtin_clz(N) + 1;\n        tb.assign(lg,\
    \ vector<int>(N + 1, -1)); dep.assign(N + 1, 0);\n        dfs(1, -1);\n      \
    \  for (auto i = 1; i < lg; i++) {\n            for (auto j = 1; j <= N; j++)\
    \ {\n                int pp = tb[i - 1][j];\n                tb[i][j] = pp ==\
    \ -1 ? -1 : tb[i - 1][pp];\n            }\n        }\n    }\n    int lca(int a,\
    \ int b) {\n        if (a == b) return a;\n        if (dep[a] > dep[b]) swap(a,\
    \ b);\n        int delta = dep[b] - dep[a];\n        for (auto i = 0; i < lg;\
    \ i++)\n            if ((delta >> i) & 1)\n                b = tb[i][b];\n   \
    \     if (a == b) return a;\n        for (auto i = lg-1; i >= 0; i--) {\n    \
    \        if (tb[i][a] != tb[i][b]) {\n                a = tb[i][a];\n        \
    \        b = tb[i][b];\n            }\n        }\n        return tb[0][a];\n \
    \   }\n};\n"
  code: "struct Graph {\n    using Edge = int; // Edge object in adjacency list (i.e.\
    \ vector<int> g[MN], Edge type would be int)\n    int v(Edge &e) { return e; }\
    \ // Returns the adjacent node in an edge object\n};\ntemplate <class Graph> struct\
    \ LCA {\n    using Edge = typename Graph::Edge; Graph G;\n    vector<int> dep;\n\
    \    vector<Edge> *g;\n    vector<vector<int>> tb;\n    int N, lg;\n    void dfs(int\
    \ c, int p) {\n        tb[0][c] = p;\n        for (auto to : g[c]) {\n       \
    \     int v = G.v(to);\n            if (v != p) {\n                dep[v] = dep[c]\
    \ + 1;\n                dfs(v, c);\n            }\n        }\n    }\n    void\
    \ init(int N0, vector<Edge> *g0) {\n        N = N0; g = g0;\n        lg = 31 -\
    \ __builtin_clz(N) + 1;\n        tb.assign(lg, vector<int>(N + 1, -1)); dep.assign(N\
    \ + 1, 0);\n        dfs(1, -1);\n        for (auto i = 1; i < lg; i++) {\n   \
    \         for (auto j = 1; j <= N; j++) {\n                int pp = tb[i - 1][j];\n\
    \                tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];\n            }\n  \
    \      }\n    }\n    int lca(int a, int b) {\n        if (a == b) return a;\n\
    \        if (dep[a] > dep[b]) swap(a, b);\n        int delta = dep[b] - dep[a];\n\
    \        for (auto i = 0; i < lg; i++)\n            if ((delta >> i) & 1)\n  \
    \              b = tb[i][b];\n        if (a == b) return a;\n        for (auto\
    \ i = lg-1; i >= 0; i--) {\n            if (tb[i][a] != tb[i][b]) {\n        \
    \        a = tb[i][a];\n                b = tb[i][b];\n            }\n       \
    \ }\n        return tb[0][a];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/lca.cpp
layout: document
redirect_from:
- /library/tree/lca.cpp
- /library/tree/lca.cpp.html
title: tree/lca.cpp
---
