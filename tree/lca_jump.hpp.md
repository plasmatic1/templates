---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_jump.test.cpp
    title: tests/tree/lca_jump.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/74847
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tree/lca_jump.hpp\"\
    \n\n// Source: https://codeforces.com/blog/entry/74847\ntemplate <typename GraphType,\
    \ typename EdgeType> struct LCAJump {\n    EdgeType E;\n    vector<int> dep, par,\
    \ jmp;\n    void init(int N, GraphType &g, int rt) {\n        dep.assign(N+1,\
    \ 0); par.assign(N+1, -1); jmp.assign(N+1, -1);\n        function<void(int, int)>\
    \ dfs = [&] (int c, int p) {\n            par[c] = p;\n            if (c != rt)\
    \ {\n                if (dep[p] - dep[jmp[p]] == dep[jmp[p]] - dep[jmp[jmp[p]]])\n\
    \                    jmp[c] = jmp[jmp[p]];\n                else\n           \
    \         jmp[c] = p;\n            }\n            for (auto to : g[c]) {\n   \
    \             int v = E.v(to);\n                if (v != p) {\n              \
    \      dep[v] = dep[c] + 1;\n                    dfs(v, c);\n                }\n\
    \            }\n        };\n        jmp[rt] = rt;\n        dfs(rt, -1);\n    }\n\
    \    int findFirst(int u, function<bool(int)> check) {\n        while (!check(u))\
    \ {\n            if (!check(jmp[u])) u = jmp[u];\n            else u = par[u];\n\
    \        }\n        return u;\n    }\n    int up(int u, int want) {\n        while\
    \ (dep[u] > want) {\n            if (dep[jmp[u]] >= want) u = jmp[u];\n      \
    \      else u = par[u];\n        }\n        return u;\n    }\n    int lca(int\
    \ a, int b) {\n        if (dep[a] > dep[b]) swap(a, b);\n        b = up(b, dep[a]);\n\
    \        while (a != b) {\n            if (jmp[a] != jmp[b]) {\n             \
    \   a = jmp[a];\n                b = jmp[b];\n            }\n            else\
    \ {\n                a = par[a];\n                b = par[b];\n            }\n\
    \        }\n        return a;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Source: https://codeforces.com/blog/entry/74847\n\
    template <typename GraphType, typename EdgeType> struct LCAJump {\n    EdgeType\
    \ E;\n    vector<int> dep, par, jmp;\n    void init(int N, GraphType &g, int rt)\
    \ {\n        dep.assign(N+1, 0); par.assign(N+1, -1); jmp.assign(N+1, -1);\n \
    \       function<void(int, int)> dfs = [&] (int c, int p) {\n            par[c]\
    \ = p;\n            if (c != rt) {\n                if (dep[p] - dep[jmp[p]] ==\
    \ dep[jmp[p]] - dep[jmp[jmp[p]]])\n                    jmp[c] = jmp[jmp[p]];\n\
    \                else\n                    jmp[c] = p;\n            }\n      \
    \      for (auto to : g[c]) {\n                int v = E.v(to);\n            \
    \    if (v != p) {\n                    dep[v] = dep[c] + 1;\n               \
    \     dfs(v, c);\n                }\n            }\n        };\n        jmp[rt]\
    \ = rt;\n        dfs(rt, -1);\n    }\n    int findFirst(int u, function<bool(int)>\
    \ check) {\n        while (!check(u)) {\n            if (!check(jmp[u])) u = jmp[u];\n\
    \            else u = par[u];\n        }\n        return u;\n    }\n    int up(int\
    \ u, int want) {\n        while (dep[u] > want) {\n            if (dep[jmp[u]]\
    \ >= want) u = jmp[u];\n            else u = par[u];\n        }\n        return\
    \ u;\n    }\n    int lca(int a, int b) {\n        if (dep[a] > dep[b]) swap(a,\
    \ b);\n        b = up(b, dep[a]);\n        while (a != b) {\n            if (jmp[a]\
    \ != jmp[b]) {\n                a = jmp[a];\n                b = jmp[b];\n   \
    \         }\n            else {\n                a = par[a];\n               \
    \ b = par[b];\n            }\n        }\n        return a;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/lca_jump.hpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree/lca_jump.test.cpp
documentation_of: tree/lca_jump.hpp
layout: document
redirect_from:
- /library/tree/lca_jump.hpp
- /library/tree/lca_jump.hpp.html
title: tree/lca_jump.hpp
---
