---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/eea.hpp
    title: math/eea.hpp
  - icon: ':question:'
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
    \ math/crt.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"../template.hpp\"\n#include \"eea.hpp\"\n#pragma once\n\n/*\n\
    \ * Provide in the form of:\n * {{residue1, modulus1}, {residue2, modulus2}, ...}\n\
    \ */\ntemplate <typename T> T crt(const vector<pair<T, T>> &ms) {\n    T v = 0,\
    \ m = 1;\n    for (auto [v0, m0] : ms) {\n        T c, c0, _ = extgcd(m, m0, c,\
    \ c0);\n        v = v*c*m + v0*c0*m0;\n        m *= m0;\n    }\n    return v;\n\
    }\n"
  dependsOn:
  - template.hpp
  - math/eea.hpp
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2021-07-05 01:37:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt.hpp
layout: document
redirect_from:
- /library/math/crt.hpp
- /library/math/crt.hpp.html
title: math/crt.hpp
---
