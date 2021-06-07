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
  bundledCode: "#line 1 \"math/mod.cpp\"\nconst ll MOD = 1e9 + 7;\nll fix(ll &&x)\
    \ { x %= MOD; if (x < 0) x += MOD; return x; }\nll fix(ll &x) { x %= MOD; if (x\
    \ < 0) x += MOD; return x; }\nll fpow(ll x, ll y, ll mod = MOD) {\n    if (!y)\
    \ return 1LL;\n    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL)\
    \ % mod;\n}\nll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }\n"
  code: "const ll MOD = 1e9 + 7;\nll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD;\
    \ return x; }\nll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }\nll\
    \ fpow(ll x, ll y, ll mod = MOD) {\n    if (!y) return 1LL;\n    return fpow(x\
    \ * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;\n}\nll inv(ll x, ll mod\
    \ = MOD) { return fpow(x, mod - 2, mod); }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.cpp
layout: document
redirect_from:
- /library/math/mod.cpp
- /library/math/mod.cpp.html
title: math/mod.cpp
---
