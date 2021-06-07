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
  bundledCode: "#line 1 \"ds/treap.cpp\"\n\nmt19937 mt(04072020);\nuniform_int_distribution<int>\
    \ dis(INT_MIN, INT_MAX);\n\nstruct Node {\n    Node *l, *r;\n    int pri;\n\n\
    \    int sz;\n    ll val, sum;\n    Node(ll v0) : l(nullptr), r(nullptr), pri(dis(mt)),\
    \ sz(1), val(v0), sum(v0) {}\n};\n\nint sz(Node *n) { return n ? n->sz : 0; }\n\
    ll sum(Node *n) { return n ? n->sum : 0; }\nvoid push(Node *n) {\n    if (n) {\n\
    \n    }\n}\nvoid upd(Node *n) {\n    push(n->l); push(n->r);\n    if (n) {\n \
    \       n->sz = sz(n->l) + sz(n->r) + 1;\n        n->sum = sum(n->l) + sum(n->r)\
    \ + n->val;\n    }\n}\nconst bool VAL = 0, IDX = 1;\n// type=0->val, type=1->idx\n\
    void split(Node *n, bool type, ll key, Node *&l, Node *&r) {\n    if (!n) return\
    \ void(l = r = nullptr);\n    push(n);\n    int rm = sz(n->l) + 1;\n    if ((type\
    \ == VAL && n->val <= key) || (type == IDX && rm <= key)) { split(n->r, type,\
    \ key - (type * rm), n->r, r); l = n; }\n    else { split(n->l, type, key, l,\
    \ n->l); r = n; }\n    upd(n);\n}\nvoid merge(Node *&n, Node *l, Node *r) {\n\
    \    push(l); push(r);\n    if (!l || !r) n = l ? l : r;\n    else if (l->pri\
    \ > r->pri) { merge(l->r, l->r, r); n = l; }\n    else { merge(r->l, l, r->l);\
    \ n = r; }\n    upd(n);\n}\n\n// debug\nvoid io(Node *n) {\n    if(!n)return;io(n->l);cout<<n->val<<\"\
    , \";io(n->r);\n}\n#define PS(n) do{cout<<(#n)<<\": [\";io(n);cout<<\"]\"<<endl;}while(0)\n\
    \nvoid ins(Node *&rt, ll x) {\n    Node *tmp;\n    split(rt, VAL, x, rt, tmp);\n\
    \    merge(rt, rt, new Node(x));\n    merge(rt, rt, tmp);\n}\nvoid rem(Node *&rt,\
    \ ll x) {\n    if (rt->val == x) merge(rt, rt->l, rt->r);\n    else rem(x > rt->val\
    \ ? rt->r : rt->l, x);\n    upd(rt);\n}\n\nll over(Node *n, ll x) {\n    if (!n)\
    \ return LLINF;\n    push(n);\n    if (n->val > x) return min(n->val, over(n->l,\
    \ x));\n    return over(n->r, x);\n}\n\n"
  code: "\nmt19937 mt(04072020);\nuniform_int_distribution<int> dis(INT_MIN, INT_MAX);\n\
    \nstruct Node {\n    Node *l, *r;\n    int pri;\n\n    int sz;\n    ll val, sum;\n\
    \    Node(ll v0) : l(nullptr), r(nullptr), pri(dis(mt)), sz(1), val(v0), sum(v0)\
    \ {}\n};\n\nint sz(Node *n) { return n ? n->sz : 0; }\nll sum(Node *n) { return\
    \ n ? n->sum : 0; }\nvoid push(Node *n) {\n    if (n) {\n\n    }\n}\nvoid upd(Node\
    \ *n) {\n    push(n->l); push(n->r);\n    if (n) {\n        n->sz = sz(n->l) +\
    \ sz(n->r) + 1;\n        n->sum = sum(n->l) + sum(n->r) + n->val;\n    }\n}\n\
    const bool VAL = 0, IDX = 1;\n// type=0->val, type=1->idx\nvoid split(Node *n,\
    \ bool type, ll key, Node *&l, Node *&r) {\n    if (!n) return void(l = r = nullptr);\n\
    \    push(n);\n    int rm = sz(n->l) + 1;\n    if ((type == VAL && n->val <= key)\
    \ || (type == IDX && rm <= key)) { split(n->r, type, key - (type * rm), n->r,\
    \ r); l = n; }\n    else { split(n->l, type, key, l, n->l); r = n; }\n    upd(n);\n\
    }\nvoid merge(Node *&n, Node *l, Node *r) {\n    push(l); push(r);\n    if (!l\
    \ || !r) n = l ? l : r;\n    else if (l->pri > r->pri) { merge(l->r, l->r, r);\
    \ n = l; }\n    else { merge(r->l, l, r->l); n = r; }\n    upd(n);\n}\n\n// debug\n\
    void io(Node *n) {\n    if(!n)return;io(n->l);cout<<n->val<<\", \";io(n->r);\n\
    }\n#define PS(n) do{cout<<(#n)<<\": [\";io(n);cout<<\"]\"<<endl;}while(0)\n\n\
    void ins(Node *&rt, ll x) {\n    Node *tmp;\n    split(rt, VAL, x, rt, tmp);\n\
    \    merge(rt, rt, new Node(x));\n    merge(rt, rt, tmp);\n}\nvoid rem(Node *&rt,\
    \ ll x) {\n    if (rt->val == x) merge(rt, rt->l, rt->r);\n    else rem(x > rt->val\
    \ ? rt->r : rt->l, x);\n    upd(rt);\n}\n\nll over(Node *n, ll x) {\n    if (!n)\
    \ return LLINF;\n    push(n);\n    if (n->val > x) return min(n->val, over(n->l,\
    \ x));\n    return over(n->r, x);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/treap.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/treap.cpp
layout: document
redirect_from:
- /library/ds/treap.cpp
- /library/ds/treap.cpp.html
title: ds/treap.cpp
---
