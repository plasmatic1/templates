---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/hash_utils.test.cpp
    title: tests/string/hash_utils.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"string/hash_utils.hpp\"\
    \n\n// Hashing stuff\nconst int FIXED_BASE = 0, RAND_BASE = 1 << 0;\nconst ll\
    \ MOD = 999999999999999989;\nll BASE = 131;\n\nvector<ll> _hash_pows;\ntemplate\
    \ <int MODE> void init_hash(int MAX_N) {\n    if (MODE & RAND_BASE) {\n      \
    \  mt19937 mt(RANDOM);\n        BASE = uniform_int_distribution<ll>(MOD/2, MOD-2)(mt);\n\
    \    }\n\n    _hash_pows.resize(MAX_N + 1);\n    _hash_pows[0] = 1LL;\n    for\
    \ (auto i = 1; i <= MAX_N; i++)\n        _hash_pows[i] = __int128(_hash_pows[i\
    \ - 1]) * BASE % MOD;\n}\ntemplate <typename It> ll hget(It hs, int l, int r)\
    \ {\n    __int128 res = (hs[r] - __int128(hs[l - 1]) * _hash_pows[r - l + 1])\
    \ % MOD;\n    if (res < 0) res += MOD;\n    return res;\n}\nll happend(ll hsh,\
    \ int val) { return (__int128(hsh) * BASE + val) % MOD; }\nll hconcat(ll hshLeft,\
    \ ll hshRight, int szRight) { return (__int128(hshLeft) * _hash_pows[szRight]\
    \ + hshRight) % MOD; }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Hashing stuff\nconst int\
    \ FIXED_BASE = 0, RAND_BASE = 1 << 0;\nconst ll MOD = 999999999999999989;\nll\
    \ BASE = 131;\n\nvector<ll> _hash_pows;\ntemplate <int MODE> void init_hash(int\
    \ MAX_N) {\n    if (MODE & RAND_BASE) {\n        mt19937 mt(RANDOM);\n       \
    \ BASE = uniform_int_distribution<ll>(MOD/2, MOD-2)(mt);\n    }\n\n    _hash_pows.resize(MAX_N\
    \ + 1);\n    _hash_pows[0] = 1LL;\n    for (auto i = 1; i <= MAX_N; i++)\n   \
    \     _hash_pows[i] = __int128(_hash_pows[i - 1]) * BASE % MOD;\n}\ntemplate <typename\
    \ It> ll hget(It hs, int l, int r) {\n    __int128 res = (hs[r] - __int128(hs[l\
    \ - 1]) * _hash_pows[r - l + 1]) % MOD;\n    if (res < 0) res += MOD;\n    return\
    \ res;\n}\nll happend(ll hsh, int val) { return (__int128(hsh) * BASE + val) %\
    \ MOD; }\nll hconcat(ll hshLeft, ll hshRight, int szRight) { return (__int128(hshLeft)\
    \ * _hash_pows[szRight] + hshRight) % MOD; }\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: string/hash_utils.hpp
  requiredBy: []
  timestamp: '2022-01-04 15:14:59-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/hash_utils.test.cpp
documentation_of: string/hash_utils.hpp
layout: document
redirect_from:
- /library/string/hash_utils.hpp
- /library/string/hash_utils.hpp.html
title: string/hash_utils.hpp
---
