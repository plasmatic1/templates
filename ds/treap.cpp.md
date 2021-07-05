---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"ds/treap.cpp\"\n\
    \nmt19937 _mt_treap(04072020);\nuniform_int_distribution<int> _dis_treap(INT_MIN,\
    \ INT_MAX);\n\nstruct Node {\n    Node *l, *r;\n    int pri;\n\n    int sz;\n\
    \    ll val, sum;\n    Node(ll v0) : l(nullptr), r(nullptr), pri(_dis_treap(_mt_treap)),\
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
  code: "#pragma once\n#include \"../template.hpp\"\n\nmt19937 _mt_treap(04072020);\n\
    uniform_int_distribution<int> _dis_treap(INT_MIN, INT_MAX);\n\nstruct Node {\n\
    \    Node *l, *r;\n    int pri;\n\n    int sz;\n    ll val, sum;\n    Node(ll\
    \ v0) : l(nullptr), r(nullptr), pri(_dis_treap(_mt_treap)), sz(1), val(v0), sum(v0)\
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
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: ds/treap.cpp
  requiredBy: []
  timestamp: '2021-07-05 01:46:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/treap.cpp
layout: document
redirect_from:
- /library/ds/treap.cpp
- /library/ds/treap.cpp.html
title: ds/treap.cpp
---
