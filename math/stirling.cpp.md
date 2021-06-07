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
  bundledCode: "#line 1 \"math/stirling.cpp\"\n// Stirling Numbers (1st kind)\n//\
    \ Depends on mod template\n// Number of length N permutations with K disjoint\
    \ cycles\nvector<vector<ll>> dp;\nll stir1(ll N, ll K) {\n    dp.assign(N + 1,\
    \ vector<ll>(K + 1, -1));\n    return _stir1(N, K);\n}\nll _stir1(ll N, ll K)\
    \ {\n    if (!N && !K) return 1LL;\n    if (!N || !K) return 0LL;\n    ll &ret\
    \ = dp[N][K];\n    if (ret != -1) return ret;\n    return ret = madd(mmul(N -\
    \ 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));\n}\n\n// Stirling Numbers (2nd\
    \ kind)\n// Depends on mod and nchooser templates (and calling init_nchooser to\
    \ init factorial table)\n// Number of ways to partition N labelled objects into\
    \ K (NONEMPTY) unlabelled subsets (order of subsets does not matter)\n// If you\
    \ want to do it with labelled subsets, just remove the division at the end or\
    \ multiply by fact[K]\n// If empty subsets were allowed, the answer would just\
    \ be K^N\nll stir2(ll N, ll K) {\n    ll res = 0;\n    int coeff = 1;\n    for\
    \ (int i = 0; i <= K; i++) {\n        res = madd(res, mmul(coeff, mmul(choose(K,\
    \ i), fpow(K - i, N))));\n        coeff *= -1;\n    }\n    return mdiv(res, fact[K]);\n\
    }\n\n"
  code: "// Stirling Numbers (1st kind)\n// Depends on mod template\n// Number of\
    \ length N permutations with K disjoint cycles\nvector<vector<ll>> dp;\nll stir1(ll\
    \ N, ll K) {\n    dp.assign(N + 1, vector<ll>(K + 1, -1));\n    return _stir1(N,\
    \ K);\n}\nll _stir1(ll N, ll K) {\n    if (!N && !K) return 1LL;\n    if (!N ||\
    \ !K) return 0LL;\n    ll &ret = dp[N][K];\n    if (ret != -1) return ret;\n \
    \   return ret = madd(mmul(N - 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));\n\
    }\n\n// Stirling Numbers (2nd kind)\n// Depends on mod and nchooser templates\
    \ (and calling init_nchooser to init factorial table)\n// Number of ways to partition\
    \ N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does\
    \ not matter)\n// If you want to do it with labelled subsets, just remove the\
    \ division at the end or multiply by fact[K]\n// If empty subsets were allowed,\
    \ the answer would just be K^N\nll stir2(ll N, ll K) {\n    ll res = 0;\n    int\
    \ coeff = 1;\n    for (int i = 0; i <= K; i++) {\n        res = madd(res, mmul(coeff,\
    \ mmul(choose(K, i), fpow(K - i, N))));\n        coeff *= -1;\n    }\n    return\
    \ mdiv(res, fact[K]);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/stirling.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stirling.cpp
layout: document
redirect_from:
- /library/math/stirling.cpp
- /library/math/stirling.cpp.html
title: math/stirling.cpp
---
