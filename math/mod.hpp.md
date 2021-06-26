---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/choose.test.cpp
    title: tests/math/choose.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/modint.test.cpp
    title: tests/math/modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"math/mod.hpp\"\n\
    \n// based on Tourist modInt orz\ntemplate <typename MD> struct _ModInt {\n  \
    \  using T = typename decay<decltype(MD::value)>::type;\n    static_assert(sizeof(T)\
    \ >= 4, \"size of T must be at least 32 bits\");\n    static_assert(sizeof(T)\
    \ <= 8, \"size of T must be at most 64 bits\");\n    static_assert(is_integral<T>::value,\
    \ \"T must be an integral type\");\n#ifdef __SIZEOF_INT128__\n    using mul_t\
    \ = typename conditional<sizeof(T) <= 4, int64_t, __int128>::type;\n#else\n  \
    \  using mul_t = int64_t;\n    static_assert(sizeof(T) <= 4, \"int128 not available,\
    \ cannot use 64-bit size of T\");\n#endif\n\n    constexpr static T mod() { return\
    \ MD::value; }\n\n    template <typename U> static T normalize(const U& x) {\n\
    \        T res = x;\n        res %= mod();\n        if (res < 0) res += mod();\n\
    \        return res;\n    }\n\n    T value;\n    constexpr _ModInt() : value()\
    \ {}\n    template <typename U> _ModInt(const U& x) { value = normalize(x); }\n\
    \    const T& operator()() const { return value; }\n    template <typename U>\
    \ operator U() const { return static_cast<U>(value); }\n\n    // FastPow\n   \
    \ template <typename U> static _ModInt pow(_ModInt x, U y) {\n        _ModInt\
    \ res(1);\n        for (; y; y /= 2) {\n            if (y & 1) res *= x;\n   \
    \         x *= x;\n        }\n        return res;\n    }\n    static _ModInt inv(_ModInt\
    \ x) { return pow(x, mod() - 2); }\n\n    // Arithmetic Operators w/ _ModInt\n\
    \    // Assignment operators here\n    _ModInt& operator+=(const _ModInt &o) {\
    \ if ((value += o.value) >= mod()) value -= mod(); return *this; }\n    template\
    \ <typename U> _ModInt& operator+=(const U &o) { return *this += _ModInt(o); }\n\
    \    _ModInt& operator-=(const _ModInt &o) { if ((value -= o.value) < 0) value\
    \ += mod(); return *this; }\n    template <typename U> _ModInt& operator-=(const\
    \ U &o) { return *this += _ModInt(o); }\n    _ModInt& operator++() { return *this\
    \ += 1; }\n    _ModInt operator++(int) { _ModInt res(*this); *this += 1; return\
    \ res; }\n    _ModInt& operator--() { return *this -= 1; }\n    _ModInt operator--(int)\
    \ { _ModInt res(*this); *this -= 1; return res; }\n    _ModInt& operator*=(const\
    \ _ModInt &o) { value = (mul_t)value * o.value % mod(); return *this; } // make\
    \ sure cast to mul_t!!!\n    template <typename U> _ModInt& operator*=(const U\
    \ &o) { return *this *= _ModInt(o); }\n    _ModInt& operator/=(const _ModInt &o)\
    \ { return *this *= inv(o.value); }\n    template <typename U> _ModInt& operator/=(const\
    \ U &o) { return this /= _ModInt(o); }\n    _ModInt operator-() const { return\
    \ _ModInt(value); }\n    // Other Operators\n    T& operator()() { return value;\
    \ }\n    // Definitions of some operators\n};\n// Binary operators\n#define OP_CMP(op)\
    \ template <typename T> bool operator op(const _ModInt<T> &lhs, const _ModInt<T>\
    \ &rhs) { return lhs.value op rhs.value; } \\\n    template <typename T, typename\
    \ U> bool operator op(const _ModInt<T> &lhs, U rhs) { return lhs op _ModInt<T>(rhs);\
    \ } \\\n    template <typename T, typename U> bool operator op(U lhs, const _ModInt<T>\
    \ &rhs) { return _ModInt<T>(lhs) op rhs; }\n#define OP_ARI(op) template <typename\
    \ T> _ModInt<T> operator op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return\
    \ _ModInt<T>(lhs) op##= rhs; } \\\n    template <typename T, typename U> _ModInt<T>\
    \ operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs;\
    \ } \\\n    template <typename T, typename U> _ModInt<T> operator op(const _ModInt<T>\
    \ &lhs, U rhs) { return _ModInt<T>(lhs) op##= rhs; }\nOP_CMP(==) OP_CMP(!=) OP_CMP(<)\
    \ OP_CMP(>) OP_CMP(<=) OP_CMP(>=)\nOP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)\n#undef\
    \ OP_CMP\n#undef OP_ARI\ntemplate <typename T> istream& operator>>(istream& in,\
    \ _ModInt<T> &o) { return in >> o(); }\ntemplate <typename T> ostream& operator<<(ostream&\
    \ out, _ModInt<T> &o) { return out << o(); }\n\n// Definitions\ntemplate <typename\
    \ T, T mod> using ModInt = _ModInt<integral_constant<T, mod>>;\ntemplate <typename\
    \ T> struct VarMod {\n    static T value;\n    static void read(istream& in) {\
    \ in >> value; }\n    static void set(T v0) { value = v0; }\n};\ntemplate <typename\
    \ T> using VarModInt = _ModInt<VarMod<T>>;\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// based on Tourist modInt\
    \ orz\ntemplate <typename MD> struct _ModInt {\n    using T = typename decay<decltype(MD::value)>::type;\n\
    \    static_assert(sizeof(T) >= 4, \"size of T must be at least 32 bits\");\n\
    \    static_assert(sizeof(T) <= 8, \"size of T must be at most 64 bits\");\n \
    \   static_assert(is_integral<T>::value, \"T must be an integral type\");\n#ifdef\
    \ __SIZEOF_INT128__\n    using mul_t = typename conditional<sizeof(T) <= 4, int64_t,\
    \ __int128>::type;\n#else\n    using mul_t = int64_t;\n    static_assert(sizeof(T)\
    \ <= 4, \"int128 not available, cannot use 64-bit size of T\");\n#endif\n\n  \
    \  constexpr static T mod() { return MD::value; }\n\n    template <typename U>\
    \ static T normalize(const U& x) {\n        T res = x;\n        res %= mod();\n\
    \        if (res < 0) res += mod();\n        return res;\n    }\n\n    T value;\n\
    \    constexpr _ModInt() : value() {}\n    template <typename U> _ModInt(const\
    \ U& x) { value = normalize(x); }\n    const T& operator()() const { return value;\
    \ }\n    template <typename U> operator U() const { return static_cast<U>(value);\
    \ }\n\n    // FastPow\n    template <typename U> static _ModInt pow(_ModInt x,\
    \ U y) {\n        _ModInt res(1);\n        for (; y; y /= 2) {\n            if\
    \ (y & 1) res *= x;\n            x *= x;\n        }\n        return res;\n   \
    \ }\n    static _ModInt inv(_ModInt x) { return pow(x, mod() - 2); }\n\n    //\
    \ Arithmetic Operators w/ _ModInt\n    // Assignment operators here\n    _ModInt&\
    \ operator+=(const _ModInt &o) { if ((value += o.value) >= mod()) value -= mod();\
    \ return *this; }\n    template <typename U> _ModInt& operator+=(const U &o) {\
    \ return *this += _ModInt(o); }\n    _ModInt& operator-=(const _ModInt &o) { if\
    \ ((value -= o.value) < 0) value += mod(); return *this; }\n    template <typename\
    \ U> _ModInt& operator-=(const U &o) { return *this += _ModInt(o); }\n    _ModInt&\
    \ operator++() { return *this += 1; }\n    _ModInt operator++(int) { _ModInt res(*this);\
    \ *this += 1; return res; }\n    _ModInt& operator--() { return *this -= 1; }\n\
    \    _ModInt operator--(int) { _ModInt res(*this); *this -= 1; return res; }\n\
    \    _ModInt& operator*=(const _ModInt &o) { value = (mul_t)value * o.value %\
    \ mod(); return *this; } // make sure cast to mul_t!!!\n    template <typename\
    \ U> _ModInt& operator*=(const U &o) { return *this *= _ModInt(o); }\n    _ModInt&\
    \ operator/=(const _ModInt &o) { return *this *= inv(o.value); }\n    template\
    \ <typename U> _ModInt& operator/=(const U &o) { return this /= _ModInt(o); }\n\
    \    _ModInt operator-() const { return _ModInt(value); }\n    // Other Operators\n\
    \    T& operator()() { return value; }\n    // Definitions of some operators\n\
    };\n// Binary operators\n#define OP_CMP(op) template <typename T> bool operator\
    \ op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return lhs.value op rhs.value;\
    \ } \\\n    template <typename T, typename U> bool operator op(const _ModInt<T>\
    \ &lhs, U rhs) { return lhs op _ModInt<T>(rhs); } \\\n    template <typename T,\
    \ typename U> bool operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs)\
    \ op rhs; }\n#define OP_ARI(op) template <typename T> _ModInt<T> operator op(const\
    \ _ModInt<T> &lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs;\
    \ } \\\n    template <typename T, typename U> _ModInt<T> operator op(U lhs, const\
    \ _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs; } \\\n    template <typename\
    \ T, typename U> _ModInt<T> operator op(const _ModInt<T> &lhs, U rhs) { return\
    \ _ModInt<T>(lhs) op##= rhs; }\nOP_CMP(==) OP_CMP(!=) OP_CMP(<) OP_CMP(>) OP_CMP(<=)\
    \ OP_CMP(>=)\nOP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)\n#undef OP_CMP\n#undef OP_ARI\n\
    template <typename T> istream& operator>>(istream& in, _ModInt<T> &o) { return\
    \ in >> o(); }\ntemplate <typename T> ostream& operator<<(ostream& out, _ModInt<T>\
    \ &o) { return out << o(); }\n\n// Definitions\ntemplate <typename T, T mod> using\
    \ ModInt = _ModInt<integral_constant<T, mod>>;\ntemplate <typename T> struct VarMod\
    \ {\n    static T value;\n    static void read(istream& in) { in >> value; }\n\
    \    static void set(T v0) { value = v0; }\n};\ntemplate <typename T> using VarModInt\
    \ = _ModInt<VarMod<T>>;"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/mod.hpp
  requiredBy: []
  timestamp: '2021-06-26 02:30:43-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/modint.test.cpp
  - tests/math/choose.test.cpp
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
