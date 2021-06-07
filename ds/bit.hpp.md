---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Template is 1-indexed (by\
    \ default).  Can be made 0-indexed by modifying Comp\n// Default: Point increment\
    \ and prefix sum query\nstruct Comp {\n    using Data = int;\n    const Data vdef\
    \ = 0;\n    void applyUpdate(Data &to, Data &v) { to += v; }\n    int transformInd(int\
    \ idx, int N) { return idx; }\n};\ntemplate <typename Comp> struct BIT {\n   \
    \ using Data = typename Comp::Data; Comp C;\n    int N; vector<Data> bit;\n  \
    \  void init(int n0) {\n        N = n0;\n        bit.assign(N + 1, C.vdef);\n\
    \    }\n    void update(int x, Data v) {\n        x = C.transformInd(x, N);\n\
    \        for (; x <= N; x += x & -x)\n            C.applyUpdate(bit[x], v);\n\
    \    }\n    Data query(int x) {\n        x = C.transformInd(x, N);\n        Data\
    \ res = C.vdef;\n        for (; x; x -= x & -x)\n            C.applyUpdate(res,\
    \ bit[x]);\n        return res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/bit.hpp
  requiredBy: []
  timestamp: '2021-06-07 01:26:18-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/bit.hpp
layout: document
redirect_from:
- /library/ds/bit.hpp
- /library/ds/bit.hpp.html
title: ds/bit.hpp
---
