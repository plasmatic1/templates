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
  bundledCode: "#line 1 \"string/hash_utils.cpp\"\n// Hashing stuff\nconst ll MODS[2]\
    \ = {1000000007, 1000000009}, BASE[2] = {131, 191};\nll madd(ll a, ll b, ll mod)\
    \ { return (a + b) % mod; }\nll msub(ll a, ll b, ll mod) { return (a - b + mod)\
    \ % mod; }\nll mmul(ll a, ll b, ll mod) { return (a * b) % mod; }\nll fpow(ll\
    \ x, ll y, ll mod) {\n    if (!y) return 1LL;\n    return mmul(fpow(mmul(x, x,\
    \ mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);\n}\nll mdiv(ll x, ll y, ll mod)\
    \ { return mmul(x, fpow(y, mod - 2, mod), mod); }\n\nll comb(ll lo, ll hi) { return\
    \ (hi << 32) | lo; }\nll glo(ll x) { return x & ((1LL << 32) - 1); }\nll ghi(ll\
    \ x) { return x >> 32; }\nll append1(ll hsh, int val, int i) { return madd(mmul(hsh,\
    \ BASE[i], MODS[i]), val, MODS[i]); }\nll append(ll hsh, int val) { return comb(append1(glo(hsh),\
    \ val, 0), append1(ghi(hsh), val, 1)); } \nvector<ll> pows[2];\nvoid init_pow(int\
    \ N) {\n    for (auto i = 0; i < 2; i++) {\n        pows[i].resize(N + 1);\n \
    \       pows[i][0] = 1LL;\n        for (auto j = 1; j <= N; j++)\n           \
    \ pows[i][j] = mmul(pows[i][j - 1], BASE[i], MODS[i]);\n    }\n}\nll ghsh1(ll\
    \ hr, ll hl, int sz, int i) {\n    return msub(hr, mmul(pows[i][sz], hl, MODS[i]),\
    \ MODS[i]);\n}\nll ghsh(ll *hs, int l, int r) {\n    int sz = r - l + 1;\n   \
    \ return comb(ghsh1(glo(hs[r]), glo(hs[l - 1]), sz, 0), ghsh1(ghi(hs[r]), ghi(hs[l\
    \ - 1]), sz, 1));\n}\nll concat1(ll hsh, ll hsh2, int sz, int i) { return madd(mmul(hsh,\
    \ pows[i][sz], MODS[i]), hsh2, MODS[i]); }\nll concat(ll hsh, ll hsh2, int sz)\
    \ { return comb(concat1(glo(hsh), glo(hsh2), sz, 0), concat1(ghi(hsh), ghi(hsh2),\
    \ sz, 1)); }\n"
  code: "// Hashing stuff\nconst ll MODS[2] = {1000000007, 1000000009}, BASE[2] =\
    \ {131, 191};\nll madd(ll a, ll b, ll mod) { return (a + b) % mod; }\nll msub(ll\
    \ a, ll b, ll mod) { return (a - b + mod) % mod; }\nll mmul(ll a, ll b, ll mod)\
    \ { return (a * b) % mod; }\nll fpow(ll x, ll y, ll mod) {\n    if (!y) return\
    \ 1LL;\n    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL,\
    \ mod);\n}\nll mdiv(ll x, ll y, ll mod) { return mmul(x, fpow(y, mod - 2, mod),\
    \ mod); }\n\nll comb(ll lo, ll hi) { return (hi << 32) | lo; }\nll glo(ll x) {\
    \ return x & ((1LL << 32) - 1); }\nll ghi(ll x) { return x >> 32; }\nll append1(ll\
    \ hsh, int val, int i) { return madd(mmul(hsh, BASE[i], MODS[i]), val, MODS[i]);\
    \ }\nll append(ll hsh, int val) { return comb(append1(glo(hsh), val, 0), append1(ghi(hsh),\
    \ val, 1)); } \nvector<ll> pows[2];\nvoid init_pow(int N) {\n    for (auto i =\
    \ 0; i < 2; i++) {\n        pows[i].resize(N + 1);\n        pows[i][0] = 1LL;\n\
    \        for (auto j = 1; j <= N; j++)\n            pows[i][j] = mmul(pows[i][j\
    \ - 1], BASE[i], MODS[i]);\n    }\n}\nll ghsh1(ll hr, ll hl, int sz, int i) {\n\
    \    return msub(hr, mmul(pows[i][sz], hl, MODS[i]), MODS[i]);\n}\nll ghsh(ll\
    \ *hs, int l, int r) {\n    int sz = r - l + 1;\n    return comb(ghsh1(glo(hs[r]),\
    \ glo(hs[l - 1]), sz, 0), ghsh1(ghi(hs[r]), ghi(hs[l - 1]), sz, 1));\n}\nll concat1(ll\
    \ hsh, ll hsh2, int sz, int i) { return madd(mmul(hsh, pows[i][sz], MODS[i]),\
    \ hsh2, MODS[i]); }\nll concat(ll hsh, ll hsh2, int sz) { return comb(concat1(glo(hsh),\
    \ glo(hsh2), sz, 0), concat1(ghi(hsh), ghi(hsh2), sz, 1)); }\n"
  dependsOn: []
  isVerificationFile: false
  path: string/hash_utils.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/hash_utils.cpp
layout: document
redirect_from:
- /library/string/hash_utils.cpp
- /library/string/hash_utils.cpp.html
title: string/hash_utils.cpp
---
