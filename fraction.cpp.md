---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus ==\
    \ 201703L // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
    \ // for some templates\n#endif\nusing ll = long long; using ull = unsigned long\
    \ long; using ld = long double;\nusing pii = pair<int, int>; using pll = pair<long\
    \ long, long long>;\n#ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
    \ // Common file\n#include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\
    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,\
    \ comp, rb_tree_tag, tree_order_statistics_node_update>;\ntemplate <typename K,\
    \ typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n// HashSet\n#include <ext/pb_ds/assoc_container.hpp>\n\
    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,\
    \ Hash>;\ntemplate <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\nconst ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };\n#endif\n//\
    \ More utilities\nint SZ(string &v) { return v.length(); }\ntemplate <typename\
    \ C> int SZ(C &v) { return v.size(); }\ntemplate <typename C> void UNIQUE(vector<C>\
    \ &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());\
    \ }\ntemplate <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }\n\
    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }\nconst\
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"fraction.cpp\"\n\
    \ntemplate <typename T = int64_t> struct Fraction {\n    T n, d;\n    void reduce()\
    \ {\n        T gv = __gcd(abs(n), abs(d));\n        n /= gv; d /= gv;\n      \
    \  if (d < 0) {\n            n *= -1; d *= -1;\n        }\n    }\n    Fraction(T\
    \ a, T b) : n(a), d(b) { reduce(); }\n    Fraction(T x) : n(x), d(1) { reduce();\
    \ }\n    Fraction inv() const { return Fraction(d, n); }\n    Fraction neg() const\
    \ { return Fraction(-n, d); }\n    Fraction mul(Fraction f) const { return Fraction(n\
    \ * f.n, d * f.d); }\n    Fraction div(Fraction f) const { return mul(f.inv());\
    \ }\n    Fraction add(Fraction f) const { return Fraction(n * f.d + f.n * d, d\
    \ * f.d); }\n    Fraction sub(Fraction f) const { return add(f.neg()); }\n   \
    \ bool operator==(const Fraction o) const { return n == o.n && d == o.d; }\n \
    \   bool operator!=(const Fraction o) const { return n != o.n || d != o.d; }\n\
    \    bool operator<(const Fraction o) const { return n * o.d < o.n * d; }\n  \
    \  bool operator>(const Fraction o) const { return o < *this; }\n    bool operator<=(const\
    \ Fraction o) const { return !(o < *this); }\n    bool operator>=(const Fraction\
    \ o) const { return !(*this < o); }\n};\nostream& operator<<(ostream &out, const\
    \ Fraction o) {\n    out << o.n << \" / \" << o.d;\n    return out;\n}\n\n"
  code: "#pragma once\n#include \"template.hpp\"\n\ntemplate <typename T = int64_t>\
    \ struct Fraction {\n    T n, d;\n    void reduce() {\n        T gv = __gcd(abs(n),\
    \ abs(d));\n        n /= gv; d /= gv;\n        if (d < 0) {\n            n *=\
    \ -1; d *= -1;\n        }\n    }\n    Fraction(T a, T b) : n(a), d(b) { reduce();\
    \ }\n    Fraction(T x) : n(x), d(1) { reduce(); }\n    Fraction inv() const {\
    \ return Fraction(d, n); }\n    Fraction neg() const { return Fraction(-n, d);\
    \ }\n    Fraction mul(Fraction f) const { return Fraction(n * f.n, d * f.d); }\n\
    \    Fraction div(Fraction f) const { return mul(f.inv()); }\n    Fraction add(Fraction\
    \ f) const { return Fraction(n * f.d + f.n * d, d * f.d); }\n    Fraction sub(Fraction\
    \ f) const { return add(f.neg()); }\n    bool operator==(const Fraction o) const\
    \ { return n == o.n && d == o.d; }\n    bool operator!=(const Fraction o) const\
    \ { return n != o.n || d != o.d; }\n    bool operator<(const Fraction o) const\
    \ { return n * o.d < o.n * d; }\n    bool operator>(const Fraction o) const {\
    \ return o < *this; }\n    bool operator<=(const Fraction o) const { return !(o\
    \ < *this); }\n    bool operator>=(const Fraction o) const { return !(*this <\
    \ o); }\n};\nostream& operator<<(ostream &out, const Fraction o) {\n    out <<\
    \ o.n << \" / \" << o.d;\n    return out;\n}\n\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: fraction.cpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fraction.cpp
layout: document
redirect_from:
- /library/fraction.cpp
- /library/fraction.cpp.html
title: fraction.cpp
---
