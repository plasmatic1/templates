---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/choose.hpp
    title: math/choose.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/choose.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#include \"choose.hpp\"\n#pragma once\n\n//\
    \ Stirling Numbers (1st kind)\n// Depends on mod template\n// Number of length\
    \ N permutations with K disjoint cycles\ntemplate <typename T> struct Stir1 {\n\
    \    vector<vector<T>> dp;\n    void init(int N, int K) {\n        dp.assign(N+1,\
    \ vector<T>(K+1));\n        dp[0][0] = 1;\n        for (int i = 1; i <= N; i++)\n\
    \            for (int j = 1; j <= K; j++)\n                dp[i][j] = (i-1)*dp[i-1][j]\
    \ + dp[i-1][j-1];\n    }\n    T get(int n, int k) { return dp[n][k]; }\n};\n\n\
    // Stirling Numbers (2nd kind)\n// Depends on mod and nchooser templates (and\
    \ calling init_nchooser to init factorial table)\n// Number of ways to partition\
    \ N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does\
    \ not matter)\n// If you want to do it with labelled subsets, just remove the\
    \ division at the end or multiply by fact[K]\n// If empty subsets were allowed,\
    \ the answer would just be K^N\ntemplate <typename T> T stir2(int N, int K, Choose<T>\
    \ &c) {\n    T res = 0, coeff = 1;\n    for (int i = 0; i <= K; i++) {\n     \
    \   res += coeff * c.choose(K, i) * mpow((T)K - i, N));\n        coeff *= -1;\n\
    \    }\n    return mdiv(res, c.fact[K]);\n}\n"
  dependsOn:
  - template.hpp
  - math/choose.hpp
  isVerificationFile: false
  path: math/stirling.hpp
  requiredBy: []
  timestamp: '2021-06-26 02:30:43-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stirling.hpp
layout: document
redirect_from:
- /library/math/stirling.hpp
- /library/math/stirling.hpp.html
title: math/stirling.hpp
---
