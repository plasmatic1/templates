---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge_types.hpp
    title: graph/edge_types.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  - icon: ':x:'
    path: tree/hld.hpp
    title: tree/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/tree/hld_lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\n#define DEBUG 1\nusing namespace\
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
    \ { return {v, w(e), i(e)}; }\n};\n#line 1 \"tree/hld.hpp\"\ntemplate <typename\
    \ GraphType, typename EdgeType> struct HLD {\n    EdgeType E;\n    int cpos;\n\
    \    vector<int> par, dep, head, heavy, pos;\n    void init(int N, GraphType &g,\
    \ int rt) {\n        cpos = 0;\n        par.assign(N + 1, 0); dep.assign(N + 1,\
    \ 0); head.assign(N + 1, 0); heavy.assign(N + 1, -1); pos.assign(N + 1, 0);\n\
    \        function<int(int, int)> dfs = [&] (int c, int p) {\n            par[c]\
    \ = p;\n            int sz = 1, mxsz = 0;\n            for (auto to : g[c]) {\n\
    \                int v = E.v(to);\n                if (v != p) {\n           \
    \         dep[v] = dep[c] + 1;\n                    int csz = dfs(v, c); sz +=\
    \ csz;\n                    if (csz > mxsz) heavy[c] = v, mxsz = csz;\n      \
    \          }\n            }\n            return sz;\n        };\n        function<void(int,\
    \ int)> build = [&] (int c, int chead) {\n            pos[c] = ++cpos; head[c]\
    \ = chead;\n            if (heavy[c] != -1) build(heavy[c], chead);\n        \
    \    for (auto to : g[c]) {\n                int v = E.v(to);\n              \
    \  if (v != par[c] && v != heavy[c])\n                    build(v, v);\n     \
    \       }\n        };\n        dfs(rt, -1);\n        build(rt, rt);\n    }\n \
    \   int lca(int a, int b) {\n        while (head[a] != head[b]) {\n          \
    \  if (dep[head[a]] > dep[head[b]]) swap(a, b);\n            b = par[head[b]];\n\
    \        }\n        return dep[a] < dep[b] ? a : b;\n    }\n\n#if __cplusplus\
    \ == 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>> par0, opt_ref<vector<int>>\
    \ dep0, opt_ref<vector<int>> head0, opt_ref<vector<int>> heavy0, opt_ref<vector<int>>\
    \ pos0) {\n        if (par0) par.swap(*par0);\n        if (dep0) dep.swap(*dep0);\n\
    \        if (head0) head.swap(*head0);\n        if (heavy0) heavy.swap(*heavy0);\n\
    \        if (pos0) pos.swap(*pos0);\n    }\n#endif\n};\n#line 6 \"tests/tree/hld_lca.test.cpp\"\
    \n\nconst int MN = 5e5 + 1;\nvector<int> g[MN];\n\nint main() {\n    fast_io();\n\
    \    int N = readi(), Q = readi();\n\n    // Randomizer to make sure code does\
    \ not fail on trees where par_i < i does not always hold\n    mt19937 mt(26022021);\n\
    \    vector<int> P(N+1), iP(N+1); iota(P.begin()+1, P.end(), 1);\n    shuffle(P.begin()+1,\
    \ P.end(), mt);\n    for (int i = 1; i <= N; i++)\n        iP[P[i]] = i;\n\n \
    \   for (int i = 2; i <= N; i++) {\n        int p = readi()+1, a = P[i], b = P[p];\n\
    \        g[a].push_back(b);\n        g[b].push_back(a);\n    }\n\n    HLD<vector<int>[MN],\
    \ Edge> lca; lca.init(N, g, P[1]);\n\n    while (Q--) {\n        int u = P[readi()+1];\n\
    \        int v = P[readi()+1];\n        print(iP[lca.lca(u, v)]-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../template.hpp\"\
    \n#include \"../test_utils.hpp\"\n#include \"../../graph/edge_types.hpp\"\n#include\
    \ \"../../tree/hld.hpp\"\n\nconst int MN = 5e5 + 1;\nvector<int> g[MN];\n\nint\
    \ main() {\n    fast_io();\n    int N = readi(), Q = readi();\n\n    // Randomizer\
    \ to make sure code does not fail on trees where par_i < i does not always hold\n\
    \    mt19937 mt(26022021);\n    vector<int> P(N+1), iP(N+1); iota(P.begin()+1,\
    \ P.end(), 1);\n    shuffle(P.begin()+1, P.end(), mt);\n    for (int i = 1; i\
    \ <= N; i++)\n        iP[P[i]] = i;\n\n    for (int i = 2; i <= N; i++) {\n  \
    \      int p = readi()+1, a = P[i], b = P[p];\n        g[a].push_back(b);\n  \
    \      g[b].push_back(a);\n    }\n\n    HLD<vector<int>[MN], Edge> lca; lca.init(N,\
    \ g, P[1]);\n\n    while (Q--) {\n        int u = P[readi()+1];\n        int v\
    \ = P[readi()+1];\n        print(iP[lca.lca(u, v)]-1);\n    }\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - graph/edge_types.hpp
  - tree/hld.hpp
  isVerificationFile: true
  path: tests/tree/hld_lca.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/tree/hld_lca.test.cpp
layout: document
redirect_from:
- /verify/tests/tree/hld_lca.test.cpp
- /verify/tests/tree/hld_lca.test.cpp.html
title: tests/tree/hld_lca.test.cpp
---
