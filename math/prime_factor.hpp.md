---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_factor1.test.cpp
    title: tests/math/prime_factor1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_factor2.test.cpp
    title: tests/math/prime_factor2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/prime_factor.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#pragma once\n\ntemplate <typename T> vector<pair<T,\
    \ int>> primeFactor1(T v) {\n    vector<pair<T, int>> res;\n    for (T i = 2;\
    \ i * i <= v; i++) {\n        if (v % i == 0) {\n            int cnt = 0;\n  \
    \          for (; v % i == 0; v /= i) cnt++;\n            res.emplace_back(i,\
    \ cnt);\n        }\n    }\n    if (v > 1) res.emplace_back(v, 1);\n    return\
    \ res;\n}\ntemplate <typename T> vector<T> primeFactor2(T v) {\n    vector<T>\
    \ res;\n    for (T i = 2; i * i <= v; i++) {\n        for (; v % i == 0; v /=\
    \ i)\n            res.push_back(i);\n    }\n    if (v > 1) res.push_back(v);\n\
    \    return res;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy: []
  timestamp: '2021-06-27 02:07:30-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/prime_factor1.test.cpp
  - tests/math/prime_factor2.test.cpp
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: math/prime_factor.hpp
---
