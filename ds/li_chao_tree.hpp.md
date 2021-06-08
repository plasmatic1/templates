---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ds/li_chao_tree.test.cpp
    title: tests/ds/li_chao_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/li_chao_tree.hpp\"\ntemplate <typename T> struct Line\
    \ {\n    T m, b;\n    Line(T m0, T b0) : m(m0), b(b0) {}\n    T eval(T x) { return\
    \ x * m + b; }\n};\ntemplate <typename T, ll MINX = (ll)-1e6, ll MAXX = (ll)1e6>\
    \ struct LiChaoTree { // Just *-1 if you want to do max lol\n    using line =\
    \ Line<T>;\n    struct Node {\n        Node *l = nullptr, *r = nullptr;\n    \
    \    line val{0, LLINF};\n        Node(Node *l0, Node *r0, line v0) : l(l0), r(r0),\
    \ val(v0) {}\n    };\n    Node *rt = nullptr;\n    void _insert(line ln, Node\
    \ *&n, ll l, ll r) {\n        if (l > r) return;\n        if (!n) {\n        \
    \    n = new Node(nullptr, nullptr, ln);\n            return;\n        }\n   \
    \     ll mid = (l + r) / 2;\n        bool lDom = ln.eval(l) < n->val.eval(l),\
    \ mDom = ln.eval(mid) < n->val.eval(mid);\n        if (mDom) swap(ln, n->val);\n\
    \        if (l == r) return; // base case\n        if (lDom != mDom) _insert(ln,\
    \ n->l, l, mid);\n        else _insert(ln, n->r, mid + 1, r);\n    }\n    ll _query(ll\
    \ x, Node *n, ll l, ll r) {\n        if (!n) return LLINF;\n        ll res = n->val.eval(x),\
    \ mid = (l + r) / 2;\n        if (l != r) {\n            if (x < mid) res = min(res,\
    \ _query(x, n->l, l, mid));\n            else res = min(res, _query(x, n->r, mid\
    \ + 1, r));\n        }\n        return res;\n    }\n    void insert(line ln) {\
    \ _insert(ln, rt, MINX, MAXX); }\n    ll query(ll x) { return _query(x, rt, MINX,\
    \ MAXX); }\n};\n"
  code: "template <typename T> struct Line {\n    T m, b;\n    Line(T m0, T b0) :\
    \ m(m0), b(b0) {}\n    T eval(T x) { return x * m + b; }\n};\ntemplate <typename\
    \ T, ll MINX = (ll)-1e6, ll MAXX = (ll)1e6> struct LiChaoTree { // Just *-1 if\
    \ you want to do max lol\n    using line = Line<T>;\n    struct Node {\n     \
    \   Node *l = nullptr, *r = nullptr;\n        line val{0, LLINF};\n        Node(Node\
    \ *l0, Node *r0, line v0) : l(l0), r(r0), val(v0) {}\n    };\n    Node *rt = nullptr;\n\
    \    void _insert(line ln, Node *&n, ll l, ll r) {\n        if (l > r) return;\n\
    \        if (!n) {\n            n = new Node(nullptr, nullptr, ln);\n        \
    \    return;\n        }\n        ll mid = (l + r) / 2;\n        bool lDom = ln.eval(l)\
    \ < n->val.eval(l), mDom = ln.eval(mid) < n->val.eval(mid);\n        if (mDom)\
    \ swap(ln, n->val);\n        if (l == r) return; // base case\n        if (lDom\
    \ != mDom) _insert(ln, n->l, l, mid);\n        else _insert(ln, n->r, mid + 1,\
    \ r);\n    }\n    ll _query(ll x, Node *n, ll l, ll r) {\n        if (!n) return\
    \ LLINF;\n        ll res = n->val.eval(x), mid = (l + r) / 2;\n        if (l !=\
    \ r) {\n            if (x < mid) res = min(res, _query(x, n->l, l, mid));\n  \
    \          else res = min(res, _query(x, n->r, mid + 1, r));\n        }\n    \
    \    return res;\n    }\n    void insert(line ln) { _insert(ln, rt, MINX, MAXX);\
    \ }\n    ll query(ll x) { return _query(x, rt, MINX, MAXX); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-06-07 23:09:50-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ds/li_chao_tree.test.cpp
documentation_of: ds/li_chao_tree.hpp
layout: document
redirect_from:
- /library/ds/li_chao_tree.hpp
- /library/ds/li_chao_tree.hpp.html
title: ds/li_chao_tree.hpp
---
