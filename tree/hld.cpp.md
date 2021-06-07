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
  bundledCode: "#line 1 \"tree/hld.cpp\"\nstruct Graph {\n    using Edge = int; //\
    \ Edge type\n    int v(Edge &e) { return e; } // Get vertex of edge\n};\ntemplate\
    \ <class Graph> struct HLD {\n    using Edge = typename Graph::Edge; Graph G;\n\
    \    int N, cpos;\n    vector<Edge> *g;\n    vector<int> par, dep, head, heavy,\
    \ pos;\n    int dfs(int c, int p) {\n        par[c] = p;\n        int sz = 1,\
    \ mxsz = 0;\n        for (auto to : g[c]) {\n            int v = G.v(to);\n  \
    \          if (v != p) {\n                dep[v] = dep[c] + 1;\n             \
    \   int csz = dfs(v, c); sz += csz;\n                if (csz > mxsz) heavy[c]\
    \ = v, mxsz = csz;\n            }\n        }\n        return sz;\n    }\n    void\
    \ build(int c, int chead) {\n        pos[c] = ++cpos; head[c] = chead;\n     \
    \   if (heavy[c] != -1) build(heavy[c], chead);\n        for (auto to : g[c])\
    \ {\n            int v = G.v(to);\n            if (v != par[c] && v != heavy[c])\n\
    \                build(v, v);\n        }\n    }\n    void init(int n0, vector<Edge>\
    \ *g0) {\n        N = n0; g = g0; cpos = 0;\n        par.assign(N + 1, 0); dep.assign(N\
    \ + 1, 0); head.assign(N + 1, 0); heavy.assign(N + 1, -1); pos.assign(N + 1, 0);\n\
    \        dfs(1, -1); build(1, 1);\n    }\n    int lca(int a, int b) {\n      \
    \  while (head[a] != head[b]) {\n            if (dep[head[a]] > dep[head[b]])\
    \ swap(a, b);\n            b = par[head[b]];\n        }\n        return dep[a]\
    \ < dep[b] ? a : b;\n    }\n};\n"
  code: "struct Graph {\n    using Edge = int; // Edge type\n    int v(Edge &e) {\
    \ return e; } // Get vertex of edge\n};\ntemplate <class Graph> struct HLD {\n\
    \    using Edge = typename Graph::Edge; Graph G;\n    int N, cpos;\n    vector<Edge>\
    \ *g;\n    vector<int> par, dep, head, heavy, pos;\n    int dfs(int c, int p)\
    \ {\n        par[c] = p;\n        int sz = 1, mxsz = 0;\n        for (auto to\
    \ : g[c]) {\n            int v = G.v(to);\n            if (v != p) {\n       \
    \         dep[v] = dep[c] + 1;\n                int csz = dfs(v, c); sz += csz;\n\
    \                if (csz > mxsz) heavy[c] = v, mxsz = csz;\n            }\n  \
    \      }\n        return sz;\n    }\n    void build(int c, int chead) {\n    \
    \    pos[c] = ++cpos; head[c] = chead;\n        if (heavy[c] != -1) build(heavy[c],\
    \ chead);\n        for (auto to : g[c]) {\n            int v = G.v(to);\n    \
    \        if (v != par[c] && v != heavy[c])\n                build(v, v);\n   \
    \     }\n    }\n    void init(int n0, vector<Edge> *g0) {\n        N = n0; g =\
    \ g0; cpos = 0;\n        par.assign(N + 1, 0); dep.assign(N + 1, 0); head.assign(N\
    \ + 1, 0); heavy.assign(N + 1, -1); pos.assign(N + 1, 0);\n        dfs(1, -1);\
    \ build(1, 1);\n    }\n    int lca(int a, int b) {\n        while (head[a] !=\
    \ head[b]) {\n            if (dep[head[a]] > dep[head[b]]) swap(a, b);\n     \
    \       b = par[head[b]];\n        }\n        return dep[a] < dep[b] ? a : b;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/hld.cpp
layout: document
redirect_from:
- /library/tree/hld.cpp
- /library/tree/hld.cpp.html
title: tree/hld.cpp
---
