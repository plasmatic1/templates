---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/string/suffix_automaton.test.cpp
    title: tests/string/suffix_automaton.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"string/suffix_automaton.hpp\"\
    \n\ntemplate <int MN> struct SAM {\n    struct state {\n        int len, link;\n\
    \        map<char, int> to;\n    };\n    state st[MN*2];\n    int last, sz = 0;\n\
    \    void init() {\n        for (auto i = 0; i < MN*2; i++) st[i] = {0, 0, map<char,\
    \ int>()};\n        st[0] = {0, -1, map<char, int>()};\n        sz = 1; last =\
    \ 0;\n    }\n    void extend(char c) {\n        int cur = sz++, p = last;\n  \
    \      st[cur].len = st[last].len + 1;\n        for (; p != -1 && !st[p].to.count(c);\
    \ p = st[p].link)\n            st[p].to[c] = cur;\n        if (p == -1) st[cur].link\
    \ = 0;\n        else {\n            int q = st[p].to[c];\n            if (st[p].len\
    \ + 1 == st[q].len) st[cur].link = q; // transition is continuous, we can link\
    \ directly to Q as the parent in the prefix trie\n            else { // transition\
    \ is discontinuous, we must split node q into p+1, \n                int clone\
    \ = sz++; \n                st[clone] = st[q]; st[clone].len = st[p].len + 1;\n\
    \                for (; p != -1 && st[p].to[c] == q; p = st[p].link)\n       \
    \             st[p].to[c] = clone;\n                st[cur].link = st[q].link\
    \ = clone;\n            }\n        }\n\n        last = cur;\n    }\n};\n\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <int MN> struct SAM\
    \ {\n    struct state {\n        int len, link;\n        map<char, int> to;\n\
    \    };\n    state st[MN*2];\n    int last, sz = 0;\n    void init() {\n     \
    \   for (auto i = 0; i < MN*2; i++) st[i] = {0, 0, map<char, int>()};\n      \
    \  st[0] = {0, -1, map<char, int>()};\n        sz = 1; last = 0;\n    }\n    void\
    \ extend(char c) {\n        int cur = sz++, p = last;\n        st[cur].len = st[last].len\
    \ + 1;\n        for (; p != -1 && !st[p].to.count(c); p = st[p].link)\n      \
    \      st[p].to[c] = cur;\n        if (p == -1) st[cur].link = 0;\n        else\
    \ {\n            int q = st[p].to[c];\n            if (st[p].len + 1 == st[q].len)\
    \ st[cur].link = q; // transition is continuous, we can link directly to Q as\
    \ the parent in the prefix trie\n            else { // transition is discontinuous,\
    \ we must split node q into p+1, \n                int clone = sz++; \n      \
    \          st[clone] = st[q]; st[clone].len = st[p].len + 1;\n               \
    \ for (; p != -1 && st[p].to[c] == q; p = st[p].link)\n                    st[p].to[c]\
    \ = clone;\n                st[cur].link = st[q].link = clone;\n            }\n\
    \        }\n\n        last = cur;\n    }\n};\n\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: string/suffix_automaton.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/string/suffix_automaton.test.cpp
documentation_of: string/suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/suffix_automaton.hpp
- /library/string/suffix_automaton.hpp.html
title: string/suffix_automaton.hpp
---
