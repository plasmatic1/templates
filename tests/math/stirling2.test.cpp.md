---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/choose.hpp
    title: math/choose.hpp
  - icon: ':question:'
    path: math/eea.hpp
    title: math/eea.hpp
  - icon: ':question:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/stirling2.hpp
    title: math/stirling2.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/choose.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../math/mod.hpp\"\n#include \"../../math/choose.hpp\"\n#include \"../../math/stirling2.hpp\"\
    \n\nusing MI = ModInt<int, 1000000007>;\n\nChoose<MI> c;\n\n// Stirling numbers\
    \ of the second kind\nint main() {\n    fast_io();\n    int N = readi(), K = readi();\n\
    \    c.init(N);\n    MI ans = 0;\n    for (int i = 1; i <= min(N, K); i++)\n \
    \       ans += stir2(N, i, c);\n    print(ans);\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - math/mod.hpp
  - math/eea.hpp
  - math/choose.hpp
  - math/stirling2.hpp
  isVerificationFile: true
  path: tests/math/stirling2.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/math/stirling2.test.cpp
layout: document
redirect_from:
- /verify/tests/math/stirling2.test.cpp
- /verify/tests/math/stirling2.test.cpp.html
title: tests/math/stirling2.test.cpp
---
