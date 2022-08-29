---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  - icon: ':heavy_check_mark:'
    path: tests/tree/hld_lca.test.cpp
    title: tests/tree/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree/hld_path_query.test.cpp
    title: tests/tree/hld_path_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_binary_lift.test.cpp
    title: tests/tree/lca_binary_lift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_jump.test.cpp
    title: tests/tree/lca_jump.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree/lca_sparse_table.test.cpp
    title: tests/tree/lca_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\n#define DEBUG\
    \ 1\nusing namespace std;\n\n// Defines\n#define fs first\n#define sn second\n\
    #define pb push_back\n#define eb emplace_back\n#define mpr make_pair\n#define\
    \ mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n// Basic type definitions\n\
    #if __cplusplus == 201703L // CPP17 only things\ntemplate <typename T> using opt_ref\
    \ = optional<reference_wrapper<T>>; // for some templates\n#endif\nusing ll =\
    \ long long; using ull = unsigned long long; using ld = long double;\nusing pii\
    \ = pair<int, int>; using pll = pair<long long, long long>;\n#ifdef __GNUG__\n\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"graph/edge_types.hpp\"\
    \n\nstruct Edge {\n    using EdgeType = int;\n    int v(EdgeType e) { return e;\
    \ }\n    int w(EdgeType e) { return 1; }\n    int i(EdgeType e) { throw domain_error(\"\
    no information on edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return v; }\n};\ntemplate <typename T> struct WeightedEdge {\n    using EdgeType\
    \ = pair<int, T>; using WeightType = T;\n    int v(EdgeType e) { return e.first;\
    \ }\n    T w(EdgeType e) { return e.second; }\n    int i(EdgeType e) { throw domain_error(\"\
    no information on edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e)}; }\n};\nstruct IndexedEdge {\n    using EdgeType = pair<int,\
    \ int>;\n    int v(EdgeType e) { return e.first; }\n    int w(EdgeType e) { return\
    \ 1; }\n    int i(EdgeType e) { return e.second; }\n    EdgeType swapNode(EdgeType\
    \ e, int v) { return {v, i(e)}; }\n};\ntemplate <typename T> struct WeightedIndexedEdge\
    \ {\n    using EdgeType = tuple<int, T, int>; using WeightType = T;\n    int v(EdgeType\
    \ e) { return get<0>(e); }\n    T w(EdgeType e) { return get<1>(e); }\n    int\
    \ i(EdgeType e) { return get<2>(e); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e), i(e)}; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct Edge {\n    using EdgeType\
    \ = int;\n    int v(EdgeType e) { return e; }\n    int w(EdgeType e) { return\
    \ 1; }\n    int i(EdgeType e) { throw domain_error(\"no information on edge indices\"\
    ); }\n    EdgeType swapNode(EdgeType e, int v) { return v; }\n};\ntemplate <typename\
    \ T> struct WeightedEdge {\n    using EdgeType = pair<int, T>; using WeightType\
    \ = T;\n    int v(EdgeType e) { return e.first; }\n    T w(EdgeType e) { return\
    \ e.second; }\n    int i(EdgeType e) { throw domain_error(\"no information on\
    \ edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v) { return {v, w(e)};\
    \ }\n};\nstruct IndexedEdge {\n    using EdgeType = pair<int, int>;\n    int v(EdgeType\
    \ e) { return e.first; }\n    int w(EdgeType e) { return 1; }\n    int i(EdgeType\
    \ e) { return e.second; }\n    EdgeType swapNode(EdgeType e, int v) { return {v,\
    \ i(e)}; }\n};\ntemplate <typename T> struct WeightedIndexedEdge {\n    using\
    \ EdgeType = tuple<int, T, int>; using WeightType = T;\n    int v(EdgeType e)\
    \ { return get<0>(e); }\n    T w(EdgeType e) { return get<1>(e); }\n    int i(EdgeType\
    \ e) { return get<2>(e); }\n    EdgeType swapNode(EdgeType e, int v) { return\
    \ {v, w(e), i(e)}; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/edge_types.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree/lca_binary_lift.test.cpp
  - tests/tree/hld_lca.test.cpp
  - tests/tree/hld_path_query.test.cpp
  - tests/tree/lca_sparse_table.test.cpp
  - tests/tree/lca_jump.test.cpp
  - tests/graph/articulation_points.test.cpp
  - tests/graph/bridges.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/spfa.test.cpp
  - tests/graph/bfs.test.cpp
  - tests/graph/scc.test.cpp
  - tests/graph/biconnected_components.test.cpp
documentation_of: graph/edge_types.hpp
layout: document
redirect_from:
- /library/graph/edge_types.hpp
- /library/graph/edge_types.hpp.html
title: graph/edge_types.hpp
---
