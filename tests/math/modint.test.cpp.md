---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/eea.hpp
    title: math/eea.hpp
  - icon: ':question:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
  bundledCode: "#line 1 \"tests/math/modint.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\
    \n#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    // Defines\n#define fs first\n#define sn second\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define all(x)\
    \ (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus == 201703L\
    \ // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tests/test_utils.hpp\"\
    \n\n// I/O\ntemplate <typename T> void print(T v) {\n    cout << v << '\\n';\n\
    }\n\ntemplate <typename T, typename... Rest> void print(T v, Rest... vs) {\n \
    \   cout << v << ' ';\n    print(vs...);\n}\n\nvoid fast_io() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n}\n\n// Reading operators\ntemplate <typename T, typename\
    \ U> istream& operator>>(istream& in, pair<T, U> &o) {\n    return in >> o.first\
    \ >> o.second;\n}\n\n// Read helpers\nint readi() {\n    int x; cin >> x;\n  \
    \  return x;\n}\n\nll readl() {\n    ll x; cin >> x;\n    return x;\n}\n\ntemplate\
    \ <typename T> vector<T> readv(int n) {\n    vector<T> res(n);\n    for (auto\
    \ &x : res) cin >> x;\n    return res;\n}\n\n// Functional stuff\ntemplate <typename\
    \ T> vector<pair<int, T>> enumerate(vector<T> v, int start = 0) {\n    vector<pair<int,\
    \ T>> res;\n    for (auto &x : v)\n        res.emplace_back(start++, x);\n   \
    \ return res;\n}\n\n#line 3 \"math/eea.hpp\"\n\n/*\n * ax + by = gcd(a, b)\n *\n\
    \ * we know\n * bx' + (a%b)y' = gcd(a, b)\n *\n * bx' + (a-b*(a//b))y' = gcd(a,\
    \ b)\n * bx' + ay' - b*(a//b)y' = gcd(a, b)\n * ay' + b(x' - (a//b)y') = gcd(a,\
    \ b)\n */\ntemplate <typename T> T extgcd(T a, T b, T &x, T &y) {\n    if (b ==\
    \ 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n    T x0, y0,\
    \ res = extgcd(b, a%b, x0, y0);\n    x = y0;\n    y = x0 - (a / b) * y0;\n   \
    \ return res;\n}\n#line 4 \"math/mod.hpp\"\n\n// based on Tourist modInt orz\n\
    template <typename MD> struct _ModInt {\n    using T = typename decay<decltype(MD::value)>::type;\n\
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
    \ }\n    static _ModInt inv(const _ModInt &x) {\n        T inv, _; extgcd(x.value,\
    \ mod(), inv, _);\n        return _ModInt(inv);\n    }\n\n    // Arithmetic Operators\
    \ w/ _ModInt\n    // Assignment operators here\n    _ModInt& operator+=(const\
    \ _ModInt &o) { if ((value += o.value) >= mod()) value -= mod(); return *this;\
    \ }\n    template <typename U> _ModInt& operator+=(const U &o) { return *this\
    \ += _ModInt(o); }\n    _ModInt& operator-=(const _ModInt &o) { if ((value -=\
    \ o.value) < 0) value += mod(); return *this; }\n    template <typename U> _ModInt&\
    \ operator-=(const U &o) { return *this -= _ModInt(o); }\n    _ModInt& operator++()\
    \ { return *this += 1; }\n    _ModInt operator++(int) { _ModInt res(*this); *this\
    \ += 1; return res; }\n    _ModInt& operator--() { return *this -= 1; }\n    _ModInt\
    \ operator--(int) { _ModInt res(*this); *this -= 1; return res; }\n    _ModInt&\
    \ operator*=(const _ModInt &o) { value = (mul_t)value * o.value % mod(); if (value\
    \ < 0) value += mod(); return *this; } // make sure cast to mul_t!!!\n    template\
    \ <typename U> _ModInt& operator*=(const U &o) { return *this *= _ModInt(o); }\n\
    \    _ModInt& operator/=(const _ModInt &o) { return *this *= inv(o.value); }\n\
    \    template <typename U> _ModInt& operator/=(const U &o) { return *this /= _ModInt(o);\
    \ }\n    _ModInt operator-() const { return _ModInt(value); }\n    // Other Operators\n\
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
    \ = _ModInt<VarMod<T>>;\n#line 5 \"tests/math/modint.test.cpp\"\n\nusing MI =\
    \ ModInt<int, 1000000007>;\n\nint main() {\n    fast_io();\n    int N = readi(),\
    \ K = readi();\n    print(MI::pow(K, N));\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../math/mod.hpp\"\n\nusing MI = ModInt<int, 1000000007>;\n\nint main() {\n\
    \    fast_io();\n    int N = readi(), K = readi();\n    print(MI::pow(K, N));\n\
    }\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - math/mod.hpp
  - math/eea.hpp
  isVerificationFile: true
  path: tests/math/modint.test.cpp
  requiredBy: []
  timestamp: '2021-07-11 00:49:35-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/math/modint.test.cpp
layout: document
redirect_from:
- /verify/tests/math/modint.test.cpp
- /verify/tests/math/modint.test.cpp.html
title: tests/math/modint.test.cpp
---
