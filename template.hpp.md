---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/bit.hpp
    title: ds/bit.hpp
  - icon: ':heavy_check_mark:'
    path: ds/dsu.hpp
    title: ds/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segment_tree.hpp
    title: ds/segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segment_tree_lazy.hpp
    title: ds/segment_tree_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table.hpp
    title: ds/sparse_table.hpp
  - icon: ':warning:'
    path: fraction.cpp
    title: fraction.cpp
  - icon: ':heavy_check_mark:'
    path: graph/2sat.hpp
    title: graph/2sat.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: graph/bfs.hpp
  - icon: ':warning:'
    path: graph/bfs_0_1.hpp
    title: graph/bfs_0_1.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge_types.hpp
    title: graph/edge_types.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: graph/spfa.hpp
    title: graph/spfa.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tarjan_undirected.hpp
    title: graph/tarjan_undirected.hpp
  - icon: ':warning:'
    path: math/mod.cpp
    title: math/mod.cpp
  - icon: ':heavy_check_mark:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
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
  bundledCode: '#line 2 "template.hpp"

    #include <bits/stdc++.h>

    using namespace std;


    // Defines

    #define fs first

    #define sn second

    #define pb push_back

    #define eb emplace_back

    #define mpr make_pair

    #define mtp make_tuple

    #define all(x) (x).begin(), (x).end()

    // Basic type definitions

    #if __cplusplus == 201703L // CPP17 only things

    template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some
    templates

    #endif

    using ll = long long; using ull = unsigned long long; using ld = long double;

    using pii = pair<int, int>; using pll = pair<long long, long long>;

    #ifdef __GNUG__

    // PBDS order statistic tree

    #include <ext/pb_ds/assoc_container.hpp> // Common file

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,
    comp, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename K, typename V, class comp = less<K>> using treemap = tree<K,
    V, comp, rb_tree_tag, tree_order_statistics_node_update>;

    // HashSet

    #include <ext/pb_ds/assoc_container.hpp>

    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,
    Hash>;

    template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,
    V, Hash>;

    const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

    #endif

    // More utilities

    int SZ(string &v) { return v.length(); }

    template <typename C> int SZ(C &v) { return v.size(); }

    template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(),
    v.end()) - v.begin()); }

    template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }

    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }

    const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

    '
  code: '#pragma once

    #include <bits/stdc++.h>

    using namespace std;


    // Defines

    #define fs first

    #define sn second

    #define pb push_back

    #define eb emplace_back

    #define mpr make_pair

    #define mtp make_tuple

    #define all(x) (x).begin(), (x).end()

    // Basic type definitions

    #if __cplusplus == 201703L // CPP17 only things

    template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some
    templates

    #endif

    using ll = long long; using ull = unsigned long long; using ld = long double;

    using pii = pair<int, int>; using pll = pair<long long, long long>;

    #ifdef __GNUG__

    // PBDS order statistic tree

    #include <ext/pb_ds/assoc_container.hpp> // Common file

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,
    comp, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename K, typename V, class comp = less<K>> using treemap = tree<K,
    V, comp, rb_tree_tag, tree_order_statistics_node_update>;

    // HashSet

    #include <ext/pb_ds/assoc_container.hpp>

    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,
    Hash>;

    template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,
    V, Hash>;

    const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

    #endif

    // More utilities

    int SZ(string &v) { return v.length(); }

    template <typename C> int SZ(C &v) { return v.size(); }

    template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(),
    v.end()) - v.begin()); }

    template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }

    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }

    const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

    '
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - ds/segment_tree_lazy.hpp
  - ds/bit.hpp
  - ds/sparse_table.hpp
  - ds/dsu.hpp
  - ds/segment_tree.hpp
  - fraction.cpp
  - math/mod.cpp
  - tests/test_utils.hpp
  - graph/bfs_0_1.hpp
  - graph/tarjan_undirected.hpp
  - graph/dijkstra.hpp
  - graph/spfa.hpp
  - graph/bfs.hpp
  - graph/scc.hpp
  - graph/2sat.hpp
  - graph/edge_types.hpp
  timestamp: '2021-06-16 10:53:28-04:00'
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
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---