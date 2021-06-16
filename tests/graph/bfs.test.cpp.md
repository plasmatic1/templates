---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: graph/bfs.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge_types.hpp
    title: graph/edge_types.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"tests/graph/bfs.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    // Defines\n#define fs first\n#define sn second\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define all(x)\
    \ (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus == 201703L\
    \ // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
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
    \ return res;\n}\n\n#line 3 \"graph/bfs.hpp\"\n\ntemplate <typename GraphType,\
    \ typename EdgeType> vector<int> bfs(int N, GraphType &g, initializer_list<int>\
    \ start) {\n    static EdgeType E;\n    vector<int> dis(N+1, -1);\n    queue<int>\
    \ q;\n    for (auto s : start) {\n        q.push(s);\n        dis[s] = 0;\n  \
    \  }\n    while (!q.empty()) {\n        int c = q.front(); q.pop();\n        for\
    \ (auto _to : g[c]) {\n            int to = E.v(_to);\n            if (dis[to]\
    \ == -1) {\n                dis[to] = dis[c] + 1;\n                q.push(to);\n\
    \            }\n        }\n    }\n    return dis;\n}\n#line 3 \"graph/edge_types.hpp\"\
    \n\nstruct Edge {\n    using EdgeType = int;\n    int v(EdgeType e) { return e;\
    \ }\n    int w(EdgeType e) { return 1; }\n    int i(EdgeType e) { throw domain_error(\"\
    no information on edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return v; }\n};\ntemplate <typename T> struct WeightedEdge {\n    using EdgeType\
    \ = pair<int, T>; using WeightType = T;\n    int v(EdgeType e) { return e.first;\
    \ }\n    T w(EdgeType e) { return e.second; }\n    int i(EdgeType e) { throw domain_error(\"\
    no information on edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e)}; }\n};\nstruct IndexedEdge {\n    using EdgeType = pair<int,\
    \ int>;\n    int v(EdgeType e) { return e.first; }\n    int w(EdgeType e) { return\
    \ 1; }\n    int i(EdgeType e) { return e.second; }\n    EdgeType swapNode(EdgeType\
    \ e, int v) { return {v, i(e)}; }\n};\ntemplate <typename T> struct WeightedIndexedEdge\
    \ {\n    using EdgeType = tuple<int, T, int>; using WeightType = T;\n    int v(EdgeType\
    \ e) { return get<0>(e); }\n    T w(EdgeType e) { return get<1>(e); }\n    int\
    \ i(EdgeType e) { return get<2>(e); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e), i(e)}; }\n};\n#line 6 \"tests/graph/bfs.test.cpp\"\n\nconst\
    \ int MN = 101;\nint N;\nvector<int> g[MN];\n\nint main() {\n    fast_io();\n\
    \    N = readi();\n    for (int i = 1; i <= N; i++) {\n        int v = readi(),\
    \ n = readi();\n        for (auto to : readv<int>(n))\n            g[v].pb(to);\n\
    \    }\n\n    auto res = bfs<vector<int>[MN], Edge>(N, g, {1});\n    for (int\
    \ i = 1; i <= N; i++)\n        print(i, res[i]);\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../graph/bfs.hpp\"\n#include \"../../graph/edge_types.hpp\"\n\nconst int MN\
    \ = 101;\nint N;\nvector<int> g[MN];\n\nint main() {\n    fast_io();\n    N =\
    \ readi();\n    for (int i = 1; i <= N; i++) {\n        int v = readi(), n = readi();\n\
    \        for (auto to : readv<int>(n))\n            g[v].pb(to);\n    }\n\n  \
    \  auto res = bfs<vector<int>[MN], Edge>(N, g, {1});\n    for (int i = 1; i <=\
    \ N; i++)\n        print(i, res[i]);\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - graph/bfs.hpp
  - graph/edge_types.hpp
  isVerificationFile: true
  path: tests/graph/bfs.test.cpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/bfs.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/bfs.test.cpp
- /verify/tests/graph/bfs.test.cpp.html
title: tests/graph/bfs.test.cpp
---
