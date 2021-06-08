---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/dsu.test.cpp
    title: tests/ds/dsu.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"ds/dsu.hpp\"\n\n\
    struct DSU {\n    vector<int> dsu;\n    void init(int N) {\n        dsu.resize(N\
    \ + 1);\n        iota(dsu.begin(), dsu.end(), 0);\n    }\n    int rt(int x) {\
    \ return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }\n    void merge(int x, int y)\
    \ { // x -> y\n        dsu[rt(x)] = rt(y); }\n    bool con(int x, int y) { return\
    \ rt(x) == rt(y); }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct DSU {\n    vector<int>\
    \ dsu;\n    void init(int N) {\n        dsu.resize(N + 1);\n        iota(dsu.begin(),\
    \ dsu.end(), 0);\n    }\n    int rt(int x) { return dsu[x] == x ? x : dsu[x] =\
    \ rt(dsu[x]); }\n    void merge(int x, int y) { // x -> y\n        dsu[rt(x)]\
    \ = rt(y); }\n    bool con(int x, int y) { return rt(x) == rt(y); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/dsu.hpp
  requiredBy: []
  timestamp: '2021-06-07 23:09:50-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ds/dsu.test.cpp
documentation_of: ds/dsu.hpp
layout: document
redirect_from:
- /library/ds/dsu.hpp
- /library/ds/dsu.hpp.html
title: ds/dsu.hpp
---
