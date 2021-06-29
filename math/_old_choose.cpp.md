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
  bundledCode: "#line 1 \"math/_old_choose.cpp\"\n// N choose R\nvector<ll> fact,\
    \ invf;\nvoid init_nchooser(int MN) {\n    fact.resize(MN + 1); invf.resize(MN\
    \ + 1);\n    fact[0] = invf[0] = 1LL;\n    for (int i = 1; i <= MN; i++) {\n \
    \       fact[i] = mmul(fact[i - 1], i);\n        invf[i] = mdiv(1, fact[i]);\n\
    \    }\n}\nll choose(ll N, ll K) { return mmul(fact[N], mmul(invf[K], invf[N -\
    \ K])); }\nll permute(ll N, ll K) { return mmul(fact[N], invf[N - K]); }\n"
  code: "// N choose R\nvector<ll> fact, invf;\nvoid init_nchooser(int MN) {\n   \
    \ fact.resize(MN + 1); invf.resize(MN + 1);\n    fact[0] = invf[0] = 1LL;\n  \
    \  for (int i = 1; i <= MN; i++) {\n        fact[i] = mmul(fact[i - 1], i);\n\
    \        invf[i] = mdiv(1, fact[i]);\n    }\n}\nll choose(ll N, ll K) { return\
    \ mmul(fact[N], mmul(invf[K], invf[N - K])); }\nll permute(ll N, ll K) { return\
    \ mmul(fact[N], invf[N - K]); }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/_old_choose.cpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/_old_choose.cpp
layout: document
redirect_from:
- /library/math/_old_choose.cpp
- /library/math/_old_choose.cpp.html
title: math/_old_choose.cpp
---
