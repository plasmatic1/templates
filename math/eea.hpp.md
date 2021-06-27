---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/crt.hpp
    title: math/crt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/eea.test.cpp
    title: tests/math/eea.test.cpp
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
    \ math/eea.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#pragma once\n\n/*\n * ax + by = gcd(a, b)\n\
    \ *\n * we know\n * bx' + (a%b)y' = gcd(a, b)\n *\n * bx' + (a-b*(a//b))y' = gcd(a,\
    \ b)\n * bx' + ay' - b*(a//b)y' = gcd(a, b)\n * ay' + b(x' - (a//b)y') = gcd(a,\
    \ b)\n */\ntemplate <typename T> T extgcd(T a, T b, T &x, T &y) {\n    if (b ==\
    \ 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n    T x0, y0,\
    \ res = extgcd(b, a%b, x0, y0);\n    x = y0;\n    y = x0 - (a / b) * y0;\n   \
    \ return res;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/eea.hpp
  requiredBy:
  - math/crt.hpp
  timestamp: '2021-06-27 02:07:30-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/eea.test.cpp
documentation_of: math/eea.hpp
layout: document
redirect_from:
- /library/math/eea.hpp
- /library/math/eea.hpp.html
title: math/eea.hpp
---
