---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segment_tree.hpp
    title: ds/segment_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"tests/ds/segment_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\n#define DEBUG 1\nusing namespace\
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
    \ return res;\n}\n\n#line 3 \"ds/segment_tree.hpp\"\n\n// Template is 1-indexed\n\
    // Default Comp: RMQ + Set query\n// Functions merge and applyUpdate should be\
    \ implemented left to right\nstruct Comp {\n    using Data = int;\n    using Update\
    \ = int;\n    const Data vdef = INF;\n    Data merge(Data l, Data r) { return\
    \ min(l, r); }\n    void applyUpdate(Data &l, Update &r) { l = r; }\n};\n#define\
    \ MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;\ntemplate\
    \ <class Comp> struct SegmentTree {\n    using Data = typename Comp::Data; using\
    \ Update = typename Comp::Update; Comp C;\n    int N;\n    vector<Data> seg;\n\
    \    void init(int n0) {\n        N = n0;\n        seg.assign(2 * N + 2, C.vdef);\n\
    \    }\n    Data _query(int ql, int qr, int i, int l, int r) {\n        if (ql\
    \ > r || qr < l) return C.vdef;\n        if (l >= ql && r <= qr) return seg[i];\n\
    \        MID;\n        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql,\
    \ qr, rhs, mid + 1, r));\n    }\n    Data _update(int q, Update v, int i, int\
    \ l, int r) {\n        if (q > r || q < l) return seg[i];\n        if (l == q\
    \ && r == q) {\n            C.applyUpdate(seg[i], v);\n            return seg[i];\n\
    \        }\n        MID;\n        return seg[i] = C.merge(_update(q, v, lhs, l,\
    \ mid), _update(q, v, rhs, mid + 1, r));\n    }\n    Data query(int ql, int qr)\
    \ { return _query(ql, qr, 1, 1, N); }\n    void update(int q, Update v) { _update(q,\
    \ v, 1, 1, N); }\n};\n#line 3 \"math/eea.hpp\"\n\n/*\n * ax + by = gcd(a, b)\n\
    \ *\n * we know\n * bx' + (a%b)y' = gcd(a, b)\n *\n * bx' + (a-b*(a//b))y' = gcd(a,\
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
    \ = _ModInt<VarMod<T>>;\n#line 6 \"tests/ds/segment_tree.test.cpp\"\n\n// A(x)\
    \ = ax+b, B(x) = cx+d\n// B(A(x)) = c(ax+b)+d = acx + bc + d\nusing MI = ModInt<int,\
    \ 998244353>;\nusing pm = pair<MI, MI>;\nstruct CompComp {\n    using Data = pm;\n\
    \    using Update = pm;\n    const Data vdef = {1, 0};\n    Data merge(Data l,\
    \ Data r) {\n        auto [a, b] = l;\n        auto [c, d] = r;\n        return\
    \ {a * c, b * c + d};\n    }\n    void applyUpdate(Data &l, Update &r) { l = r;\
    \ }\n};\n\nint main() {\n    fast_io();\n    int N = readi(), Q = readi();\n \
    \   SegmentTree<CompComp> seg; seg.init(N);\n    for (auto [i, v] : enumerate(readv<pll>(N),\
    \ 1))\n        seg.update(i, v);\n    while (Q--) {\n        if (readi() == 0)\
    \ {\n            int p = readi()+1, b = readi(), c = readi();\n            seg.update(p,\
    \ {b, c});\n        }\n        else {\n            int l = readi()+1, r = readi();\
    \ ll x = readl();\n            auto [a, b] = seg.query(l, r);\n            print(a\
    \ * x + b);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../ds/segment_tree.hpp\"\n#include \"../../math/mod.hpp\"\n\n// A(x) = ax+b,\
    \ B(x) = cx+d\n// B(A(x)) = c(ax+b)+d = acx + bc + d\nusing MI = ModInt<int, 998244353>;\n\
    using pm = pair<MI, MI>;\nstruct CompComp {\n    using Data = pm;\n    using Update\
    \ = pm;\n    const Data vdef = {1, 0};\n    Data merge(Data l, Data r) {\n   \
    \     auto [a, b] = l;\n        auto [c, d] = r;\n        return {a * c, b * c\
    \ + d};\n    }\n    void applyUpdate(Data &l, Update &r) { l = r; }\n};\n\nint\
    \ main() {\n    fast_io();\n    int N = readi(), Q = readi();\n    SegmentTree<CompComp>\
    \ seg; seg.init(N);\n    for (auto [i, v] : enumerate(readv<pll>(N), 1))\n   \
    \     seg.update(i, v);\n    while (Q--) {\n        if (readi() == 0) {\n    \
    \        int p = readi()+1, b = readi(), c = readi();\n            seg.update(p,\
    \ {b, c});\n        }\n        else {\n            int l = readi()+1, r = readi();\
    \ ll x = readl();\n            auto [a, b] = seg.query(l, r);\n            print(a\
    \ * x + b);\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - ds/segment_tree.hpp
  - math/mod.hpp
  - math/eea.hpp
  isVerificationFile: true
  path: tests/ds/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ds/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/ds/segment_tree.test.cpp
- /verify/tests/ds/segment_tree.test.cpp.html
title: tests/ds/segment_tree.test.cpp
---
