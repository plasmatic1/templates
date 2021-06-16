---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"math/mod.cpp\"\n\
    \n// based on Tourist modInt orz\ntemplate <typename T, T mod> struct ModInt {\n\
    \    static_assert(sizeof(T) >= 4, \"size of T must be at least 32 bits\");\n\
    \    static_assert(is_integral<T>::value, \"T must be an integral type\");\n\n\
    \    template <typename U> static T normalize(const U& x) {\n        T res = x;\n\
    \        x %= mod;\n        if (x < 0) x += mod;\n        return res;\n    }\n\
    \n    T value;\n    constexpr ModInt() : value() {}\n    template <typename U>\
    \ ModInt(const U& x) { value = normalize(x); }\n    const T& operator()() const\
    \ { return value; }\n    template <typename U> explicit operator U() const { return\
    \ static_cast<U>(value); }\n};\n\nconst ll MOD = 1e9 + 7;\nll fix(ll &&x) { x\
    \ %= MOD; if (x < 0) x += MOD; return x; }\nll fix(ll &x) { x %= MOD; if (x <\
    \ 0) x += MOD; return x; }\nll fpow(ll x, ll y, ll mod = MOD) {\n    if (!y) return\
    \ 1LL;\n    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;\n\
    }\nll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// based on Tourist modInt\
    \ orz\ntemplate <typename T, T mod> struct ModInt {\n    static_assert(sizeof(T)\
    \ >= 4, \"size of T must be at least 32 bits\");\n    static_assert(is_integral<T>::value,\
    \ \"T must be an integral type\");\n\n    template <typename U> static T normalize(const\
    \ U& x) {\n        T res = x;\n        x %= mod;\n        if (x < 0) x += mod;\n\
    \        return res;\n    }\n\n    T value;\n    constexpr ModInt() : value()\
    \ {}\n    template <typename U> ModInt(const U& x) { value = normalize(x); }\n\
    \    const T& operator()() const { return value; }\n    template <typename U>\
    \ explicit operator U() const { return static_cast<U>(value); }\n};\n\nconst ll\
    \ MOD = 1e9 + 7;\nll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }\n\
    ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }\nll fpow(ll x, ll y,\
    \ ll mod = MOD) {\n    if (!y) return 1LL;\n    return fpow(x * x % mod, y >>\
    \ 1, mod) * ((y & 1) ? x : 1LL) % mod;\n}\nll inv(ll x, ll mod = MOD) { return\
    \ fpow(x, mod - 2, mod); }\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/mod.cpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.cpp
layout: document
redirect_from:
- /library/math/mod.cpp
- /library/math/mod.cpp.html
title: math/mod.cpp
---
