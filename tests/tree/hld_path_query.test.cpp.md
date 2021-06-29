---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/bit.hpp
    title: ds/bit.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge_types.hpp
    title: graph/edge_types.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  - icon: ':heavy_check_mark:'
    path: tree/hld.hpp
    title: tree/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"tests/tree/hld_path_query.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line 2 \"template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n// Defines\n#define fs first\n\
    #define sn second\n#define pb push_back\n#define eb emplace_back\n#define mpr\
    \ make_pair\n#define mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n//\
    \ Basic type definitions\n#if __cplusplus == 201703L // CPP17 only things\ntemplate\
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
    \        if (pos0) pos.swap(*pos0);\n    }\n#endif\n};\n#line 3 \"ds/bit.hpp\"\
    \n\n// Template is 1-indexed (by default).  Can be made 0-indexed by modifying\
    \ Comp\n// Example: update = point increment, range sum\n// In the function applyUpdate,\
    \ updates are applied from `v` to `to`\nstruct Comp {\n    using Data = int;\n\
    \    const Data vdef = 0;\n    void applyUpdate(Data &to, Data &v) { to += v;\
    \ }\n    int transformInd(int idx, int N) { return idx; }\n};\ntemplate <typename\
    \ Comp> struct BIT {\n    using Data = typename Comp::Data; Comp C;\n    int N;\
    \ vector<Data> bit;\n    void init(int n0) {\n        N = n0;\n        bit.assign(N\
    \ + 1, C.vdef);\n    }\n    void update(int x, Data v) {\n        x = C.transformInd(x,\
    \ N);\n        for (; x <= N; x += x & -x)\n            C.applyUpdate(bit[x],\
    \ v);\n    }\n    Data query(int x) {\n        x = C.transformInd(x, N);\n   \
    \     Data res = C.vdef;\n        for (; x; x -= x & -x)\n            C.applyUpdate(res,\
    \ bit[x]);\n        return res;\n    }\n};\n#line 7 \"tests/tree/hld_path_query.test.cpp\"\
    \n\nstruct CompLL {\n    using Data = ll;\n    const Data vdef = 0;\n    void\
    \ applyUpdate(Data &to, Data &v) { to += v; }\n    int transformInd(int idx, int\
    \ N) { return idx; }\n};\n\nconst int MN = 5e5 + 1;\nint N, Q;\nll A[MN];\nvector<int>\
    \ g[MN];\nHLD<vector<int>[MN], Edge> hld;\nBIT<CompLL> bit;\nvector<int> &par\
    \ = hld.par, &head = hld.head, &pos = hld.pos;\n\nll path(int u) {\n    ll res\
    \ = 0;\n    while (u != -1) {\n        res += bit.query(pos[u]) - bit.query(pos[head[u]]-1);\n\
    \        u = par[head[u]];\n    }\n    return res;\n}\n\nint main() {\n    fast_io();\n\
    \    N = readi();\n    Q = readi();\n    for (int i = 1; i <= N; i++) A[i] = readi();\n\
    \    for (int i = 1; i <= N-1; i++) {\n        int a = readi()+1;\n        int\
    \ b = readi()+1;\n        g[a].push_back(b);\n        g[b].push_back(a);\n   \
    \ }\n\n    hld.init(N, g, 1);\n    bit.init(N);\n    for (int i = 1; i <= N; i++)\n\
    \        bit.update(pos[i], A[i]);\n\n    while (Q--) {\n        int t = readi();\n\
    \        int a = readi()+1;\n        int b = readi() + (t == 1);\n        if (t\
    \ == 0) {\n            bit.update(pos[a], b);\n            A[a] += b;\n      \
    \  }\n        else {\n            int l = hld.lca(a, b);\n            ll res =\
    \ path(a) + path(b) - 2*path(l) + A[l];\n            print(res);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../graph/edge_types.hpp\"\
    \n#include \"../../tree/hld.hpp\"\n#include \"../../ds/bit.hpp\"\n\nstruct CompLL\
    \ {\n    using Data = ll;\n    const Data vdef = 0;\n    void applyUpdate(Data\
    \ &to, Data &v) { to += v; }\n    int transformInd(int idx, int N) { return idx;\
    \ }\n};\n\nconst int MN = 5e5 + 1;\nint N, Q;\nll A[MN];\nvector<int> g[MN];\n\
    HLD<vector<int>[MN], Edge> hld;\nBIT<CompLL> bit;\nvector<int> &par = hld.par,\
    \ &head = hld.head, &pos = hld.pos;\n\nll path(int u) {\n    ll res = 0;\n   \
    \ while (u != -1) {\n        res += bit.query(pos[u]) - bit.query(pos[head[u]]-1);\n\
    \        u = par[head[u]];\n    }\n    return res;\n}\n\nint main() {\n    fast_io();\n\
    \    N = readi();\n    Q = readi();\n    for (int i = 1; i <= N; i++) A[i] = readi();\n\
    \    for (int i = 1; i <= N-1; i++) {\n        int a = readi()+1;\n        int\
    \ b = readi()+1;\n        g[a].push_back(b);\n        g[b].push_back(a);\n   \
    \ }\n\n    hld.init(N, g, 1);\n    bit.init(N);\n    for (int i = 1; i <= N; i++)\n\
    \        bit.update(pos[i], A[i]);\n\n    while (Q--) {\n        int t = readi();\n\
    \        int a = readi()+1;\n        int b = readi() + (t == 1);\n        if (t\
    \ == 0) {\n            bit.update(pos[a], b);\n            A[a] += b;\n      \
    \  }\n        else {\n            int l = hld.lca(a, b);\n            ll res =\
    \ path(a) + path(b) - 2*path(l) + A[l];\n            print(res);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - graph/edge_types.hpp
  - tree/hld.hpp
  - ds/bit.hpp
  isVerificationFile: true
  path: tests/tree/hld_path_query.test.cpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tree/hld_path_query.test.cpp
layout: document
redirect_from:
- /verify/tests/tree/hld_path_query.test.cpp
- /verify/tests/tree/hld_path_query.test.cpp.html
title: tests/tree/hld_path_query.test.cpp
---
