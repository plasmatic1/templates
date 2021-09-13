---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/spfa.test.cpp
    title: tests/graph/spfa.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"graph/spfa.hpp\"\
    \n\ntemplate <typename GraphType, typename EdgeType> vector<typename EdgeType::WeightType>\
    \ spfa(int N, GraphType &g, initializer_list<int> start, typename EdgeType::WeightType\
    \ initDis) {\n    static EdgeType E;\n    using w_t = typename EdgeType::WeightType;\n\
    \    vector<w_t> dis(N+1, initDis);\n    vector<int> inq(N+1, false);\n    queue<int>\
    \ q;\n    for (auto s : start) {\n        q.push(s);\n        dis[s] = 0;\n  \
    \      inq[s] = false;\n    }\n    while (!q.empty()) {\n        int c = q.front();\
    \ q.pop();\n        inq[c] = false;\n        for (auto _to : g[c]) {\n       \
    \     int to = E.v(_to); w_t alt = dis[c] + E.w(_to);\n            if (alt < dis[to])\
    \ {\n                dis[to] = alt;\n                if (!inq[to]) {\n       \
    \             inq[to] = true;\n                    q.push(to);\n             \
    \   }\n            }\n        }\n    }\n    return dis;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <typename GraphType,\
    \ typename EdgeType> vector<typename EdgeType::WeightType> spfa(int N, GraphType\
    \ &g, initializer_list<int> start, typename EdgeType::WeightType initDis) {\n\
    \    static EdgeType E;\n    using w_t = typename EdgeType::WeightType;\n    vector<w_t>\
    \ dis(N+1, initDis);\n    vector<int> inq(N+1, false);\n    queue<int> q;\n  \
    \  for (auto s : start) {\n        q.push(s);\n        dis[s] = 0;\n        inq[s]\
    \ = false;\n    }\n    while (!q.empty()) {\n        int c = q.front(); q.pop();\n\
    \        inq[c] = false;\n        for (auto _to : g[c]) {\n            int to\
    \ = E.v(_to); w_t alt = dis[c] + E.w(_to);\n            if (alt < dis[to]) {\n\
    \                dis[to] = alt;\n                if (!inq[to]) {\n           \
    \         inq[to] = true;\n                    q.push(to);\n                }\n\
    \            }\n        }\n    }\n    return dis;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/spfa.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/spfa.test.cpp
documentation_of: graph/spfa.hpp
layout: document
redirect_from:
- /library/graph/spfa.hpp
- /library/graph/spfa.hpp.html
title: graph/spfa.hpp
---
