---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: rank_compression.hpp
    title: rank_compression.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ rank_compression.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"template.hpp\"\n#include \"test_utils.hpp\"\n#include \"rank_compression.hpp\"\
    \n\nRanks<ll> r;\nusing T = tuple<int, ll, ll>;\nvector<T> qs;\n\nint main() {\n\
    \    fast_io();\n    int Q = readi();\n    for (int i = 0; i < Q; i++) {\n   \
    \     if (readi() == 0) {\n            ll k = readl(); ll v = readl();\n     \
    \       r.add(k);\n            qs.eb(0, k, v);\n        }\n        else {\n  \
    \          ll k = readl();\n            r.add(k);\n            qs.eb(1, k, -1);\n\
    \        }\n    }\n    r.init();\n\n    vector<ll> A(SZ(r)+1);\n    for (auto\
    \ [t, a, b] : qs) {\n        a = r.get(a);\n        if (t == 0) A[a] = b;\n  \
    \      else print(A[a]);\n    }\n}"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - rank_compression.hpp
  isVerificationFile: true
  path: tests/rank_compression.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/rank_compression.test.cpp
layout: document
redirect_from:
- /verify/tests/rank_compression.test.cpp
- /verify/tests/rank_compression.test.cpp.html
title: tests/rank_compression.test.cpp
---
