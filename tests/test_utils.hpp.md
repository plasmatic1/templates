---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/bit.test.cpp
    title: tests/ds/bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/dsu.test.cpp
    title: tests/ds/dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/li_chao_tree.test.cpp
    title: tests/ds/li_chao_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree.test.cpp
    title: tests/ds/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree_lazy.test.cpp
    title: tests/ds/segment_tree_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/sparse_table.test.cpp
    title: tests/ds/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/2sat.test.cpp
    title: tests/graph/2sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/articulation_points.test.cpp
    title: tests/graph/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: tests/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/biconnected_components.test.cpp
    title: tests/graph/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/bridges.test.cpp
    title: tests/graph/bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/scc.test.cpp
    title: tests/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/spfa.test.cpp
    title: tests/graph/spfa.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\ntemplate <typename\
    \ T> using opt_ref = optional<reference_wrapper<T>>; // for some templates\nusing\
    \ ll = long long; using ull = unsigned long long; using ld = long double;\nusing\
    \ pii = pair<int, int>; using pll = pair<long long, long long>;\n#ifdef __GNUG__\n\
    // PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp> // Common\
    \ file\n#include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntemplate\
    \ <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\ntemplate <typename K, typename\
    \ V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tests/test_utils.hpp\"\
    \n\n// I/O\ntemplate <typename T> void print(T v) {\n    cout << v << '\\n';\n\
    }\n\ntemplate <typename T, typename... Rest> void print(T v, Rest... vs) {\n \
    \   cout << v << ' ';\n    print(vs...);\n}\n\nvoid fast_io() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n}\n\n// Reading operators\ntemplate <typename T, typename\
    \ U> istream& operator>>(istream& in, pair<T, U> &o) {\n    return in >> o.first\
    \ >> o.second;\n}\n\n// Read helpers\nint readi() {\n    int x; cin >> x;\n  \
    \  return x;\n}\n\nll readl() {\n    ll x; cin >> x;\n    return x;\n}\n\ntemplate\
    \ <typename T> vector<T> readv(int n) {\n    vector<T> res(n);\n    for (auto\
    \ &x : res) cin >> x;\n    return res;\n}\n\n// Functional stuff\ntemplate <typename\
    \ T> vector<pair<int, T>> enumerate(vector<T> v, int start = 0) {\n    vector<pair<int,\
    \ T>> res;\n    for (auto &x : v)\n        res.emplace_back(start++, x);\n   \
    \ return res;\n}\n\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// I/O\ntemplate <typename\
    \ T> void print(T v) {\n    cout << v << '\\n';\n}\n\ntemplate <typename T, typename...\
    \ Rest> void print(T v, Rest... vs) {\n    cout << v << ' ';\n    print(vs...);\n\
    }\n\nvoid fast_io() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\
    }\n\n// Reading operators\ntemplate <typename T, typename U> istream& operator>>(istream&\
    \ in, pair<T, U> &o) {\n    return in >> o.first >> o.second;\n}\n\n// Read helpers\n\
    int readi() {\n    int x; cin >> x;\n    return x;\n}\n\nll readl() {\n    ll\
    \ x; cin >> x;\n    return x;\n}\n\ntemplate <typename T> vector<T> readv(int\
    \ n) {\n    vector<T> res(n);\n    for (auto &x : res) cin >> x;\n    return res;\n\
    }\n\n// Functional stuff\ntemplate <typename T> vector<pair<int, T>> enumerate(vector<T>\
    \ v, int start = 0) {\n    vector<pair<int, T>> res;\n    for (auto &x : v)\n\
    \        res.emplace_back(start++, x);\n    return res;\n}\n\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tests/test_utils.hpp
  requiredBy: []
  timestamp: '2021-06-14 21:42:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ds/bit.test.cpp
  - tests/ds/segment_tree_lazy.test.cpp
  - tests/ds/segment_tree.test.cpp
  - tests/ds/sparse_table.test.cpp
  - tests/ds/dsu.test.cpp
  - tests/ds/li_chao_tree.test.cpp
  - tests/graph/articulation_points.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/bfs.test.cpp
  - tests/graph/spfa.test.cpp
  - tests/graph/biconnected_components.test.cpp
  - tests/graph/bridges.test.cpp
  - tests/graph/scc.test.cpp
  - tests/graph/2sat.test.cpp
documentation_of: tests/test_utils.hpp
layout: document
redirect_from:
- /library/tests/test_utils.hpp
- /library/tests/test_utils.hpp.html
title: tests/test_utils.hpp
---
