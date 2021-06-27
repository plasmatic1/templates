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
  bundledCode: "#line 1 \"math/old_choose.cpp\"\n// N choose R\nvector<ll> fact, invf;\n\
    void init_nchooser(int MN) {\n    fact.resize(MN + 1); invf.resize(MN + 1);\n\
    \    fact[0] = invf[0] = 1LL;\n    for (int i = 1; i <= MN; i++) {\n        fact[i]\
    \ = mmul(fact[i - 1], i);\n        invf[i] = mdiv(1, fact[i]);\n    }\n}\nll choose(ll\
    \ N, ll K) { return mmul(fact[N], mmul(invf[K], invf[N - K])); }\nll permute(ll\
    \ N, ll K) { return mmul(fact[N], invf[N - K]); }\n"
  code: "// N choose R\nvector<ll> fact, invf;\nvoid init_nchooser(int MN) {\n   \
    \ fact.resize(MN + 1); invf.resize(MN + 1);\n    fact[0] = invf[0] = 1LL;\n  \
    \  for (int i = 1; i <= MN; i++) {\n        fact[i] = mmul(fact[i - 1], i);\n\
    \        invf[i] = mdiv(1, fact[i]);\n    }\n}\nll choose(ll N, ll K) { return\
    \ mmul(fact[N], mmul(invf[K], invf[N - K])); }\nll permute(ll N, ll K) { return\
    \ mmul(fact[N], invf[N - K]); }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/old_choose.cpp
  requiredBy: []
  timestamp: '2021-06-27 02:07:30-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/old_choose.cpp
layout: document
redirect_from:
- /library/math/old_choose.cpp
- /library/math/old_choose.cpp.html
title: math/old_choose.cpp
---
