---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree_lazy.test.cpp
    title: tests/ds/segment_tree_lazy.test.cpp
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"ds/segment_tree_lazy.hpp\"\
    \n\n// Example comparator: Range min + Range increment\n// In the functions mergeLazy\
    \ and applyLazy, objects are merged from `v` to `to`.  In the function merge,\
    \ data is merged from left to right\nstruct Comp {\n    using Data = int;\n  \
    \  using Lazy = int;\n    const Data vdef = INF;\n    const Lazy ldef = 0;\n \
    \   Data merge(Data l, Data r) const { return min(l, r); }\n    Lazy mergeLazy(Lazy\
    \ to, Lazy v) const { return to + v; }\n    void applyLazy(Data &to, Lazy &v,\
    \ int l, int r) { to += v; }\n};\n#define MID int mid = (l + r) / 2, lhs = i +\
    \ 1, rhs = i + (mid - l + 1) * 2;\ntemplate <class Comp> struct LazySegmentTree\
    \ {\n    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp\
    \ C;\n    int N;\n    vector<Data> seg; vector<Lazy> lazy;\n    void init(int\
    \ n0) {\n        N = n0;\n        seg.assign(2 * N + 2, C.vdef);\n        lazy.assign(2\
    \ * N + 2, C.ldef);\n    }\n    void push(int i, int l, int r) {\n        if (lazy[i]\
    \ != C.ldef) {\n            MID;\n            C.applyLazy(seg[i], lazy[i], l,\
    \ r);\n            if (l != r) {\n                lazy[lhs] = C.mergeLazy(lazy[lhs],\
    \ lazy[i]);\n                lazy[rhs] = C.mergeLazy(lazy[rhs], lazy[i]);\n  \
    \          }\n            lazy[i] = C.ldef;\n        }\n    }\n    Data _query(int\
    \ ql, int qr, int i, int l, int r) {\n        if (ql > r || qr < l) return C.vdef;\n\
    \        push(i, l, r);\n        if (l >= ql && r <= qr) return seg[i];\n    \
    \    MID;\n        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr,\
    \ rhs, mid + 1, r));\n    }\n    Data _update(int ql, int qr, Lazy v, int i, int\
    \ l, int r) {\n        push(i, l, r);\n        if (ql > r || qr < l) return seg[i];\n\
    \        if (l >= ql && r <= qr) {\n            lazy[i] = v;\n            push(i,\
    \ l, r);\n            return seg[i];\n        }\n        MID;\n        return\
    \ seg[i] = C.merge(_update(ql, qr, v, lhs, l, mid), _update(ql, qr, v, rhs, mid\
    \ + 1, r));\n    }\n    Data _setPoint(int q, Data v, int i, int l, int r) {\n\
    \        push(i, l, r);\n        if (q > r || q < l) return seg[i];\n        if\
    \ (l >= q && r <= q) return seg[i] = v;\n        MID;\n        return seg[i] =\
    \ C.merge(_setPoint(q, v, lhs, l, mid), _setPoint(q, v, rhs, mid + 1, r));\n \
    \   }\n    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }\n  \
    \  void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }\n    void\
    \ setPoint(int q, Data v) { _setPoint(q, v, 1, 1, N); }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Example comparator: Range\
    \ min + Range increment\n// In the functions mergeLazy and applyLazy, objects\
    \ are merged from `v` to `to`.  In the function merge, data is merged from left\
    \ to right\nstruct Comp {\n    using Data = int;\n    using Lazy = int;\n    const\
    \ Data vdef = INF;\n    const Lazy ldef = 0;\n    Data merge(Data l, Data r) const\
    \ { return min(l, r); }\n    Lazy mergeLazy(Lazy to, Lazy v) const { return to\
    \ + v; }\n    void applyLazy(Data &to, Lazy &v, int l, int r) { to += v; }\n};\n\
    #define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;\n\
    template <class Comp> struct LazySegmentTree {\n    using Data = typename Comp::Data;\
    \ using Lazy = typename Comp::Lazy; Comp C;\n    int N;\n    vector<Data> seg;\
    \ vector<Lazy> lazy;\n    void init(int n0) {\n        N = n0;\n        seg.assign(2\
    \ * N + 2, C.vdef);\n        lazy.assign(2 * N + 2, C.ldef);\n    }\n    void\
    \ push(int i, int l, int r) {\n        if (lazy[i] != C.ldef) {\n            MID;\n\
    \            C.applyLazy(seg[i], lazy[i], l, r);\n            if (l != r) {\n\
    \                lazy[lhs] = C.mergeLazy(lazy[lhs], lazy[i]);\n              \
    \  lazy[rhs] = C.mergeLazy(lazy[rhs], lazy[i]);\n            }\n            lazy[i]\
    \ = C.ldef;\n        }\n    }\n    Data _query(int ql, int qr, int i, int l, int\
    \ r) {\n        if (ql > r || qr < l) return C.vdef;\n        push(i, l, r);\n\
    \        if (l >= ql && r <= qr) return seg[i];\n        MID;\n        return\
    \ C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));\n   \
    \ }\n    Data _update(int ql, int qr, Lazy v, int i, int l, int r) {\n       \
    \ push(i, l, r);\n        if (ql > r || qr < l) return seg[i];\n        if (l\
    \ >= ql && r <= qr) {\n            lazy[i] = v;\n            push(i, l, r);\n\
    \            return seg[i];\n        }\n        MID;\n        return seg[i] =\
    \ C.merge(_update(ql, qr, v, lhs, l, mid), _update(ql, qr, v, rhs, mid + 1, r));\n\
    \    }\n    Data _setPoint(int q, Data v, int i, int l, int r) {\n        push(i,\
    \ l, r);\n        if (q > r || q < l) return seg[i];\n        if (l >= q && r\
    \ <= q) return seg[i] = v;\n        MID;\n        return seg[i] = C.merge(_setPoint(q,\
    \ v, lhs, l, mid), _setPoint(q, v, rhs, mid + 1, r));\n    }\n    Data query(int\
    \ ql, int qr) { return _query(ql, qr, 1, 1, N); }\n    void update(int ql, int\
    \ qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }\n    void setPoint(int q, Data\
    \ v) { _setPoint(q, v, 1, 1, N); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/segment_tree_lazy.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ds/segment_tree_lazy.test.cpp
documentation_of: ds/segment_tree_lazy.hpp
layout: document
redirect_from:
- /library/ds/segment_tree_lazy.hpp
- /library/ds/segment_tree_lazy.hpp.html
title: ds/segment_tree_lazy.hpp
---
