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
  bundledCode: "#line 1 \"external/UNFINISHED_ntt_big_mod.cpp\"\nusing ll = long long;\n\
    using ull = unsigned long long;\null multiplyHighUnsigned(ull x, ull y) {\n  \
    \  ull x_high = x >> 32;\n    ull y_high = y >> 32;\n    ull x_low = x & 0xFFFFFFFFL;\n\
    \    ull y_low = y & 0xFFFFFFFFL;\n        \n    ull z2 = x_low * y_low;\n   \
    \ ull t = x_high * y_low + (z2 >> 32);\n    ull z1 = t & 0xFFFFFFFFL;\n    ull\
    \ z0 = t >> 32;\n    z1 += x_low * y_high;\n    return x_high * y_high + z0 +\
    \ (z1 >> 32);\n}\nll mulMod(a: Long, b: Long {\n    xh = multiplyHighUnsigned(a,\
    \ b) // high word of product\n    xl = a * b // low word of product\n\n    xrh\
    \ = multiplyHighUnsigned(xh, BARR_R) // high word of xr\n    xrm = multiplyHighUnsigned(xl,\
    \ BARR_R) // middle word of xr, first part\n    add = xh * BARR_R // second part\
    \ of middle word\n    xrm += add // add them\n    if(add ^ (1L << 63) > xrm ^\
    \ (1L << 63)) xrh++ // carry, see note 1\n\n    t = xl - ((xrh << 2) | (xrm >>>\
    \ 62)) * MOD - MOD // see note 2\n    t += (t >> 63) & MOD\n    return t\n}\n"
  code: "using ll = long long;\nusing ull = unsigned long long;\null multiplyHighUnsigned(ull\
    \ x, ull y) {\n    ull x_high = x >> 32;\n    ull y_high = y >> 32;\n    ull x_low\
    \ = x & 0xFFFFFFFFL;\n    ull y_low = y & 0xFFFFFFFFL;\n        \n    ull z2 =\
    \ x_low * y_low;\n    ull t = x_high * y_low + (z2 >> 32);\n    ull z1 = t & 0xFFFFFFFFL;\n\
    \    ull z0 = t >> 32;\n    z1 += x_low * y_high;\n    return x_high * y_high\
    \ + z0 + (z1 >> 32);\n}\nll mulMod(a: Long, b: Long {\n    xh = multiplyHighUnsigned(a,\
    \ b) // high word of product\n    xl = a * b // low word of product\n\n    xrh\
    \ = multiplyHighUnsigned(xh, BARR_R) // high word of xr\n    xrm = multiplyHighUnsigned(xl,\
    \ BARR_R) // middle word of xr, first part\n    add = xh * BARR_R // second part\
    \ of middle word\n    xrm += add // add them\n    if(add ^ (1L << 63) > xrm ^\
    \ (1L << 63)) xrh++ // carry, see note 1\n\n    t = xl - ((xrh << 2) | (xrm >>>\
    \ 62)) * MOD - MOD // see note 2\n    t += (t >> 63) & MOD\n    return t\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: external/UNFINISHED_ntt_big_mod.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/UNFINISHED_ntt_big_mod.cpp
layout: document
redirect_from:
- /library/external/UNFINISHED_ntt_big_mod.cpp
- /library/external/UNFINISHED_ntt_big_mod.cpp.html
title: external/UNFINISHED_ntt_big_mod.cpp
---
