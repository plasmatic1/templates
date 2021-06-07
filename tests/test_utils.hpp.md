---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/bit.test.cpp
    title: tests/bit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tests/test_utils.hpp\"\
    \n\nint readi() {\n    int x; cin >> x;\n    return x;\n}\n\nll readl() {\n  \
    \  ll x; cin >> x;\n    return x;\n}\n\ntemplate <typename T> vector<T> readv(int\
    \ n) {\n    vector<T> res(n);\n    for (auto &x : res) cin >> x;\n    return res;\n\
    }\n\ntemplate <typename T> vector<pair<int, T>> enumerate(vector<T> v, int start\
    \ = 0) {\n    vector<pair<int, T>> res;\n    for (auto &x : v)\n        res.emplace_back(start++,\
    \ x);\n    return res;\n}\n\ntemplate <typename T> void print(T v) {\n    cout\
    \ << v << '\\n';\n}\n\ntemplate <typename T, typename... Rest> void print(T v,\
    \ Rest... vs) {\n    cout << v << ' ';\n    print(vs...);\n}\n\nvoid fast_io()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nint readi() {\n    int x; cin\
    \ >> x;\n    return x;\n}\n\nll readl() {\n    ll x; cin >> x;\n    return x;\n\
    }\n\ntemplate <typename T> vector<T> readv(int n) {\n    vector<T> res(n);\n \
    \   for (auto &x : res) cin >> x;\n    return res;\n}\n\ntemplate <typename T>\
    \ vector<pair<int, T>> enumerate(vector<T> v, int start = 0) {\n    vector<pair<int,\
    \ T>> res;\n    for (auto &x : v)\n        res.emplace_back(start++, x);\n   \
    \ return res;\n}\n\ntemplate <typename T> void print(T v) {\n    cout << v <<\
    \ '\\n';\n}\n\ntemplate <typename T, typename... Rest> void print(T v, Rest...\
    \ vs) {\n    cout << v << ' ';\n    print(vs...);\n}\n\nvoid fast_io() {\n   \
    \ ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tests/test_utils.hpp
  requiredBy: []
  timestamp: '2021-06-07 02:10:30-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/bit.test.cpp
documentation_of: tests/test_utils.hpp
layout: document
redirect_from:
- /library/tests/test_utils.hpp
- /library/tests/test_utils.hpp.html
title: tests/test_utils.hpp
---