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
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct DSU {\n    vector<int>\
    \ dsu;\n    void init(int N) {\n        dsu.resize(N + 1);\n        iota(dsu.begin(),\
    \ dsu.end(), 0);\n    }\n    int rt(int x) { return dsu[x] == x ? x : dsu[x] =\
    \ rt(dsu[x]); }\n    void merge(int x, int y) { // x -> y\n        dsu[rt(x)]\
    \ = rt(y); }\n    bool same(int x, int y) { return rt(x) == rt(y); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/dsu.hpp
  requiredBy: []
  timestamp: '2021-06-07 01:26:18-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/dsu.hpp
layout: document
redirect_from:
- /library/ds/dsu.hpp
- /library/ds/dsu.hpp.html
title: ds/dsu.hpp
---
