---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/totient.test.cpp
    title: tests/math/totient.test.cpp
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
    \ math/totient.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#pragma once\n\ntemplate <typename T> T totient(T\
    \ v) {\n    T res = v;\n    for (T i = 2; i * i <= v; i++) {\n        if (v %\
    \ i == 0) {\n            while (v % i == 0) v /= i;\n            res /= i;\n \
    \           res *= i-1;\n        }\n    }\n    if (v > 1) {\n        res /= v;\n\
    \        res *= v-1;\n    }\n    return res;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/totient.hpp
  requiredBy: []
  timestamp: '2021-06-27 02:07:30-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/totient.test.cpp
documentation_of: math/totient.hpp
layout: document
redirect_from:
- /library/math/totient.hpp
- /library/math/totient.hpp.html
title: math/totient.hpp
---
