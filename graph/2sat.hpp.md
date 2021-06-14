---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/2sat.test.cpp
    title: tests/graph/2sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\nusing ll = long long;\
    \ using ull = unsigned long long; using ld = long double;\nusing pii = pair<int,\
    \ int>; using pll = pair<long long, long long>;\n#ifdef __GNUG__\n// PBDS order\
    \ statistic tree\n#include <ext/pb_ds/assoc_container.hpp> // Common file\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntemplate <typename\
    \ T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\ntemplate <typename K, typename V, class\
    \ comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\
    // HashSet\n#include <ext/pb_ds/assoc_container.hpp>\ntemplate <typename T, class\
    \ Hash> using hashset = gp_hash_table<T, null_type, Hash>;\ntemplate <typename\
    \ K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;\nconst\
    \ ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };\n#endif\n//\
    \ More utilities\nint SZ(string &v) { return v.length(); }\ntemplate <typename\
    \ C> int SZ(C &v) { return v.size(); }\ntemplate <typename C> void UNIQUE(vector<C>\
    \ &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());\
    \ }\ntemplate <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }\n\
    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }\nconst\
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"graph/2sat.hpp\"\
    \n\nstruct TwoSat {\n    int N, cord, ccomp;\n    vector<int> ord, low, instk,\
    \ stk, comp;\n    vector<vector<int>> g;\n    void init(int N0) {\n        N =\
    \ N0; cord = ccomp = 0;\n        g.assign(N*2+1, vector<int>());\n        ord.assign(N*2+1,\
    \ 0);\n        low.assign(N*2+1, 0);\n        instk.assign(N*2+1, 0);\n      \
    \  comp.assign(N*2+1, 0);\n        stk.clear();\n    }\n    void addEdge(int a,\
    \ int b) {\n        if (a < 0) a = N-a;\n        if (b < 0) b = N-b;\n       \
    \ g[a].push_back(b);\n    }\n    void addOr(int a, int b) {\n        addEdge(-a,\
    \ b);\n        addEdge(-b, a);\n    }\n    void tarjan(int c) {\n        ord[c]\
    \ = low[c] = ++cord;\n        instk[c] = true; stk.push_back(c);\n        for\
    \ (auto to : g[c]) {\n            if (!ord[to]) {\n                tarjan(to);\n\
    \                low[c] = min(low[c], low[to]);\n            }\n            else\
    \ if (instk[to])\n                low[c] = min(low[c], ord[to]);\n        }\n\n\
    \        if (low[c] == ord[c]) {\n            int u, cc = ++ccomp;\n         \
    \   do {\n                u = stk.back(); stk.pop_back(); instk[u] = false;\n\
    \                comp[u] = cc;\n            } while (u != c);\n        }\n   \
    \ }\n    vector<int> solve() {\n        for (auto i = 1; i <= 2*N; i++)\n    \
    \        if (!ord[i])\n                tarjan(i);\n        for (auto i = 1; i\
    \ <= N; i++)\n            if (comp[i] == comp[i+N])\n                return vector<int>(N+1,\
    \ -1);\n        vector<int> res(N+1);\n        for (auto i = 1; i <= N; i++)\n\
    \            res[i] = comp[i] < comp[i+N]; // 1 > 0\n        return res;\n   \
    \ }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct TwoSat {\n    int N,\
    \ cord, ccomp;\n    vector<int> ord, low, instk, stk, comp;\n    vector<vector<int>>\
    \ g;\n    void init(int N0) {\n        N = N0; cord = ccomp = 0;\n        g.assign(N*2+1,\
    \ vector<int>());\n        ord.assign(N*2+1, 0);\n        low.assign(N*2+1, 0);\n\
    \        instk.assign(N*2+1, 0);\n        comp.assign(N*2+1, 0);\n        stk.clear();\n\
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
    \ c);\n        }\n    }\n    vector<int> solve() {\n        for (auto i = 1; i\
    \ <= 2*N; i++)\n            if (!ord[i])\n                tarjan(i);\n       \
    \ for (auto i = 1; i <= N; i++)\n            if (comp[i] == comp[i+N])\n     \
    \           return vector<int>(N+1, -1);\n        vector<int> res(N+1);\n    \
    \    for (auto i = 1; i <= N; i++)\n            res[i] = comp[i] < comp[i+N];\
    \ // 1 > 0\n        return res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/2sat.hpp
  requiredBy: []
  timestamp: '2021-06-14 14:35:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/2sat.test.cpp
documentation_of: graph/2sat.hpp
layout: document
redirect_from:
- /library/graph/2sat.hpp
- /library/graph/2sat.hpp.html
title: graph/2sat.hpp
---
