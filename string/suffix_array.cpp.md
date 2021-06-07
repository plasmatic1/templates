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
  bundledCode: "#line 1 \"string/suffix_array.cpp\"\nstruct suf {\n    int idx, r1,\
    \ r2;\n    bool operator<(const suf &o) const {\n        return r1 == o.r1 ? r2\
    \ < o.r2 : r1 < o.r1;\n    }\n};\n\nconst int MN = 1e5 + 1;\nint N, M;\nstring\
    \ A, B;\n\n// SA\nsuf sa[MN];\nint crnk[MN];\nchar getc(int idx, int col) {\n\
    \    int cidx = sa[idx].idx + col;\n    if (cidx >= N) return '$';\n    return\
    \ A[cidx];\n}\n\nvoid build() {\n    for (auto i = 0; i < N; i++)\n        sa[i]\
    \ = {i, A[i] - 'a', i + 1 < N ? A[i + 1] - 'a' : -1};\n    sort(sa, sa + N);\n\
    \    for (int i = 2; i <= N; i *= 2) {\n        int ctr = 0;\n        suf pre{-1,\
    \ -INF, -INF};\n        for (auto j = 0; j < N; j++) {\n            if (sa[j].r1\
    \ != pre.r1 || sa[j].r2 != pre.r2) {\n                pre = sa[j];\n         \
    \       ctr++;\n            }\n            sa[j].r1 = ctr;\n            crnk[sa[j].idx]\
    \ = ctr;\n        }\n        for (auto j = 0; j < N; j++)\n            sa[j].r2\
    \ = sa[j].idx + i < N ? crnk[sa[j].idx + i] : -1;\n        sort(sa, sa + N);\n\
    \    }\n}\n"
  code: "struct suf {\n    int idx, r1, r2;\n    bool operator<(const suf &o) const\
    \ {\n        return r1 == o.r1 ? r2 < o.r2 : r1 < o.r1;\n    }\n};\n\nconst int\
    \ MN = 1e5 + 1;\nint N, M;\nstring A, B;\n\n// SA\nsuf sa[MN];\nint crnk[MN];\n\
    char getc(int idx, int col) {\n    int cidx = sa[idx].idx + col;\n    if (cidx\
    \ >= N) return '$';\n    return A[cidx];\n}\n\nvoid build() {\n    for (auto i\
    \ = 0; i < N; i++)\n        sa[i] = {i, A[i] - 'a', i + 1 < N ? A[i + 1] - 'a'\
    \ : -1};\n    sort(sa, sa + N);\n    for (int i = 2; i <= N; i *= 2) {\n     \
    \   int ctr = 0;\n        suf pre{-1, -INF, -INF};\n        for (auto j = 0; j\
    \ < N; j++) {\n            if (sa[j].r1 != pre.r1 || sa[j].r2 != pre.r2) {\n \
    \               pre = sa[j];\n                ctr++;\n            }\n        \
    \    sa[j].r1 = ctr;\n            crnk[sa[j].idx] = ctr;\n        }\n        for\
    \ (auto j = 0; j < N; j++)\n            sa[j].r2 = sa[j].idx + i < N ? crnk[sa[j].idx\
    \ + i] : -1;\n        sort(sa, sa + N);\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_array.cpp
layout: document
redirect_from:
- /library/string/suffix_array.cpp
- /library/string/suffix_array.cpp.html
title: string/suffix_array.cpp
---
