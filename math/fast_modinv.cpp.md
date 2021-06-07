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
  bundledCode: "#line 1 \"math/fast_modinv.cpp\"\n// fast modular inverse (with O(N)\
    \ precalc), 9 lines\nconst int MN = 1001;\nll inv[MN];\nvoid init_modinv(ll mod)\
    \ {\n    inv[1] = 1LL;\n    for (int i = 2; i < MN; i++)\n        inv[i] = (mod\
    \ - ((mod / i) * inv[mod % i]) % mod) % mod;\n}\nll mdiv(ll x, ll y) { return\
    \ (x * inv[y]) % MOD; }\n"
  code: "// fast modular inverse (with O(N) precalc), 9 lines\nconst int MN = 1001;\n\
    ll inv[MN];\nvoid init_modinv(ll mod) {\n    inv[1] = 1LL;\n    for (int i = 2;\
    \ i < MN; i++)\n        inv[i] = (mod - ((mod / i) * inv[mod % i]) % mod) % mod;\n\
    }\nll mdiv(ll x, ll y) { return (x * inv[y]) % MOD; }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fast_modinv.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast_modinv.cpp
layout: document
redirect_from:
- /library/math/fast_modinv.cpp
- /library/math/fast_modinv.cpp.html
title: math/fast_modinv.cpp
---
