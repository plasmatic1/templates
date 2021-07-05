---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_sparse_table.test.cpp
    title: tests/tree/lca_sparse_table.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tree/lca_sparse_table.hpp\"\
    \n\n// Due to some limitations with the current format of the templates, I cannot\
    \ use the sparse_table.hpp template here\ntemplate <typename GraphType, typename\
    \ EdgeType> struct LCASparseTable {\n    EdgeType E;\n    vector<int> dep, tour,\
    \ fst;\n    vector<vector<int>> tb;\n    int N, lg;\n    int minByDep(int a, int\
    \ b) { return dep[a] < dep[b] ? a : b; }\n    void init(int N, GraphType &g, int\
    \ rt) {\n        dep.assign(N+1, 0); fst.assign(N+1, 0); tour.clear();\n     \
    \   function<void(int, int)> dfs = [&] (int c, int p) {\n            tour.push_back(c);\n\
    \            fst[c] = tour.size();\n            for (auto to : g[c]) {\n     \
    \           int v = E.v(to);\n                if (v != p) {\n                \
    \    dep[v] = dep[c] + 1;\n                    dfs(v, c);\n                  \
    \  tour.push_back(c);\n                }\n            }\n        };\n        dfs(rt,\
    \ -1);\n\n        N = tour.size(); lg = __lg(N);\n        tb.assign(lg+1, vector<int>(N+1));\n\
    \        copy(tour.begin(), tour.end(), tb[0].begin()+1);\n        for (auto i\
    \ = 1; i <= lg; i++) {\n            int jmp = 1 << (i-1), end = N - (1<<i) + 1;\n\
    \            for (auto j = 1; j <= end; j++)\n                tb[i][j] = minByDep(tb[i-1][j],\
    \ tb[i-1][j+jmp]);\n        }\n    }\n    int lca(int a, int b) {\n        a =\
    \ fst[a]; b = fst[b];\n        if (a > b) swap(a, b);\n        int bit = __lg(b-a+1);\n\
    \        return minByDep(tb[bit][a], tb[bit][b-(1<<bit)+1]);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Due to some limitations\
    \ with the current format of the templates, I cannot use the sparse_table.hpp\
    \ template here\ntemplate <typename GraphType, typename EdgeType> struct LCASparseTable\
    \ {\n    EdgeType E;\n    vector<int> dep, tour, fst;\n    vector<vector<int>>\
    \ tb;\n    int N, lg;\n    int minByDep(int a, int b) { return dep[a] < dep[b]\
    \ ? a : b; }\n    void init(int N, GraphType &g, int rt) {\n        dep.assign(N+1,\
    \ 0); fst.assign(N+1, 0); tour.clear();\n        function<void(int, int)> dfs\
    \ = [&] (int c, int p) {\n            tour.push_back(c);\n            fst[c] =\
    \ tour.size();\n            for (auto to : g[c]) {\n                int v = E.v(to);\n\
    \                if (v != p) {\n                    dep[v] = dep[c] + 1;\n   \
    \                 dfs(v, c);\n                    tour.push_back(c);\n       \
    \         }\n            }\n        };\n        dfs(rt, -1);\n\n        N = tour.size();\
    \ lg = __lg(N);\n        tb.assign(lg+1, vector<int>(N+1));\n        copy(tour.begin(),\
    \ tour.end(), tb[0].begin()+1);\n        for (auto i = 1; i <= lg; i++) {\n  \
    \          int jmp = 1 << (i-1), end = N - (1<<i) + 1;\n            for (auto\
    \ j = 1; j <= end; j++)\n                tb[i][j] = minByDep(tb[i-1][j], tb[i-1][j+jmp]);\n\
    \        }\n    }\n    int lca(int a, int b) {\n        a = fst[a]; b = fst[b];\n\
    \        if (a > b) swap(a, b);\n        int bit = __lg(b-a+1);\n        return\
    \ minByDep(tb[bit][a], tb[bit][b-(1<<bit)+1]);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/lca_sparse_table.hpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree/lca_sparse_table.test.cpp
documentation_of: tree/lca_sparse_table.hpp
layout: document
redirect_from:
- /library/tree/lca_sparse_table.hpp
- /library/tree/lca_sparse_table.hpp.html
title: tree/lca_sparse_table.hpp
---
