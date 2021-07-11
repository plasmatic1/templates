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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/choose.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../math/mod.hpp\"\n#include \"../../math/choose.hpp\"\n\nusing MI = ModInt<int,\
    \ 1000000007>;\nChoose<MI> c;\n\nint main() {\n    fast_io();\n    c.init(1000);\n\
    \    int N = readi(), K = readi();\n    if (K < N) print(0);\n    else print(c.permute(K,\
    \ N));\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - math/mod.hpp
  - math/eea.hpp
  - math/choose.hpp
  isVerificationFile: true
  path: tests/math/permute.test.cpp
  requiredBy: []
  timestamp: '2021-07-11 00:49:35-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/math/permute.test.cpp
layout: document
redirect_from:
- /verify/tests/math/permute.test.cpp
- /verify/tests/math/permute.test.cpp.html
title: tests/math/permute.test.cpp
---
