---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"external/fastmod.cpp\"\nusing ull = unsigned long long;\n\
    using L = __uint128_t;\nstruct FastMod {\n\tull b, m;\n\tFastMod(ull b) : b(b),\
    \ m(ull((L(1) << 64) / b)) {}\n\tull reduce(ull a) {\n\t\tull q = (ull)((L(m)\
    \ * a) >> 64);\n\t\tull r = a - q * b; // can be proven that 0 <= r < 2*b\n\t\t\
    return r >= b ? r - b : r;\n\t}\n};\n"
  code: "using ull = unsigned long long;\nusing L = __uint128_t;\nstruct FastMod {\n\
    \tull b, m;\n\tFastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}\n\tull reduce(ull\
    \ a) {\n\t\tull q = (ull)((L(m) * a) >> 64);\n\t\tull r = a - q * b; // can be\
    \ proven that 0 <= r < 2*b\n\t\treturn r >= b ? r - b : r;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: external/fastmod.cpp
  requiredBy: []
  timestamp: '2021-06-26 02:30:43-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/fastmod.cpp
layout: document
redirect_from:
- /library/external/fastmod.cpp
- /library/external/fastmod.cpp.html
title: external/fastmod.cpp
---
