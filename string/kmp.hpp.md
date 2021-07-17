---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"string/kmp.hpp\"\
    \n\n/*\n * Assume `s` is a string that is 0-indexed\n * Let pi[i] -> longest proper\
    \ prefix `k` of s[0..i] s.t. s[0..k-1] == s[i-k+1..i].  This is known as prefix\
    \ property\n *\n * 1: pi[i-1] -> pi[i] can increase by at most 1.  If this was\
    \ not the case, then we can delete the last character of\n * pi[i] and obtain\
    \ a better result for pi[i-1]\n *\n * 2: To calculate pi[i] we enumerate all values\
    \ `j` s.t. the prefix property holds for s[0..i-1], and pick the longest one\n\
    \ * s.t. s[j] == s[i].  This follows from (1)\n *\n * 2a: We can do this by repeatedly\
    \ picking the largest value of `j` we have not tried yet\n * 2b: To do this we\
    \ can begin with pi[i-1] (which is by definition the largest `j`) and move iteratively\
    \ from there\n * 2c: pi[i-1] allows us to map s[i-pi[i-1]+1..i] to s[0..pi[i-1]-1],\
    \ which means that the next largest `j` will be at\n * pi[pi[i-1]-1] (which is\
    \ the first pi[i-1] chars of s and is guaranteed to be less than pi[i-1].  We\
    \ then repeat\n * iteratively until we find a value.\n */\ntemplate <typename\
    \ Container> vector<int> kmp(int N, const Container &s) {\n    vector<int> pi(N);\n\
    \    for (int i = 1; i < N; i++) {\n        int cur = pi[i-1];\n        while\
    \ (cur && s[i] != s[cur]) cur = pi[cur-1];\n        if (s[i] == s[cur]) cur++;\n\
    \        pi[i] = cur;\n    }\n    return pi;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n/*\n * Assume `s` is a string\
    \ that is 0-indexed\n * Let pi[i] -> longest proper prefix `k` of s[0..i] s.t.\
    \ s[0..k-1] == s[i-k+1..i].  This is known as prefix property\n *\n * 1: pi[i-1]\
    \ -> pi[i] can increase by at most 1.  If this was not the case, then we can delete\
    \ the last character of\n * pi[i] and obtain a better result for pi[i-1]\n *\n\
    \ * 2: To calculate pi[i] we enumerate all values `j` s.t. the prefix property\
    \ holds for s[0..i-1], and pick the longest one\n * s.t. s[j] == s[i].  This follows\
    \ from (1)\n *\n * 2a: We can do this by repeatedly picking the largest value\
    \ of `j` we have not tried yet\n * 2b: To do this we can begin with pi[i-1] (which\
    \ is by definition the largest `j`) and move iteratively from there\n * 2c: pi[i-1]\
    \ allows us to map s[i-pi[i-1]+1..i] to s[0..pi[i-1]-1], which means that the\
    \ next largest `j` will be at\n * pi[pi[i-1]-1] (which is the first pi[i-1] chars\
    \ of s and is guaranteed to be less than pi[i-1].  We then repeat\n * iteratively\
    \ until we find a value.\n */\ntemplate <typename Container> vector<int> kmp(int\
    \ N, const Container &s) {\n    vector<int> pi(N);\n    for (int i = 1; i < N;\
    \ i++) {\n        int cur = pi[i-1];\n        while (cur && s[i] != s[cur]) cur\
    \ = pi[cur-1];\n        if (s[i] == s[cur]) cur++;\n        pi[i] = cur;\n   \
    \ }\n    return pi;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: string/kmp.hpp
  requiredBy: []
  timestamp: '2021-07-17 02:13:51-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/kmp.hpp
layout: document
redirect_from:
- /library/string/kmp.hpp
- /library/string/kmp.hpp.html
title: string/kmp.hpp
---
