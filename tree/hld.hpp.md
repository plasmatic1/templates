---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tree/hld_lca.test.cpp
    title: tests/tree/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree/hld_path_query.test.cpp
    title: tests/tree/hld_path_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/hld.hpp\"\ntemplate <typename GraphType, typename EdgeType>\
    \ struct HLD {\n    EdgeType E;\n    int cpos;\n    vector<int> par, dep, head,\
    \ heavy, pos;\n    void init(int N, GraphType &g, int rt) {\n        cpos = 0;\n\
    \        par.assign(N + 1, 0); dep.assign(N + 1, 0); head.assign(N + 1, 0); heavy.assign(N\
    \ + 1, -1); pos.assign(N + 1, 0);\n        function<int(int, int)> dfs = [&] (int\
    \ c, int p) {\n            par[c] = p;\n            int sz = 1, mxsz = 0;\n  \
    \          for (auto to : g[c]) {\n                int v = E.v(to);\n        \
    \        if (v != p) {\n                    dep[v] = dep[c] + 1;\n           \
    \         int csz = dfs(v, c); sz += csz;\n                    if (csz > mxsz)\
    \ heavy[c] = v, mxsz = csz;\n                }\n            }\n            return\
    \ sz;\n        };\n        function<void(int, int)> build = [&] (int c, int chead)\
    \ {\n            pos[c] = ++cpos; head[c] = chead;\n            if (heavy[c] !=\
    \ -1) build(heavy[c], chead);\n            for (auto to : g[c]) {\n          \
    \      int v = E.v(to);\n                if (v != par[c] && v != heavy[c])\n \
    \                   build(v, v);\n            }\n        };\n        dfs(rt, -1);\n\
    \        build(rt, rt);\n    }\n    int lca(int a, int b) {\n        while (head[a]\
    \ != head[b]) {\n            if (dep[head[a]] > dep[head[b]]) swap(a, b);\n  \
    \          b = par[head[b]];\n        }\n        return dep[a] < dep[b] ? a :\
    \ b;\n    }\n\n#if __cplusplus == 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>>\
    \ par0, opt_ref<vector<int>> dep0, opt_ref<vector<int>> head0, opt_ref<vector<int>>\
    \ heavy0, opt_ref<vector<int>> pos0) {\n        if (par0) par.swap(*par0);\n \
    \       if (dep0) dep.swap(*dep0);\n        if (head0) head.swap(*head0);\n  \
    \      if (heavy0) heavy.swap(*heavy0);\n        if (pos0) pos.swap(*pos0);\n\
    \    }\n#endif\n};\n"
  code: "template <typename GraphType, typename EdgeType> struct HLD {\n    EdgeType\
    \ E;\n    int cpos;\n    vector<int> par, dep, head, heavy, pos;\n    void init(int\
    \ N, GraphType &g, int rt) {\n        cpos = 0;\n        par.assign(N + 1, 0);\
    \ dep.assign(N + 1, 0); head.assign(N + 1, 0); heavy.assign(N + 1, -1); pos.assign(N\
    \ + 1, 0);\n        function<int(int, int)> dfs = [&] (int c, int p) {\n     \
    \       par[c] = p;\n            int sz = 1, mxsz = 0;\n            for (auto\
    \ to : g[c]) {\n                int v = E.v(to);\n                if (v != p)\
    \ {\n                    dep[v] = dep[c] + 1;\n                    int csz = dfs(v,\
    \ c); sz += csz;\n                    if (csz > mxsz) heavy[c] = v, mxsz = csz;\n\
    \                }\n            }\n            return sz;\n        };\n      \
    \  function<void(int, int)> build = [&] (int c, int chead) {\n            pos[c]\
    \ = ++cpos; head[c] = chead;\n            if (heavy[c] != -1) build(heavy[c],\
    \ chead);\n            for (auto to : g[c]) {\n                int v = E.v(to);\n\
    \                if (v != par[c] && v != heavy[c])\n                    build(v,\
    \ v);\n            }\n        };\n        dfs(rt, -1);\n        build(rt, rt);\n\
    \    }\n    int lca(int a, int b) {\n        while (head[a] != head[b]) {\n  \
    \          if (dep[head[a]] > dep[head[b]]) swap(a, b);\n            b = par[head[b]];\n\
    \        }\n        return dep[a] < dep[b] ? a : b;\n    }\n\n#if __cplusplus\
    \ == 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>> par0, opt_ref<vector<int>>\
    \ dep0, opt_ref<vector<int>> head0, opt_ref<vector<int>> heavy0, opt_ref<vector<int>>\
    \ pos0) {\n        if (par0) par.swap(*par0);\n        if (dep0) dep.swap(*dep0);\n\
    \        if (head0) head.swap(*head0);\n        if (heavy0) heavy.swap(*heavy0);\n\
    \        if (pos0) pos.swap(*pos0);\n    }\n#endif\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.hpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree/hld_path_query.test.cpp
  - tests/tree/hld_lca.test.cpp
documentation_of: tree/hld.hpp
layout: document
redirect_from:
- /library/tree/hld.hpp
- /library/tree/hld.hpp.html
title: tree/hld.hpp
---
