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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#include \"bits/stdc++.h\"\nusing namespace std;\nusing ll = long long;\n\
    \nstruct HashBase {\n    ll base, mod;\n    HashBase(ll b0, ll m0) : base(b0),\
    \ mod(m0) {}\n    ll madd(ll a, ll b) { return (a + b) % mod; }\n    ll mmul(ll\
    \ a, ll b) { return (a * b) % mod; }\n    ll msub(ll a, ll b) { return ((a - b)\
    \ % mod + mod) % mod; }\n    ll fpow(ll x, ll y) {\n        if (!y) return 1LL;\n\
    \        return mmul(fpow(mmul(x, x), y / 2), (y & 1) ? x : 1LL);\n    }\n   \
    \ ll mdiv(ll x, ll y) { return mmul(x, fpow(y, mod - 2)); }\n\n    vector<ll>\
    \ pow;\n    void initPow(int sz) {\n        pow.resize(sz + 1);\n        pow[0]\
    \ = 1LL;\n        for (int i = 1; i <= sz; i++)\n            pow[i] = mmul(pow[i\
    \ - 1], base);\n    }\n};\n\n// hash with random base\nHashBase randBase(ll mod)\
    \ {\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return HashBase(uniform_int_distribution<ll>(mod / 2, mod - 2)(mt), mod);\n\
    }\n\nstruct Hash {\n    vector<ll> hsh;\n    HashBase &b;\n    Hash(HashBase &b0)\
    \ : b(b0) {}\n    void init(string &s) { // auto-inits pow\n        int len =\
    \ s.length();\n        hsh.resize(len + 1);\n        for (int i = 1; i <= len;\
    \ i++)\n            hsh[i] = b.madd(b.mmul(hsh[i - 1], b.base), s[i - 1]);\n \
    \   }\n    ll get(int l, int r) { // 1-indexed\n        return b.msub(hsh[r],\
    \ b.mmul(hsh[l - 1], b.pow[r - l + 1]));\n    }\n};\n\ntemplate <int C, typename\
    \ HashType = ll>\nstruct MultiHash {\n    HashType comb(HashType curHash, HashType\
    \ toAdd) { return (curHash << 32) | toAdd; } // TODO: Override if needed\n   \
    \ HashType zeroVal() { return 0LL; } // Zero value of the hashtype, override if\
    \ needed \n    Hash hs[C];\n    MultiHash(HashBase bs[C]) {\n        for (int\
    \ i = 0; i < C; i++)\n            hs[i] = Hash(bs[i]);\n    }\n    void init(string\
    \ &s) {\n        for (int i = 0; i < C; i++)\n            hs[i].init(s);\n   \
    \ }\n    HashType get(int l, int r) {\n        HashType res = zeroVal();\n   \
    \     for (int i = 0; i < C; i++)\n            res = comb(res, hs[i].get(l, r));\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/_old_hash.cpp
  requiredBy: []
  timestamp: '2021-07-11 00:49:35-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/_old_hash.cpp
layout: document
redirect_from:
- /library/string/_old_hash.cpp
- /library/string/_old_hash.cpp.html
title: string/_old_hash.cpp
---
