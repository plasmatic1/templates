---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/manachers.test.cpp
    title: tests/string/manachers.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"string/manachers.hpp\"\
    \n\n/*\n * d[i] = Longest odd-length palindrome centered at i.  Formally, largest\
    \ value d[i] s.t. s[i-k] == s[i+k] for all\n * 0<=k<d[i].\n *\n * This algorithm\
    \ works almost identically to z-algorithm.  For more information and explanation,\
    \ see\n * string/z_algorithm.hpp\n *\n * The key differences between the algorithms\
    \ are: instead of 'shifting' from i -> i-l when using precomputed values,\n *\
    \ we instead flip across the midpoint of rightmost palindrome substring we found\
    \ to find our precomputed value.\n * Additionally, we extend out in both directions\
    \ instead of only forwards as we are looking for palindromes.\n *\n * To find\
    \ the longest palindromes for even locations, add placeholders between each character.\n\
    \ */\ntemplate <typename Container> vector<int> manachers(int N, const Container\
    \ &s) {\n    vector<int> d(N);\n    int l = 0, r = -1;\n    for (int i = 0; i\
    \ < N; i++) {\n        if (i <= r) d[i] = min(r-i+1, d[l + r - i]); // flip across\
    \ (l+r)/2\n        while (0 <= i-d[i] && i+d[i] < N && s[i-d[i]] == s[i+d[i]])\
    \ d[i]++;\n        if (i+d[i]-1 > r) {\n            l = i-d[i]+1;\n          \
    \  r = i+d[i]-1;\n        }\n    }\n    return d;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n/*\n * d[i] = Longest odd-length\
    \ palindrome centered at i.  Formally, largest value d[i] s.t. s[i-k] == s[i+k]\
    \ for all\n * 0<=k<d[i].\n *\n * This algorithm works almost identically to z-algorithm.\
    \  For more information and explanation, see\n * string/z_algorithm.hpp\n *\n\
    \ * The key differences between the algorithms are: instead of 'shifting' from\
    \ i -> i-l when using precomputed values,\n * we instead flip across the midpoint\
    \ of rightmost palindrome substring we found to find our precomputed value.\n\
    \ * Additionally, we extend out in both directions instead of only forwards as\
    \ we are looking for palindromes.\n *\n * To find the longest palindromes for\
    \ even locations, add placeholders between each character.\n */\ntemplate <typename\
    \ Container> vector<int> manachers(int N, const Container &s) {\n    vector<int>\
    \ d(N);\n    int l = 0, r = -1;\n    for (int i = 0; i < N; i++) {\n        if\
    \ (i <= r) d[i] = min(r-i+1, d[l + r - i]); // flip across (l+r)/2\n        while\
    \ (0 <= i-d[i] && i+d[i] < N && s[i-d[i]] == s[i+d[i]]) d[i]++;\n        if (i+d[i]-1\
    \ > r) {\n            l = i-d[i]+1;\n            r = i+d[i]-1;\n        }\n  \
    \  }\n    return d;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: string/manachers.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/manachers.test.cpp
documentation_of: string/manachers.hpp
layout: document
redirect_from:
- /library/string/manachers.hpp
- /library/string/manachers.hpp.html
title: string/manachers.hpp
---
