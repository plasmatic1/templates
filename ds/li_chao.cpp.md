---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/li_chao.cpp\"\ntemplate <typename T> struct Line {\n\
    \    T m, b;\n    Line(T m0, T b0) : m(m0), b(b0) {}\n    T eval(T x) { return\
    \ x * m + b; }\n};\nusing line = Line<ll>; // Define!!!\nconst ll MINX = -1e6,\
    \ MAXX = 1e6; // Define!!!\nstruct LiChao { // Just *-1 if you want to do max\
    \ lol\n    struct Node {\n        Node *l = nullptr, *r = nullptr;\n        line\
    \ val{0, LLINF};\n        Node(Node *l0, Node *r0, line v0) : l(l0), r(r0), val(v0)\
    \ {}\n    };\n    Node *rt = nullptr;\n    void _insert(line ln, Node *&n, ll\
    \ l, ll r) {\n        if (l > r) return;\n        if (!n) {\n            n = new\
    \ Node(nullptr, nullptr, ln);\n            return;\n        }\n        ll mid\
    \ = (l + r) / 2;\n        bool lDom = ln.eval(l) < n->val.eval(l), mDom = ln.eval(mid)\
    \ < n->val.eval(mid);\n        if (mDom) swap(ln, n->val);\n        if (l == r)\
    \ return; // base case\n        if (lDom != mDom) _insert(ln, n->l, l, mid);\n\
    \        else _insert(ln, n->r, mid + 1, r);\n    }\n    void insert(line ln)\
    \ { _insert(ln, rt, MINX, MAXX); }\n    ll _query(ll x, Node *n, ll l, ll r) {\n\
    \        if (!n) return LLINF;\n        ll res = n->val.eval(x), mid = (l + r)\
    \ / 2;\n        if (l != r) {\n            if (x < mid) res = min(res, _query(x,\
    \ n->l, l, mid));\n            else res = min(res, _query(x, n->r, mid + 1, r));\n\
    \        }\n        return res;\n    }\n    ll query(ll x) { return _query(x,\
    \ rt, MINX, MAXX); }\n};\n\n\n"
  code: "template <typename T> struct Line {\n    T m, b;\n    Line(T m0, T b0) :\
    \ m(m0), b(b0) {}\n    T eval(T x) { return x * m + b; }\n};\nusing line = Line<ll>;\
    \ // Define!!!\nconst ll MINX = -1e6, MAXX = 1e6; // Define!!!\nstruct LiChao\
    \ { // Just *-1 if you want to do max lol\n    struct Node {\n        Node *l\
    \ = nullptr, *r = nullptr;\n        line val{0, LLINF};\n        Node(Node *l0,\
    \ Node *r0, line v0) : l(l0), r(r0), val(v0) {}\n    };\n    Node *rt = nullptr;\n\
    \    void _insert(line ln, Node *&n, ll l, ll r) {\n        if (l > r) return;\n\
    \        if (!n) {\n            n = new Node(nullptr, nullptr, ln);\n        \
    \    return;\n        }\n        ll mid = (l + r) / 2;\n        bool lDom = ln.eval(l)\
    \ < n->val.eval(l), mDom = ln.eval(mid) < n->val.eval(mid);\n        if (mDom)\
    \ swap(ln, n->val);\n        if (l == r) return; // base case\n        if (lDom\
    \ != mDom) _insert(ln, n->l, l, mid);\n        else _insert(ln, n->r, mid + 1,\
    \ r);\n    }\n    void insert(line ln) { _insert(ln, rt, MINX, MAXX); }\n    ll\
    \ _query(ll x, Node *n, ll l, ll r) {\n        if (!n) return LLINF;\n       \
    \ ll res = n->val.eval(x), mid = (l + r) / 2;\n        if (l != r) {\n       \
    \     if (x < mid) res = min(res, _query(x, n->l, l, mid));\n            else\
    \ res = min(res, _query(x, n->r, mid + 1, r));\n        }\n        return res;\n\
    \    }\n    ll query(ll x) { return _query(x, rt, MINX, MAXX); }\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/li_chao.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/li_chao.cpp
layout: document
redirect_from:
- /library/ds/li_chao.cpp
- /library/ds/li_chao.cpp.html
title: ds/li_chao.cpp
---
