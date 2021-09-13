---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/li_chao_tree.hpp
    title: ds/li_chao_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"tests/ds/li_chao_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
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
    \ return res;\n}\n\n#line 1 \"ds/li_chao_tree.hpp\"\ntemplate <typename T> struct\
    \ Line {\n    T m, b;\n    Line(T m0, T b0) : m(m0), b(b0) {}\n    T eval(T x)\
    \ { return x * m + b; }\n};\ntemplate <typename T, ll MINX = (ll)-1e6, ll MAXX\
    \ = (ll)1e6> struct LiChaoTree { // Just *-1 if you want to do max lol\n    using\
    \ line = Line<T>;\n    struct Node {\n        Node *l = nullptr, *r = nullptr;\n\
    \        line val{0, LLINF};\n        Node(Node *l0, Node *r0, line v0) : l(l0),\
    \ r(r0), val(v0) {}\n    };\n    Node *rt = nullptr;\n    void _insert(line ln,\
    \ Node *&n, ll l, ll r) {\n        if (l > r) return;\n        if (!n) {\n   \
    \         n = new Node(nullptr, nullptr, ln);\n            return;\n        }\n\
    \        ll mid = (l + r) / 2;\n        bool lDom = ln.eval(l) < n->val.eval(l),\
    \ mDom = ln.eval(mid) < n->val.eval(mid);\n        if (mDom) swap(ln, n->val);\n\
    \        if (l == r) return; // base case\n        if (lDom != mDom) _insert(ln,\
    \ n->l, l, mid);\n        else _insert(ln, n->r, mid + 1, r);\n    }\n    ll _query(ll\
    \ x, Node *n, ll l, ll r) {\n        if (!n) return LLINF;\n        ll res = n->val.eval(x),\
    \ mid = (l + r) / 2;\n        if (l != r) {\n            if (x < mid) res = min(res,\
    \ _query(x, n->l, l, mid));\n            else res = min(res, _query(x, n->r, mid\
    \ + 1, r));\n        }\n        return res;\n    }\n    void insert(line ln) {\
    \ _insert(ln, rt, MINX, MAXX); }\n    ll query(ll x) { return _query(x, rt, MINX,\
    \ MAXX); }\n};\n#line 5 \"tests/ds/li_chao_tree.test.cpp\"\n\nint main() {\n \
    \   fast_io();\n    int N = readi(), Q = readi();\n    LiChaoTree<ll, -ll(1e9),\
    \ ll(1e9)> li;\n    for (auto [m, b] : readv<pll>(N))\n        li.insert({m, b});\n\
    \    while (Q--) {\n        if (readi() == 0) {\n            ll a = readl(), b\
    \ = readl();\n            li.insert({a, b});\n        }\n        else {\n    \
    \        int p = readi();\n            print(li.query(p));\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../ds/li_chao_tree.hpp\"\
    \n\nint main() {\n    fast_io();\n    int N = readi(), Q = readi();\n    LiChaoTree<ll,\
    \ -ll(1e9), ll(1e9)> li;\n    for (auto [m, b] : readv<pll>(N))\n        li.insert({m,\
    \ b});\n    while (Q--) {\n        if (readi() == 0) {\n            ll a = readl(),\
    \ b = readl();\n            li.insert({a, b});\n        }\n        else {\n  \
    \          int p = readi();\n            print(li.query(p));\n        }\n    }\n\
    }\n"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - ds/li_chao_tree.hpp
  isVerificationFile: true
  path: tests/ds/li_chao_tree.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ds/li_chao_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/ds/li_chao_tree.test.cpp
- /verify/tests/ds/li_chao_tree.test.cpp.html
title: tests/ds/li_chao_tree.test.cpp
---
