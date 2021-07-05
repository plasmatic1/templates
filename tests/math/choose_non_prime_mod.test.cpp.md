---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/eea.hpp
    title: math/eea.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
  bundledCode: "#line 1 \"tests/math/choose_non_prime_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n#line 2 \"template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n// Defines\n#define fs first\n\
    #define sn second\n#define pb push_back\n#define eb emplace_back\n#define mpr\
    \ make_pair\n#define mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n//\
    \ Basic type definitions\n#if __cplusplus == 201703L // CPP17 only things\ntemplate\
    \ <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates\n\
    #endif\nusing ll = long long; using ull = unsigned long long; using ld = long\
    \ double;\nusing pii = pair<int, int>; using pll = pair<long long, long long>;\n\
    #ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
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
    \ return res;\n}\n#line 5 \"tests/math/choose_non_prime_mod.test.cpp\"\n\nint\
    \ main() {\n    fast_io();\n\n    int T, m;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\
    #include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../math/eea.hpp\"\
    \n\nint main() {\n    fast_io();\n\n    int T, m;\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - math/eea.hpp
  isVerificationFile: true
  path: tests/math/choose_non_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2021-07-05 01:37:57-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/math/choose_non_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/tests/math/choose_non_prime_mod.test.cpp
- /verify/tests/math/choose_non_prime_mod.test.cpp.html
title: tests/math/choose_non_prime_mod.test.cpp
---
