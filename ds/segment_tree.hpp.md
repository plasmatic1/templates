---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/segment_tree.test.cpp
    title: tests/ds/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\ntemplate <typename\
    \ T> using opt_ref = optional<reference_wrapper<T>>; // for some templates\nusing\
    \ ll = long long; using ull = unsigned long long; using ld = long double;\nusing\
    \ pii = pair<int, int>; using pll = pair<long long, long long>;\n#ifdef __GNUG__\n\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"ds/segment_tree.hpp\"\
    \n\n// Template is 1-indexed\n// Default Comp: RMQ + Set query\n// Functions merge\
    \ and applyUpdate should be implemented left to right\nstruct Comp {\n    using\
    \ Data = int;\n    using Update = int;\n    const Data vdef = INF;\n    Data merge(Data\
    \ l, Data r) { return min(l, r); }\n    void applyUpdate(Data &l, Update &r) {\
    \ l = r; }\n};\n#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid\
    \ - l + 1) * 2;\ntemplate <class Comp> struct SegmentTree {\n    using Data =\
    \ typename Comp::Data; using Update = typename Comp::Update; Comp C;\n    int\
    \ N;\n    vector<Data> seg;\n    void init(int n0) {\n        N = n0;\n      \
    \  seg.assign(2 * N + 2, C.vdef);\n    }\n    Data _query(int ql, int qr, int\
    \ i, int l, int r) {\n        if (ql > r || qr < l) return C.vdef;\n        if\
    \ (l >= ql && r <= qr) return seg[i];\n        MID;\n        return C.merge(_query(ql,\
    \ qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));\n    }\n    Data _update(int\
    \ q, Update v, int i, int l, int r) {\n        if (q > r || q < l) return seg[i];\n\
    \        if (l == q && r == q) {\n            C.applyUpdate(seg[i], v);\n    \
    \        return seg[i];\n        }\n        MID;\n        return seg[i] = C.merge(_update(q,\
    \ v, lhs, l, mid), _update(q, v, rhs, mid + 1, r));\n    }\n    Data query(int\
    \ ql, int qr) { return _query(ql, qr, 1, 1, N); }\n    void update(int q, Update\
    \ v) { _update(q, v, 1, 1, N); }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Template is 1-indexed\n\
    // Default Comp: RMQ + Set query\n// Functions merge and applyUpdate should be\
    \ implemented left to right\nstruct Comp {\n    using Data = int;\n    using Update\
    \ = int;\n    const Data vdef = INF;\n    Data merge(Data l, Data r) { return\
    \ min(l, r); }\n    void applyUpdate(Data &l, Update &r) { l = r; }\n};\n#define\
    \ MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;\ntemplate\
    \ <class Comp> struct SegmentTree {\n    using Data = typename Comp::Data; using\
    \ Update = typename Comp::Update; Comp C;\n    int N;\n    vector<Data> seg;\n\
    \    void init(int n0) {\n        N = n0;\n        seg.assign(2 * N + 2, C.vdef);\n\
    \    }\n    Data _query(int ql, int qr, int i, int l, int r) {\n        if (ql\
    \ > r || qr < l) return C.vdef;\n        if (l >= ql && r <= qr) return seg[i];\n\
    \        MID;\n        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql,\
    \ qr, rhs, mid + 1, r));\n    }\n    Data _update(int q, Update v, int i, int\
    \ l, int r) {\n        if (q > r || q < l) return seg[i];\n        if (l == q\
    \ && r == q) {\n            C.applyUpdate(seg[i], v);\n            return seg[i];\n\
    \        }\n        MID;\n        return seg[i] = C.merge(_update(q, v, lhs, l,\
    \ mid), _update(q, v, rhs, mid + 1, r));\n    }\n    Data query(int ql, int qr)\
    \ { return _query(ql, qr, 1, 1, N); }\n    void update(int q, Update v) { _update(q,\
    \ v, 1, 1, N); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-06-14 21:42:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ds/segment_tree.test.cpp
documentation_of: ds/segment_tree.hpp
layout: document
redirect_from:
- /library/ds/segment_tree.hpp
- /library/ds/segment_tree.hpp.html
title: ds/segment_tree.hpp
---
