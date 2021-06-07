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
  bundledCode: "#line 1 \"math/matrix.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nusing VecType = ll;\nconstexpr ll MOD = 1e9 +\
    \ 7;\nconstexpr bool USE_MOD = true;\n\nusing Vec = vector<VecType>; using Mat\
    \ = vector<Vec>;\nvoid init(Mat &m, int N) {\n    m.resize(N);\n    for (int i\
    \ = 0; i < N; i++) m[i].assign(N, 0);\n}\nvoid init(Vec &v, int N) { v.assign(N,\
    \ 0); }\nvoid init_identity(Mat &m, int N) {\n    init(m, N);\n    for (int i\
    \ = 0; i < N; i++) m[i][i] = 1;\n}\nvoid mul(Mat &res, const Mat &a, const Mat\
    \ &b) {\n    int N = a.size();\n    init(res, N);\n    for (int i = 0; i < N;\
    \ i++) {\n        for (int j = 0; j < N; j++) {\n            for (int k = 0; k\
    \ < N; k++) {\n                res[i][j] += a[i][k] * b[k][j]; if (USE_MOD) {\
    \ res[i][j] %= MOD; } } } }\n}\nvoid mul(Vec &res, const Mat &m, const Vec &v)\
    \ {\n    int N = m.size();\n    init(res, N);\n    for (int i = 0; i < N; i++)\
    \ {\n        for (int j = 0; j < N; j++) {\n            res[i] += m[i][j] * v[j];\
    \ if (USE_MOD) { res[i] %= MOD; } } }\n}\nMat mul(const Mat &a, const Mat &b)\
    \ { Mat ret; mul(ret, a, b); return ret; }\nVec mul(const Mat &m, const Vec &v)\
    \ { Vec ret; mul(ret, m, v); return ret; }\nvoid exp(Mat &res, ll exp) {\n   \
    \ int N = res.size();\n    Mat cpow = res; init_identity(res, N);\n    for (ll\
    \ cxp = 0; exp >> cxp; cxp++) {\n        if ((exp >> cxp) & 1)\n            res\
    \ = mul(res, cpow);\n        cpow = mul(cpow, cpow);\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using VecType = ll;\nconstexpr ll MOD = 1e9 + 7;\nconstexpr bool USE_MOD = true;\n\
    \nusing Vec = vector<VecType>; using Mat = vector<Vec>;\nvoid init(Mat &m, int\
    \ N) {\n    m.resize(N);\n    for (int i = 0; i < N; i++) m[i].assign(N, 0);\n\
    }\nvoid init(Vec &v, int N) { v.assign(N, 0); }\nvoid init_identity(Mat &m, int\
    \ N) {\n    init(m, N);\n    for (int i = 0; i < N; i++) m[i][i] = 1;\n}\nvoid\
    \ mul(Mat &res, const Mat &a, const Mat &b) {\n    int N = a.size();\n    init(res,\
    \ N);\n    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++)\
    \ {\n            for (int k = 0; k < N; k++) {\n                res[i][j] += a[i][k]\
    \ * b[k][j]; if (USE_MOD) { res[i][j] %= MOD; } } } }\n}\nvoid mul(Vec &res, const\
    \ Mat &m, const Vec &v) {\n    int N = m.size();\n    init(res, N);\n    for (int\
    \ i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n            res[i]\
    \ += m[i][j] * v[j]; if (USE_MOD) { res[i] %= MOD; } } }\n}\nMat mul(const Mat\
    \ &a, const Mat &b) { Mat ret; mul(ret, a, b); return ret; }\nVec mul(const Mat\
    \ &m, const Vec &v) { Vec ret; mul(ret, m, v); return ret; }\nvoid exp(Mat &res,\
    \ ll exp) {\n    int N = res.size();\n    Mat cpow = res; init_identity(res, N);\n\
    \    for (ll cxp = 0; exp >> cxp; cxp++) {\n        if ((exp >> cxp) & 1)\n  \
    \          res = mul(res, cpow);\n        cpow = mul(cpow, cpow);\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: math/matrix.cpp
---
