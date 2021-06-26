---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fast_modinv.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#pragma once\n\ntemplate <typename T> struct\
    \ FastModInv {\n    vector<T> inv;\n    T mod;\n    void init(int N, T _mod) {\n\
    \        inv.assign(N+1); inv[1] = 1LL; mod = _mod;\n        for (int i = 2; i\
    \ <= N; i++)\n            inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;\n\
    \    }\n    T mdiv(T x, T y) { return x * inv[y] % mod; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/fast_modinv.hpp
  requiredBy: []
  timestamp: '2021-06-26 02:30:43-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast_modinv.hpp
layout: document
redirect_from:
- /library/math/fast_modinv.hpp
- /library/math/fast_modinv.hpp.html
title: math/fast_modinv.hpp
---
