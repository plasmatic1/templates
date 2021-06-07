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
  bundledCode: "#line 1 \"ds/sparse_table.cpp\"\n// Comparator for range MAX q\n//\
    \ Sparse table is 1-indexed\nstruct Comp {\n    using Data = int;\n    Data merge(Data\
    \ a, Data b) { return max(a, b); }\n};\ntemplate <class Comp> struct SparseTable\
    \ {\n    using Data = typename Comp::Data; Comp C;\n    vector<vector<Data>> tb;\n\
    \    int N, lg;\n    template <typename It> void init(It st, It end) {\n     \
    \   N = end-st; lg = __lg(N);\n        tb.assign(lg+1, vector<Data>(N+1));\n \
    \       copy(st, end, tb[0].begin()+1);\n        for (auto i = 1; i <= lg; i++)\
    \ {\n            int jmp = 1 << (i-1), end = N - (1<<i) + 1;\n            for\
    \ (auto j = 1; j <= end; j++)\n                tb[i][j] = C.merge(tb[i-1][j],\
    \ tb[i-1][j+jmp]);\n        }\n    }\n    Data query(int l, int r) {\n       \
    \ int bit = __lg(r-l+1);\n        return C.merge(tb[bit][l], tb[bit][r-(1<<bit)+1]);\n\
    \    }\n};\n\n"
  code: "// Comparator for range MAX q\n// Sparse table is 1-indexed\nstruct Comp\
    \ {\n    using Data = int;\n    Data merge(Data a, Data b) { return max(a, b);\
    \ }\n};\ntemplate <class Comp> struct SparseTable {\n    using Data = typename\
    \ Comp::Data; Comp C;\n    vector<vector<Data>> tb;\n    int N, lg;\n    template\
    \ <typename It> void init(It st, It end) {\n        N = end-st; lg = __lg(N);\n\
    \        tb.assign(lg+1, vector<Data>(N+1));\n        copy(st, end, tb[0].begin()+1);\n\
    \        for (auto i = 1; i <= lg; i++) {\n            int jmp = 1 << (i-1), end\
    \ = N - (1<<i) + 1;\n            for (auto j = 1; j <= end; j++)\n           \
    \     tb[i][j] = C.merge(tb[i-1][j], tb[i-1][j+jmp]);\n        }\n    }\n    Data\
    \ query(int l, int r) {\n        int bit = __lg(r-l+1);\n        return C.merge(tb[bit][l],\
    \ tb[bit][r-(1<<bit)+1]);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sparse_table.cpp
layout: document
redirect_from:
- /library/ds/sparse_table.cpp
- /library/ds/sparse_table.cpp.html
title: ds/sparse_table.cpp
---
