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
  bundledCode: "#line 1 \"math/old_mod.cpp\"\nconst ll MOD = 1e9 + 7;\nll madd(ll\
    \ a, ll b, ll mod = MOD) { return (a + b) % mod; }\nll msub(ll a, ll b, ll mod\
    \ = MOD) { return (a - b + mod) % mod; }\nll mmul(ll a, ll b, ll mod = MOD) {\
    \ return (a * b) % mod; }\nll fpow(ll x, ll y, ll mod = MOD) {\n    if (!y) return\
    \ 1LL;\n    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL,\
    \ mod);\n}\nll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2,\
    \ mod), mod); }\n\n"
  code: "const ll MOD = 1e9 + 7;\nll madd(ll a, ll b, ll mod = MOD) { return (a +\
    \ b) % mod; }\nll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod;\
    \ }\nll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }\nll fpow(ll x,\
    \ ll y, ll mod = MOD) {\n    if (!y) return 1LL;\n    return mmul(fpow(mmul(x,\
    \ x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);\n}\nll mdiv(ll x, ll y, ll mod\
    \ = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/old_mod.cpp
  requiredBy: []
  timestamp: '2021-06-27 02:07:30-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/old_mod.cpp
layout: document
redirect_from:
- /library/math/old_mod.cpp
- /library/math/old_mod.cpp.html
title: math/old_mod.cpp
---
