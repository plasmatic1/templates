---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/lazy_segment_tree.cpp\"\n\n// Thanks wesley thanks wesley\
    \ thanks wesley\n// RMQ + Increment query\nstruct Comp {\n    using Data = int;\n\
    \    using Lazy = int;\n    const Data vdef = INF;\n    const Lazy ldef = 0;\n\
    \    Data merge(Data l, Data r) const { return min(l, r); }\n    Lazy mergeLazy(Lazy\
    \ l, Lazy r) const { return l + r; }\n    void applyLazy(Data &to, Lazy &v, int\
    \ l, int r) { to += v; }\n};\n#define MID int mid = (l + r) / 2, lhs = i + 1,\
    \ rhs = i + (mid - l + 1) * 2;\ntemplate <class Comp> struct LazySegmentTree {\n\
    \    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp\
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
    \ + 1, r));\n    }\n    Data query(int ql, int qr) { return _query(ql, qr, 1,\
    \ 1, N); }\n    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1,\
    \ N); }\n};\n"
  code: "\n// Thanks wesley thanks wesley thanks wesley\n// RMQ + Increment query\n\
    struct Comp {\n    using Data = int;\n    using Lazy = int;\n    const Data vdef\
    \ = INF;\n    const Lazy ldef = 0;\n    Data merge(Data l, Data r) const { return\
    \ min(l, r); }\n    Lazy mergeLazy(Lazy l, Lazy r) const { return l + r; }\n \
    \   void applyLazy(Data &to, Lazy &v, int l, int r) { to += v; }\n};\n#define\
    \ MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;\ntemplate\
    \ <class Comp> struct LazySegmentTree {\n    using Data = typename Comp::Data;\
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
    \    }\n    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }\n \
    \   void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-06-07 01:26:18-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/ds/lazy_segment_tree.cpp
- /library/ds/lazy_segment_tree.cpp.html
title: ds/lazy_segment_tree.cpp
---
