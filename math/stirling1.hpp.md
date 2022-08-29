---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/choose.hpp
    title: math/choose.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/choose.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#include \"choose.hpp\"\n#pragma once\n\n//\
    \ Stirling Numbers (1st kind)\n// Depends on mod template\n// Number of length\
    \ N permutations with K disjoint cycles\ntemplate <typename T> struct Stir1 {\n\
    \    vector<vector<T>> dp;\n    void init(int N, int K) {\n        dp.assign(N+1,\
    \ vector<T>(K+1));\n        dp[0][0] = 1;\n        for (int i = 1; i <= N; i++)\n\
    \            for (int j = 1; j <= K; j++)\n                dp[i][j] = (i - 1)\
    \ * dp[i - 1][j] + dp[i - 1][j - 1];\n    }\n    T get(int n, int k) { return\
    \ dp[n][k]; }\n};"
  dependsOn:
  - template.hpp
  - math/choose.hpp
  isVerificationFile: false
  path: math/stirling1.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stirling1.hpp
layout: document
redirect_from:
- /library/math/stirling1.hpp
- /library/math/stirling1.hpp.html
title: math/stirling1.hpp
---
