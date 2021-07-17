---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manachers.hpp
    title: string/manachers.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"tests/string/manachers.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
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
    \ return res;\n}\n\n#line 3 \"string/manachers.hpp\"\n\n/*\n * d[i] = Longest\
    \ odd-length palindrome centered at i.  Formally, largest value d[i] s.t. s[i-k]\
    \ == s[i+k] for all\n * 0<=k<d[i].\n *\n * This algorithm works almost identically\
    \ to z-algorithm.  For more information and explanation, see\n * string/z_algorithm.hpp\n\
    \ *\n * The key differences between the algorithms are: instead of 'shifting'\
    \ from i -> i-l when using precomputed values,\n * we instead flip across the\
    \ midpoint of rightmost palindrome substring we found to find our precomputed\
    \ value.\n * Additionally, we extend out in both directions instead of only forwards\
    \ as we are looking for palindromes.\n *\n * To find the longest palindromes for\
    \ even locations, add placeholders between each character.\n */\ntemplate <typename\
    \ Container> vector<int> manachers(int N, const Container &s) {\n    vector<int>\
    \ d(N);\n    int l = 0, r = -1;\n    for (int i = 0; i < N; i++) {\n        if\
    \ (i <= r) d[i] = min(r-i+1, d[l + r - i]); // flip across (l+r)/2\n        while\
    \ (0 <= i-d[i] && i+d[i] < N && s[i-d[i]] == s[i+d[i]]) d[i]++;\n        if (i+d[i]-1\
    \ > r) {\n            l = i-d[i]+1;\n            r = i+d[i]-1;\n        }\n  \
    \  }\n    return d;\n}\n#line 5 \"tests/string/manachers.test.cpp\"\n\nconst int\
    \ MN = 5e5 + 1;\nint N;\nstring s;\n\nint main() {\n    fast_io();\n\n    cin\
    \ >> s; N = s.length();\n    string t = \"$\";\n    for (int i = 0; i < N; i++)\
    \ {\n        t += s[i];\n        t += '$';\n    }\n\n    auto res = manachers(2*N+1,\
    \ t);\n    for (int i = 1; i < 2*N; i++)\n        cout << res[i]-1 << ' ';\n \
    \   cout << '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"\
    ../../string/manachers.hpp\"\n\nconst int MN = 5e5 + 1;\nint N;\nstring s;\n\n\
    int main() {\n    fast_io();\n\n    cin >> s; N = s.length();\n    string t =\
    \ \"$\";\n    for (int i = 0; i < N; i++) {\n        t += s[i];\n        t +=\
    \ '$';\n    }\n\n    auto res = manachers(2*N+1, t);\n    for (int i = 1; i <\
    \ 2*N; i++)\n        cout << res[i]-1 << ' ';\n    cout << '\\n';\n\n    return\
    \ 0;\n}"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - string/manachers.hpp
  isVerificationFile: true
  path: tests/string/manachers.test.cpp
  requiredBy: []
  timestamp: '2021-07-17 02:13:51-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/manachers.test.cpp
layout: document
redirect_from:
- /verify/tests/string/manachers.test.cpp
- /verify/tests/string/manachers.test.cpp.html
title: tests/string/manachers.test.cpp
---
