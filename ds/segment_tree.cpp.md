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
  bundledCode: "#line 1 \"ds/segment_tree.cpp\"\n// Template is 1-indexed\n// RMQ\
    \ + Set query\nstruct Comp {\n    using Data = int;\n    using Update = int;\n\
    \    const Data vdef = INF;\n    Data merge(Data l, Data r) { return min(l, r);\
    \ }\n    void applyUpdate(Data &l, Update &r) { l = r; }\n};\n#define MID int\
    \ mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;\ntemplate <class\
    \ Comp> struct SegmentTree {\n    using Data = typename Comp::Data; using Update\
    \ = typename Comp::Update; Comp C;\n    int N;\n    vector<Data> seg;\n    void\
    \ init(int n0) {\n        N = n0;\n        seg.assign(2 * N + 2, C.vdef);\n  \
    \  }\n    Data _query(int ql, int qr, int i, int l, int r) {\n        if (ql >\
    \ r || qr < l) return C.vdef;\n        if (l >= ql && r <= qr) return seg[i];\n\
    \        MID;\n        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql,\
    \ qr, rhs, mid + 1, r));\n    }\n    Data _update(int q, Update v, int i, int\
    \ l, int r) {\n        if (q > r || q < l) return seg[i];\n        if (l == q\
    \ && r == q) {\n            C.applyUpdate(seg[i], v);\n            return seg[i];\n\
    \        }\n        MID;\n        return seg[i] = C.merge(_update(q, v, lhs, l,\
    \ mid), _update(q, v, rhs, mid + 1, r));\n    }\n    Data query(int ql, int qr)\
    \ { return _query(ql, qr, 1, 1, N); }\n    void update(int q, Update v) { _update(q,\
    \ v, 1, 1, N); }\n};\n"
  code: "// Template is 1-indexed\n// RMQ + Set query\nstruct Comp {\n    using Data\
    \ = int;\n    using Update = int;\n    const Data vdef = INF;\n    Data merge(Data\
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
  dependsOn: []
  isVerificationFile: false
  path: ds/segment_tree.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment_tree.cpp
layout: document
redirect_from:
- /library/ds/segment_tree.cpp
- /library/ds/segment_tree.cpp.html
title: ds/segment_tree.cpp
---
