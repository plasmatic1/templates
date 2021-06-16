---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table.hpp
    title: ds/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://en.cppreference.com/w/cpp/language/eval_order
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"tests/ds/sparse_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
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
    \ return res;\n}\n\n#line 3 \"ds/sparse_table.hpp\"\n\n// Sparse table is 1-indexed\n\
    // Comparator for range MIN query\n// When calling init, st should point to the\
    \ start (0-indexed).  (i.e. if you stored data in A[1], A[2], ..., you should\
    \ call init with (A+1, A+N+1)\n// However, queries are 1-indexed and inclusive\n\
    struct Comp {\n    using Data = int;\n    Data merge(Data a, Data b) { return\
    \ min(a, b); }\n};\ntemplate <class Comp> struct SparseTable {\n    using Data\
    \ = typename Comp::Data; Comp C;\n    vector<vector<Data>> tb;\n    int N, lg;\n\
    \    template <typename It> void init(It st, It end) {\n        N = end-st; lg\
    \ = __lg(N);\n        tb.assign(lg+1, vector<Data>(N+1));\n        copy(st, end,\
    \ tb[0].begin()+1);\n        for (auto i = 1; i <= lg; i++) {\n            int\
    \ jmp = 1 << (i-1), end = N - (1<<i) + 1;\n            for (auto j = 1; j <= end;\
    \ j++)\n                tb[i][j] = C.merge(tb[i-1][j], tb[i-1][j+jmp]);\n    \
    \    }\n    }\n    Data query(int l, int r) {\n        int bit = __lg(r-l+1);\n\
    \        return C.merge(tb[bit][l], tb[bit][r-(1<<bit)+1]);\n    }\n};\n\n#line\
    \ 5 \"tests/ds/sparse_table.test.cpp\"\n\nint main() {\n    fast_io();\n    int\
    \ N = readi(), Q = readi();\n    auto v = readv<int>(N);\n    SparseTable<Comp>\
    \ st; st.init(v.begin(), v.end());\n    while (Q--) {\n        int l = readi()+1,\
    \ r = readi(); // https://en.cppreference.com/w/cpp/language/eval_order\n    \
    \    print(st.query(l, r));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../ds/sparse_table.hpp\"\
    \n\nint main() {\n    fast_io();\n    int N = readi(), Q = readi();\n    auto\
    \ v = readv<int>(N);\n    SparseTable<Comp> st; st.init(v.begin(), v.end());\n\
    \    while (Q--) {\n        int l = readi()+1, r = readi(); // https://en.cppreference.com/w/cpp/language/eval_order\n\
    \        print(st.query(l, r));\n    }\n}\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - ds/sparse_table.hpp
  isVerificationFile: true
  path: tests/ds/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ds/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/tests/ds/sparse_table.test.cpp
- /verify/tests/ds/sparse_table.test.cpp.html
title: tests/ds/sparse_table.test.cpp
---
