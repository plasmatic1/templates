---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_binary_lift.test.cpp
    title: tests/tree/lca_binary_lift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus ==\
    \ 201703L // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
    \ // for some templates\n#endif\nusing ll = long long; using ull = unsigned long\
    \ long; using ld = long double;\nusing pii = pair<int, int>; using pll = pair<long\
    \ long, long long>;\n#ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
    \ // Common file\n#include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\
    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,\
    \ comp, rb_tree_tag, tree_order_statistics_node_update>;\ntemplate <typename K,\
    \ typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n// HashSet\n#include <ext/pb_ds/assoc_container.hpp>\n\
    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,\
    \ Hash>;\ntemplate <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\nconst ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };\n#endif\n//\
    \ More utilities\nint SZ(string &v) { return v.length(); }\ntemplate <typename\
    \ C> int SZ(C &v) { return v.size(); }\ntemplate <typename C> void UNIQUE(vector<C>\
    \ &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());\
    \ }\ntemplate <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }\n\
    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }\nconst\
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tree/lca_binary_lift.hpp\"\
    \n\ntemplate <typename GraphType, typename EdgeType> struct LCABinaryLift {\n\
    \    EdgeType E;\n    int lg;\n    vector<int> dep;\n    vector<vector<int>> tb;\n\
    \    void init(int N, GraphType &g, int rt) {\n        lg = 31 - __builtin_clz(N)\
    \ + 1;\n        tb.assign(lg, vector<int>(N + 1, -1)); dep.assign(N + 1, 0);\n\
    \        function<void(int, int)> dfs = [&] (int c, int p) {\n            tb[0][c]\
    \ = p;\n            for (auto to : g[c]) {\n                int v = E.v(to);\n\
    \                if (v != p) {\n                    dep[v] = dep[c] + 1;\n   \
    \                 dfs(v, c);\n                }\n            }\n        };\n \
    \       dfs(rt, -1);\n        for (auto i = 1; i < lg; i++) {\n            for\
    \ (auto j = 1; j <= N; j++) {\n                int pp = tb[i - 1][j];\n      \
    \          tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];\n            }\n        }\n\
    \    }\n    int lca(int a, int b) {\n        if (a == b) return a;\n        if\
    \ (dep[a] > dep[b]) swap(a, b);\n        int delta = dep[b] - dep[a];\n      \
    \  for (auto i = 0; i < lg; i++)\n            if ((delta >> i) & 1)\n        \
    \        b = tb[i][b];\n        if (a == b) return a;\n        for (auto i = lg-1;\
    \ i >= 0; i--) {\n            if (tb[i][a] != tb[i][b]) {\n                a =\
    \ tb[i][a];\n                b = tb[i][b];\n            }\n        }\n       \
    \ return tb[0][a];\n    }\n\n#if __cplusplus == 201703L // CPP17 only things\n\
    \    void bind(opt_ref<vector<int>> dep0, opt_ref<vector<vector<int>>> tb0) {\n\
    \        if (dep0) dep.swap(*dep0);\n        if (tb0) tb.swap(*tb0);\n    }\n\
    #endif\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <typename GraphType,\
    \ typename EdgeType> struct LCABinaryLift {\n    EdgeType E;\n    int lg;\n  \
    \  vector<int> dep;\n    vector<vector<int>> tb;\n    void init(int N, GraphType\
    \ &g, int rt) {\n        lg = 31 - __builtin_clz(N) + 1;\n        tb.assign(lg,\
    \ vector<int>(N + 1, -1)); dep.assign(N + 1, 0);\n        function<void(int, int)>\
    \ dfs = [&] (int c, int p) {\n            tb[0][c] = p;\n            for (auto\
    \ to : g[c]) {\n                int v = E.v(to);\n                if (v != p)\
    \ {\n                    dep[v] = dep[c] + 1;\n                    dfs(v, c);\n\
    \                }\n            }\n        };\n        dfs(rt, -1);\n        for\
    \ (auto i = 1; i < lg; i++) {\n            for (auto j = 1; j <= N; j++) {\n \
    \               int pp = tb[i - 1][j];\n                tb[i][j] = pp == -1 ?\
    \ -1 : tb[i - 1][pp];\n            }\n        }\n    }\n    int lca(int a, int\
    \ b) {\n        if (a == b) return a;\n        if (dep[a] > dep[b]) swap(a, b);\n\
    \        int delta = dep[b] - dep[a];\n        for (auto i = 0; i < lg; i++)\n\
    \            if ((delta >> i) & 1)\n                b = tb[i][b];\n        if\
    \ (a == b) return a;\n        for (auto i = lg-1; i >= 0; i--) {\n           \
    \ if (tb[i][a] != tb[i][b]) {\n                a = tb[i][a];\n               \
    \ b = tb[i][b];\n            }\n        }\n        return tb[0][a];\n    }\n\n\
    #if __cplusplus == 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>>\
    \ dep0, opt_ref<vector<vector<int>>> tb0) {\n        if (dep0) dep.swap(*dep0);\n\
    \        if (tb0) tb.swap(*tb0);\n    }\n#endif\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/lca_binary_lift.hpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree/lca_binary_lift.test.cpp
documentation_of: tree/lca_binary_lift.hpp
layout: document
redirect_from:
- /library/tree/lca_binary_lift.hpp
- /library/tree/lca_binary_lift.hpp.html
title: tree/lca_binary_lift.hpp
---
