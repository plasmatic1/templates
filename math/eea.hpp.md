---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/crt.hpp
    title: math/crt.hpp
  - icon: ':question:'
    path: math/mod.hpp
    title: math/mod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree.test.cpp
    title: tests/ds/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree_lazy.test.cpp
    title: tests/ds/segment_tree_lazy.test.cpp
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
    path: tests/math/stirling2.test.cpp
    title: tests/math/stirling2.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"math/eea.hpp\"\n\
    \n/*\n * ax + by = gcd(a, b)\n *\n * we know\n * bx' + (a%b)y' = gcd(a, b)\n *\n\
    \ * bx' + (a-b*(a//b))y' = gcd(a, b)\n * bx' + ay' - b*(a//b)y' = gcd(a, b)\n\
    \ * ay' + b(x' - (a//b)y') = gcd(a, b)\n */\ntemplate <typename T> T extgcd(T\
    \ a, T b, T &x, T &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n \
    \       return a;\n    }\n    T x0, y0, res = extgcd(b, a%b, x0, y0);\n    x =\
    \ y0;\n    y = x0 - (a / b) * y0;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n/*\n * ax + by = gcd(a, b)\n\
    \ *\n * we know\n * bx' + (a%b)y' = gcd(a, b)\n *\n * bx' + (a-b*(a//b))y' = gcd(a,\
    \ b)\n * bx' + ay' - b*(a//b)y' = gcd(a, b)\n * ay' + b(x' - (a//b)y') = gcd(a,\
    \ b)\n */\ntemplate <typename T> T extgcd(T a, T b, T &x, T &y) {\n    if (b ==\
    \ 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n    T x0, y0,\
    \ res = extgcd(b, a%b, x0, y0);\n    x = y0;\n    y = x0 - (a / b) * y0;\n   \
    \ return res;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/eea.hpp
  requiredBy:
  - math/crt.hpp
  - math/mod.hpp
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/ds/segment_tree_lazy.test.cpp
  - tests/ds/segment_tree.test.cpp
  - tests/math/eea.test.cpp
  - tests/math/modint.test.cpp
  - tests/math/matrix_mul.test.cpp
  - tests/math/matrix_solve_linear.test.cpp
  - tests/math/matrix_inverse.test.cpp
  - tests/math/choose_non_prime_mod.test.cpp
  - tests/math/choose.test.cpp
  - tests/math/matrix_determinant.test.cpp
  - tests/math/permute.test.cpp
  - tests/math/stirling2.test.cpp
documentation_of: math/eea.hpp
layout: document
redirect_from:
- /library/math/eea.hpp
- /library/math/eea.hpp.html
title: math/eea.hpp
---
