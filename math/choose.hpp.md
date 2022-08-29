---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/catalan.hpp
    title: math/catalan.hpp
  - icon: ':warning:'
    path: math/stirling1.hpp
    title: math/stirling1.hpp
  - icon: ':heavy_check_mark:'
    path: math/stirling2.hpp
    title: math/stirling2.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/choose.test.cpp
    title: tests/math/choose.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/permute.test.cpp
    title: tests/math/permute.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/stirling2.test.cpp
    title: tests/math/stirling2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/choose.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#pragma once\n\n// N choose R\ntemplate <typename\
    \ T> struct Choose {\n    vector<T> fact, invf;\n    void init(int N) {\n    \
    \    fact.resize(N + 1); invf.resize(N + 1);\n        fact[0] = 1;\n        for\
    \ (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;\n        invf[N] = 1 / fact[N];\n\
    \        for (auto i = N - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1);\n\
    \    }\n    T choose(T N, T K) { return fact[N] * invf[K] * invf[N - K]; }\n \
    \   T permute(T N, T K) { return fact[N] * invf[N - K]; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/choose.hpp
  requiredBy:
  - math/stirling2.hpp
  - math/stirling1.hpp
  - math/catalan.hpp
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/permute.test.cpp
  - tests/math/stirling2.test.cpp
  - tests/math/choose.test.cpp
documentation_of: math/choose.hpp
layout: document
redirect_from:
- /library/math/choose.hpp
- /library/math/choose.hpp.html
title: math/choose.hpp
---
