---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/hash_utils.hpp
    title: string/hash_utils.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"tests/string/hash_utils.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \ return res;\n}\n\n#line 3 \"string/hash_utils.hpp\"\n\n// Hashing stuff\nconst\
    \ int FIXED_BASE = 0, RAND_BASE = 1 << 0;\nconst ll MOD = 999999999999999989;\n\
    ll BASE = 131;\n\nvector<ll> _hash_pows;\ntemplate <int MODE> void init_hash(int\
    \ MAX_N) {\n    if (MODE & RAND_BASE) {\n        mt19937 mt(RANDOM);\n       \
    \ BASE = uniform_int_distribution<ll>(MOD/2, MOD-2)(mt);\n    }\n\n    _hash_pows.resize(MAX_N\
    \ + 1);\n    _hash_pows[0] = 1LL;\n    for (auto i = 1; i <= MAX_N; i++)\n   \
    \     _hash_pows[i] = __int128(_hash_pows[i - 1]) * BASE % MOD;\n}\ntemplate <typename\
    \ It> ll hget(It hs, int l, int r) {\n    __int128 res = (hs[r] - __int128(hs[l\
    \ - 1]) * _hash_pows[r - l + 1]) % MOD;\n    if (res < 0) res += MOD;\n    return\
    \ res;\n}\nll happend(ll hsh, int val) { return (__int128(hsh) * BASE + val) %\
    \ MOD; }\nll hconcat(ll hshLeft, ll hshRight, int szRight) { return (__int128(hshLeft)\
    \ * _hash_pows[szRight] + hshRight) % MOD; }\n#line 5 \"tests/string/hash_utils.test.cpp\"\
    \n\nconst int MN = 5e5 + 1;\nint N;\nstring s;\nll hs[MN];\n\nint main() {\n \
    \   fast_io();\n    init_hash<RAND_BASE>(MN);\n\n    cin >> s; N = s.length();\n\
    \n    for (int i = 1; i <= N; i++)\n        hs[i] = happend(hs[i-1], s[i-1]);\n\
    \    for (int i = 1; i <= N; i++) {\n        int l = 0, r = N-i+1, ans = 0;\n\
    \        while (l <= r) {\n            int mid = (l + r) / 2;\n            if\
    \ (hget(hs, i, i+mid-1) == hget(hs, 1, mid)) {\n                l = mid+1;\n \
    \               ans = mid;\n            }\n            else r = mid-1;\n     \
    \   }\n\n        cout << ans << ' ';\n    }\n    cout << '\\n';\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../string/hash_utils.hpp\"\
    \n\nconst int MN = 5e5 + 1;\nint N;\nstring s;\nll hs[MN];\n\nint main() {\n \
    \   fast_io();\n    init_hash<RAND_BASE>(MN);\n\n    cin >> s; N = s.length();\n\
    \n    for (int i = 1; i <= N; i++)\n        hs[i] = happend(hs[i-1], s[i-1]);\n\
    \    for (int i = 1; i <= N; i++) {\n        int l = 0, r = N-i+1, ans = 0;\n\
    \        while (l <= r) {\n            int mid = (l + r) / 2;\n            if\
    \ (hget(hs, i, i+mid-1) == hget(hs, 1, mid)) {\n                l = mid+1;\n \
    \               ans = mid;\n            }\n            else r = mid-1;\n     \
    \   }\n\n        cout << ans << ' ';\n    }\n    cout << '\\n';\n\n    return\
    \ 0;\n}"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - string/hash_utils.hpp
  isVerificationFile: true
  path: tests/string/hash_utils.test.cpp
  requiredBy: []
  timestamp: '2022-01-04 15:14:59-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/hash_utils.test.cpp
layout: document
redirect_from:
- /verify/tests/string/hash_utils.test.cpp
- /verify/tests/string/hash_utils.test.cpp.html
title: tests/string/hash_utils.test.cpp
---
