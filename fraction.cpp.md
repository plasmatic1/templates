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
  bundledCode: "#line 1 \"fraction.cpp\"\nstruct Fr {\n    ll n, d;\n    void reduce()\
    \ {\n        ll gv = __gcd(abs(n), abs(d));\n        n /= gv; d /= gv;\n     \
    \   if (d < 0) {\n            n *= -1; d *= -1;\n        }\n    }\n    Fr(ll a,\
    \ ll b) : n(a), d(b) { reduce(); }\n    Fr(ll x) : n(x), d(1) { reduce(); }\n\
    \    Fr inv() const { return Fr(d, n); }\n    Fr neg() const { return Fr(-n, d);\
    \ }\n    Fr mul(Fr f) const { return Fr(n * f.n, d * f.d); }\n    Fr div(Fr f)\
    \ const { return mul(f.inv()); }\n    Fr add(Fr f) const { return Fr(n * f.d +\
    \ f.n * d, d * f.d); }\n    Fr sub(Fr f) const { return add(f.neg()); }\n    bool\
    \ operator==(const Fr o) const { return n == o.n && d == o.d; }\n    bool operator!=(const\
    \ Fr o) const { return n != o.n || d != o.d; }\n    bool operator<(const Fr o)\
    \ const { return n * o.d < o.n * d; }\n    bool operator>(const Fr o) const {\
    \ return o < *this; }\n    bool operator<=(const Fr o) const { return !(o < *this);\
    \ }\n    bool operator>=(const Fr o) const { return !(*this < o); }\n};\nostream&\
    \ operator<<(ostream &out, const Fr o) {\n    out << o.n << \" / \" << o.d;\n\
    \    return out;\n}\n\n"
  code: "struct Fr {\n    ll n, d;\n    void reduce() {\n        ll gv = __gcd(abs(n),\
    \ abs(d));\n        n /= gv; d /= gv;\n        if (d < 0) {\n            n *=\
    \ -1; d *= -1;\n        }\n    }\n    Fr(ll a, ll b) : n(a), d(b) { reduce();\
    \ }\n    Fr(ll x) : n(x), d(1) { reduce(); }\n    Fr inv() const { return Fr(d,\
    \ n); }\n    Fr neg() const { return Fr(-n, d); }\n    Fr mul(Fr f) const { return\
    \ Fr(n * f.n, d * f.d); }\n    Fr div(Fr f) const { return mul(f.inv()); }\n \
    \   Fr add(Fr f) const { return Fr(n * f.d + f.n * d, d * f.d); }\n    Fr sub(Fr\
    \ f) const { return add(f.neg()); }\n    bool operator==(const Fr o) const { return\
    \ n == o.n && d == o.d; }\n    bool operator!=(const Fr o) const { return n !=\
    \ o.n || d != o.d; }\n    bool operator<(const Fr o) const { return n * o.d <\
    \ o.n * d; }\n    bool operator>(const Fr o) const { return o < *this; }\n   \
    \ bool operator<=(const Fr o) const { return !(o < *this); }\n    bool operator>=(const\
    \ Fr o) const { return !(*this < o); }\n};\nostream& operator<<(ostream &out,\
    \ const Fr o) {\n    out << o.n << \" / \" << o.d;\n    return out;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: fraction.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fraction.cpp
layout: document
redirect_from:
- /library/fraction.cpp
- /library/fraction.cpp.html
title: fraction.cpp
---
