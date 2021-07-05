---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"graph/dijkstra.hpp\"\
    \n\ntemplate <typename GraphType, typename EdgeType> vector<typename EdgeType::WeightType>\
    \ dijkstra(int N, GraphType &g, initializer_list<int> start, typename EdgeType::WeightType\
    \ initDis) {\n    static EdgeType E;\n    using w_t = typename EdgeType::WeightType;\
    \ using st = pair<w_t, int>;\n    vector<w_t> dis(N+1, initDis);\n    priority_queue<st,\
    \ vector<st>, greater<st>> pq;\n    for (auto s : start) {\n        pq.emplace(0,\
    \ s);\n        dis[s] = 0;\n    }\n    while (!pq.empty()) {\n        auto [w,\
    \ c] = pq.top(); pq.pop();\n        if (w > dis[c]) continue;\n        for (auto\
    \ _to : g[c]) {\n            int to = E.v(_to); w_t alt = dis[c] + E.w(_to);\n\
    \            if (alt < dis[to]) {\n                dis[to] = alt;\n          \
    \      pq.emplace(alt, to);\n            }\n        }\n    }\n    return dis;\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <typename GraphType,\
    \ typename EdgeType> vector<typename EdgeType::WeightType> dijkstra(int N, GraphType\
    \ &g, initializer_list<int> start, typename EdgeType::WeightType initDis) {\n\
    \    static EdgeType E;\n    using w_t = typename EdgeType::WeightType; using\
    \ st = pair<w_t, int>;\n    vector<w_t> dis(N+1, initDis);\n    priority_queue<st,\
    \ vector<st>, greater<st>> pq;\n    for (auto s : start) {\n        pq.emplace(0,\
    \ s);\n        dis[s] = 0;\n    }\n    while (!pq.empty()) {\n        auto [w,\
    \ c] = pq.top(); pq.pop();\n        if (w > dis[c]) continue;\n        for (auto\
    \ _to : g[c]) {\n            int to = E.v(_to); w_t alt = dis[c] + E.w(_to);\n\
    \            if (alt < dis[to]) {\n                dis[to] = alt;\n          \
    \      pq.emplace(alt, to);\n            }\n        }\n    }\n    return dis;\n\
    }\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
