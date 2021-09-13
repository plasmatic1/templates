---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"tests/string/z_algorithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"template.hpp\"\n#include\
    \ <bits/stdc++.h>\n#define DEBUG 1\nusing namespace std;\n\n// Defines\n#define\
    \ fs first\n#define sn second\n#define pb push_back\n#define eb emplace_back\n\
    #define mpr make_pair\n#define mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    // Basic type definitions\n#if __cplusplus == 201703L // CPP17 only things\ntemplate\
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
    \ return res;\n}\n\n#line 3 \"string/z_algorithm.hpp\"\n\n/*\n * z[i] <- LCP(s[0..],\
    \ s[i..])\n *\n * Finding z[0..N-1] quickly relies on finding an estimation for\
    \ z[i] (that is less than the actual value), and\n * increasing it until it reaches\
    \ the correct value.  This works because z[i] stores the LCP of some strings,\
    \ so if z[i]\n * is a common prefix, then clearly z[i]-1 is one as well.\n *\n\
    \ * To do this, we maintain the rightmost interval [l = i, r = i+z[i]-1] and solve\
    \ for i-s sequentially.  At any point,\n * we have a few cases:\n *\n * (1) i\
    \ > r : We start our estimate of z[i] as 0, and extend\n * (2) i <= r : Also note\
    \ that in this case, l<=i<=r as we process i-s in order.  We know that s[l..r]\
    \ == s[0..r-l] as\n * it is an interval that is defined by [k, k+z[k]-1] (for\
    \ some k).  Thus, we use one of our previously computed values\n * to initialize\
    \ z[i].  In this case, we use min(z[i-l], r-i+1), which is when we shift the interval\
    \ [k, k+z[k]-1] to\n * [0, z[k]-1].\n *\n * Complexity Proof:\n *\n * (1) : We\
    \ are always extending r and since r<N, we will extend at most N times\n * (2)\
    \ :\n *   (2a) z[i-l] == r-i+1 : Again, we are extending r so this will happen\
    \ at most N times (combined with case 1)\n *   (2b) z[i-l] < r-i+1 : We will extend\
    \ 0 times, as if we could extend z[i], we could also extend z[i-l] as we know\n\
    \ *        that s[l..r] == s[0..r-l] (and we are still within that range, so the\
    \ extended character will be the same\n *        at both locations)\n *\n * Note:\
    \ while z[0] is technically undefined, we'll define it as N for now\n */\ntemplate\
    \ <typename Container> vector<int> z_algorithm(int N, const Container &s) {\n\
    \    vector<int> z(N); z[0] = N;\n    int l = 0, r = -1;\n    for (int i = 1;\
    \ i < N; i++) {\n        if (i <= r) z[i] = min(r-i+1, z[i-l]);\n        while\
    \ (i + z[i] < N && s[z[i]] == s[i + z[i]]) z[i]++;\n        if (i+z[i]-1 > r)\
    \ {\n            r = i+z[i]-1;\n            l = i;\n        }\n    }\n    return\
    \ z;\n}\n#line 5 \"tests/string/z_algorithm.test.cpp\"\n\nconst int MN = 5e5 +\
    \ 1;\nint N;\nstring s;\n\nint main() {\n    fast_io();\n\n    cin >> s; N = s.length();\n\
    \    for (auto x : z_algorithm(N, s))\n        cout << x << ' ';\n    cout <<\
    \ '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../string/z_algorithm.hpp\"\
    \n\nconst int MN = 5e5 + 1;\nint N;\nstring s;\n\nint main() {\n    fast_io();\n\
    \n    cin >> s; N = s.length();\n    for (auto x : z_algorithm(N, s))\n      \
    \  cout << x << ' ';\n    cout << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: tests/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/tests/string/z_algorithm.test.cpp
- /verify/tests/string/z_algorithm.test.cpp.html
title: tests/string/z_algorithm.test.cpp
---
