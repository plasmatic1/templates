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
  bundledCode: "#line 1 \"math/choose.cpp\"\n// N choose R\nvector<ll> fact, invf;\n\
    void init_nchooser(int MN) {\n    fact.resize(MN + 1); invf.resize(MN + 1);\n\
    \    fact[0] = 1LL;\n    for (int i = 1; i <= MN; i++) fact[i] = fix(fact[i -\
    \ 1] * i);\n    invf[MN] = inv(fact[MN]);\n    for (auto i = MN-1; i >= 0; i--)\
    \ invf[i] = fix(invf[i + 1] * (i + 1));\n}\nll choose(ll N, ll K) { return fix(fact[N]\
    \ * fix(invf[K] * invf[N - K])); }\nll permute(ll N, ll K) { return fix(fact[N]\
    \ * invf[N - K]); }\n"
  code: "// N choose R\nvector<ll> fact, invf;\nvoid init_nchooser(int MN) {\n   \
    \ fact.resize(MN + 1); invf.resize(MN + 1);\n    fact[0] = 1LL;\n    for (int\
    \ i = 1; i <= MN; i++) fact[i] = fix(fact[i - 1] * i);\n    invf[MN] = inv(fact[MN]);\n\
    \    for (auto i = MN-1; i >= 0; i--) invf[i] = fix(invf[i + 1] * (i + 1));\n\
    }\nll choose(ll N, ll K) { return fix(fact[N] * fix(invf[K] * invf[N - K])); }\n\
    ll permute(ll N, ll K) { return fix(fact[N] * invf[N - K]); }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/choose.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/choose.cpp
layout: document
redirect_from:
- /library/math/choose.cpp
- /library/math/choose.cpp.html
title: math/choose.cpp
---
