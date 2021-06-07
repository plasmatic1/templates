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
  bundledCode: "#line 1 \"external/extgcd.cpp\"\nll gcd(ll a, ll b, ll& x, ll& y)\
    \ {\n    x = 1, y = 0;\n    ll x1 = 0, y1 = 1, a1 = a, b1 = b;\n    while (b1)\
    \ {\n        ll q = a1 / b1;\n        tie(x, x1) = make_tuple(x1, x - q * x1);\n\
    \        tie(y, y1) = make_tuple(y1, y - q * y1);\n        tie(a1, b1) = make_tuple(b1,\
    \ a1 - q * b1);\n    }\n    return a1;\n}\n\n"
  code: "ll gcd(ll a, ll b, ll& x, ll& y) {\n    x = 1, y = 0;\n    ll x1 = 0, y1\
    \ = 1, a1 = a, b1 = b;\n    while (b1) {\n        ll q = a1 / b1;\n        tie(x,\
    \ x1) = make_tuple(x1, x - q * x1);\n        tie(y, y1) = make_tuple(y1, y - q\
    \ * y1);\n        tie(a1, b1) = make_tuple(b1, a1 - q * b1);\n    }\n    return\
    \ a1;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: external/extgcd.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/extgcd.cpp
layout: document
redirect_from:
- /library/external/extgcd.cpp
- /library/external/extgcd.cpp.html
title: external/extgcd.cpp
---
