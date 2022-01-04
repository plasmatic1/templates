---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge_types.hpp
    title: graph/edge_types.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  - icon: ':heavy_check_mark:'
    path: tree/lca_sparse_table.hpp
    title: tree/lca_sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/tree/lca_sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"template.hpp\"\n#include\
    \ <bits/stdc++.h>\n#define DEBUG 1\nusing namespace std;\n\n// Defines\n#define\
    \ fs first\n#define sn second\n#define pb push_back\n#define eb emplace_back\n\
    #define mpr make_pair\n#define mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    // Basic type definitions\n#if __cplusplus == 201703L // CPP17 only things\ntemplate\
    \ <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates\n\
    #endif\nusing ll = long long; using ull = unsigned long long; using ld = long\
    \ double;\nusing pii = pair<int, int>; using pll = pair<long long, long long>;\n\
    #ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
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
    \ return res;\n}\n\n#line 3 \"graph/edge_types.hpp\"\n\nstruct Edge {\n    using\
    \ EdgeType = int;\n    int v(EdgeType e) { return e; }\n    int w(EdgeType e)\
    \ { return 1; }\n    int i(EdgeType e) { throw domain_error(\"no information on\
    \ edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v) { return v; }\n\
    };\ntemplate <typename T> struct WeightedEdge {\n    using EdgeType = pair<int,\
    \ T>; using WeightType = T;\n    int v(EdgeType e) { return e.first; }\n    T\
    \ w(EdgeType e) { return e.second; }\n    int i(EdgeType e) { throw domain_error(\"\
    no information on edge indices\"); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e)}; }\n};\nstruct IndexedEdge {\n    using EdgeType = pair<int,\
    \ int>;\n    int v(EdgeType e) { return e.first; }\n    int w(EdgeType e) { return\
    \ 1; }\n    int i(EdgeType e) { return e.second; }\n    EdgeType swapNode(EdgeType\
    \ e, int v) { return {v, i(e)}; }\n};\ntemplate <typename T> struct WeightedIndexedEdge\
    \ {\n    using EdgeType = tuple<int, T, int>; using WeightType = T;\n    int v(EdgeType\
    \ e) { return get<0>(e); }\n    T w(EdgeType e) { return get<1>(e); }\n    int\
    \ i(EdgeType e) { return get<2>(e); }\n    EdgeType swapNode(EdgeType e, int v)\
    \ { return {v, w(e), i(e)}; }\n};\n#line 3 \"tree/lca_sparse_table.hpp\"\n\n//\
    \ Due to some limitations with the current format of the templates, I cannot use\
    \ the sparse_table.hpp template here\ntemplate <typename GraphType, typename EdgeType>\
    \ struct LCASparseTable {\n    EdgeType E;\n    vector<int> dep, tour, fst;\n\
    \    vector<vector<int>> tb;\n    int N, lg;\n    int minByDep(int a, int b) {\
    \ return dep[a] < dep[b] ? a : b; }\n    void init(int N, GraphType &g, int rt)\
    \ {\n        dep.assign(N+1, 0); fst.assign(N+1, 0); tour.clear();\n        function<void(int,\
    \ int)> dfs = [&] (int c, int p) {\n            tour.push_back(c);\n         \
    \   fst[c] = tour.size();\n            for (auto to : g[c]) {\n              \
    \  int v = E.v(to);\n                if (v != p) {\n                    dep[v]\
    \ = dep[c] + 1;\n                    dfs(v, c);\n                    tour.push_back(c);\n\
    \                }\n            }\n        };\n        dfs(rt, -1);\n\n      \
    \  N = tour.size(); lg = __lg(N);\n        tb.assign(lg+1, vector<int>(N+1));\n\
    \        copy(tour.begin(), tour.end(), tb[0].begin()+1);\n        for (auto i\
    \ = 1; i <= lg; i++) {\n            int jmp = 1 << (i-1), end = N - (1<<i) + 1;\n\
    \            for (auto j = 1; j <= end; j++)\n                tb[i][j] = minByDep(tb[i-1][j],\
    \ tb[i-1][j+jmp]);\n        }\n    }\n    int lca(int a, int b) {\n        a =\
    \ fst[a]; b = fst[b];\n        if (a > b) swap(a, b);\n        int bit = __lg(b-a+1);\n\
    \        return minByDep(tb[bit][a], tb[bit][b-(1<<bit)+1]);\n    }\n};\n#line\
    \ 6 \"tests/tree/lca_sparse_table.test.cpp\"\n\nconst int MN = 5e5 + 1;\nvector<int>\
    \ g[MN];\n\nint main() {\n    fast_io();\n    int N = readi(), Q = readi();\n\n\
    \    // Randomizer to make sure code does not fail on trees where par_i < i does\
    \ not always hold\n    mt19937 mt(26022021);\n    vector<int> P(N+1), iP(N+1);\
    \ iota(P.begin()+1, P.end(), 1);\n    shuffle(P.begin()+1, P.end(), mt);\n   \
    \ for (int i = 1; i <= N; i++)\n        iP[P[i]] = i;\n\n    for (int i = 2; i\
    \ <= N; i++) {\n        int p = readi()+1, a = P[i], b = P[p];\n        g[a].push_back(b);\n\
    \        g[b].push_back(a);\n    }\n\n    LCASparseTable<vector<int>[MN], Edge>\
    \ lca; lca.init(N, g, P[1]);\n\n    while (Q--) {\n        int u = P[readi()+1];\n\
    \        int v = P[readi()+1];\n        print(iP[lca.lca(u, v)]-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../template.hpp\"\
    \n#include \"../test_utils.hpp\"\n#include \"../../graph/edge_types.hpp\"\n#include\
    \ \"../../tree/lca_sparse_table.hpp\"\n\nconst int MN = 5e5 + 1;\nvector<int>\
    \ g[MN];\n\nint main() {\n    fast_io();\n    int N = readi(), Q = readi();\n\n\
    \    // Randomizer to make sure code does not fail on trees where par_i < i does\
    \ not always hold\n    mt19937 mt(26022021);\n    vector<int> P(N+1), iP(N+1);\
    \ iota(P.begin()+1, P.end(), 1);\n    shuffle(P.begin()+1, P.end(), mt);\n   \
    \ for (int i = 1; i <= N; i++)\n        iP[P[i]] = i;\n\n    for (int i = 2; i\
    \ <= N; i++) {\n        int p = readi()+1, a = P[i], b = P[p];\n        g[a].push_back(b);\n\
    \        g[b].push_back(a);\n    }\n\n    LCASparseTable<vector<int>[MN], Edge>\
    \ lca; lca.init(N, g, P[1]);\n\n    while (Q--) {\n        int u = P[readi()+1];\n\
    \        int v = P[readi()+1];\n        print(iP[lca.lca(u, v)]-1);\n    }\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - graph/edge_types.hpp
  - tree/lca_sparse_table.hpp
  isVerificationFile: true
  path: tests/tree/lca_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tree/lca_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/tests/tree/lca_sparse_table.test.cpp
- /verify/tests/tree/lca_sparse_table.test.cpp.html
title: tests/tree/lca_sparse_table.test.cpp
---
