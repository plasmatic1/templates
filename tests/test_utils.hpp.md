---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: tests/math/choose.test.cpp
    title: tests/math/choose.test.cpp
  - icon: ':x:'
    path: tests/math/choose_non_prime_mod.test.cpp
    title: tests/math/choose_non_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/eea.test.cpp
    title: tests/math/eea.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_determinant.test.cpp
    title: tests/math/matrix_determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_inverse.test.cpp
    title: tests/math/matrix_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_mul.test.cpp
    title: tests/math/matrix_mul.test.cpp
  - icon: ':x:'
    path: tests/math/matrix_solve_linear.test.cpp
    title: tests/math/matrix_solve_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/modint.test.cpp
    title: tests/math/modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/permute.test.cpp
    title: tests/math/permute.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_factor1.test.cpp
    title: tests/math/prime_factor1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_factor2.test.cpp
    title: tests/math/prime_factor2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/stirling2.test.cpp
    title: tests/math/stirling2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/totient.test.cpp
    title: tests/math/totient.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rank_compression.test.cpp
    title: tests/rank_compression.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/hash_utils.test.cpp
    title: tests/string/hash_utils.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/manachers.test.cpp
    title: tests/string/manachers.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/suffix_array.test.cpp
    title: tests/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/suffix_array_lcp.test.cpp
    title: tests/string/suffix_array_lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/suffix_automaton.test.cpp
    title: tests/string/suffix_automaton.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/string/z_algorithm.test.cpp
    title: tests/string/z_algorithm.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_SOME_WA
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
  - tests/graph/2sat.test.cpp
  - tests/graph/bfs.test.cpp
  - tests/graph/scc.test.cpp
  - tests/graph/biconnected_components.test.cpp
  - tests/math/matrix_solve_linear.test.cpp
  - tests/math/modint.test.cpp
  - tests/math/totient.test.cpp
  - tests/math/permute.test.cpp
  - tests/math/matrix_determinant.test.cpp
  - tests/math/matrix_mul.test.cpp
  - tests/math/stirling2.test.cpp
  - tests/math/prime_factor2.test.cpp
  - tests/math/prime_factor1.test.cpp
  - tests/math/choose.test.cpp
  - tests/math/eea.test.cpp
  - tests/math/choose_non_prime_mod.test.cpp
  - tests/math/matrix_inverse.test.cpp
  - tests/string/suffix_array_lcp.test.cpp
  - tests/string/suffix_automaton.test.cpp
  - tests/string/z_algorithm.test.cpp
  - tests/string/suffix_array.test.cpp
  - tests/string/manachers.test.cpp
  - tests/string/hash_utils.test.cpp
  - tests/rank_compression.test.cpp
  - tests/ds/segment_tree_lazy.test.cpp
  - tests/ds/segment_tree.test.cpp
  - tests/ds/sparse_table.test.cpp
  - tests/ds/bit.test.cpp
  - tests/ds/dsu.test.cpp
  - tests/ds/li_chao_tree.test.cpp
documentation_of: tests/test_utils.hpp
layout: document
redirect_from:
- /library/tests/test_utils.hpp
- /library/tests/test_utils.hpp.html
title: tests/test_utils.hpp
---
