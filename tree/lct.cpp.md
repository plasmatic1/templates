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
  bundledCode: "#line 1 \"tree/lct.cpp\"\n\nstruct Node {\n    Node *p, *ch[2];\n\
    \    int sz; bool rev;\n    // aux\n    int val, sum, max, min;\n    // lazy\n\
    \    bool isLazySet;\n    int lazySet, lazyInc;\n    Node(int val0) {\n      \
    \  sz = 1; rev = false;\n        p = ch[0] = ch[1] = nullptr;\n        val = sum\
    \ = max = min = val0;\n        lazySet = lazyInc = 0;\n        isLazySet = false;\n\
    \    }\n    void prop(Node *c) {\n        if (c) {\n            if (isLazySet)\
    \ {\n                c->isLazySet = true;\n                c->lazySet = lazySet;\n\
    \                c->lazyInc = 0;\n            }\n            if (lazyInc != 0)\
    \ {\n                c->lazyInc += lazyInc;\n            }\n            if (rev)\n\
    \                c->rev ^= 1;\n        }\n    }\n    void apply() {\n        if\
    \ (isLazySet) {\n            max = min = val = lazySet;\n            sum = lazySet\
    \ * sz;\n        }\n        if (lazyInc != 0) {\n            max += lazyInc;\n\
    \            min += lazyInc;\n            sum += sz * lazyInc;\n            val\
    \ += lazyInc;\n        }\n        if (rev) {\n            swap(ch[0], ch[1]);\n\
    \        }\n    }\n};\n#define FUN(type, x, def) type n##x(Node *n) { return n\
    \ ? n->x : def; }\nFUN(int, sum, 0) FUN(int, max, INT_MIN) FUN(int, min, INT_MAX)\
    \ FUN(int, sz, 0)\nbool side(Node *n) { return n->p ? n == n->p->ch[1] : false;\
    \ }\nbool isrt(Node *n) { return n->p ? n != n->p->ch[side(n)] : true; }\nvoid\
    \ setp(Node *n, Node *p) { if (n) n->p = p; }\nvoid setc(Node *n, Node *c, bool\
    \ dir) { if (n) { n->ch[dir] = c; setp(c, n); }}\n\nvoid push(Node *n) {\n   \
    \ if (n) {\n        n->apply();\n        n->prop(n->ch[0]); n->prop(n->ch[1]);\n\
    \n        n->isLazySet = false;\n        n->lazyInc = 0;\n        n->rev = false;\n\
    \    }\n}\nvoid upd(Node *n) {\n    if (n) {\n        push(n->ch[0]); push(n->ch[1]);\n\
    \n        n->sum = nsum(n->ch[0]) + nsum(n->ch[1]) + n->val;\n        n->max =\
    \ max({nmax(n->ch[0]), nmax(n->ch[1]), n->val});\n        n->min = min({nmin(n->ch[0]),\
    \ nmin(n->ch[1]), n->val});\n        n->sz = nsz(n->ch[0]) + nsz(n->ch[1]) + 1;\n\
    \    }\n}\nvoid rot(Node *n) { \n    push(n->p); push(n);\n    bool ndir = side(n),\
    \ pdir = side(n->p);\n    Node *p = n->p, *d = n->ch[!ndir], *pp = p->p;\n   \
    \ if (isrt(p)) setp(n, pp); else setc(pp, n, pdir); setc(p, d, ndir); setc(n,\
    \ p, !ndir);\n    upd(p); upd(n);\n}\nvoid splay(Node *n) {\n    while (n && !isrt(n))\
    \ {\n        if (!isrt(n->p)) {\n            if (side(n) == side(n->p)) { rot(n->p);\
    \ rot(n); }\n            else { rot(n); rot(n); }\n        }\n        else rot(n);\n\
    \    }\n    push(n);\n}\nvoid access(Node *n) {\n    for (Node *c = n, *pre =\
    \ nullptr; c; c = c->p) {\n        splay(c); c->ch[1] = pre; upd(c);\n       \
    \ pre = c;\n    }\n    splay(n);\n}\n\nvoid reroot(Node *n) {\n    access(n);\
    \ n->rev ^= 1; push(n);\n}\nvoid link(Node *u, Node *v) {\n    reroot(v); access(u);\n\
    \    setc(v, u, 0); upd(v);\n}\nNode* path(Node *u, Node *v) {\n    reroot(u);\
    \ access(v);\n    // db(v->val); db(v->sum); db(v->max); db(v->min); db(v->lazyInc);\
    \ db(v->lazySet); db(v->rev); dbln;\n    return v;\n}\nNode* lca(Node *u, Node\
    \ *v) {\n    access(u); access(v); splay(u);\n    // db(u); db(v); db(u->p); dbln;\n\
    \    return u->p ? u->p : u;\n}\nvoid cut(Node *n) {\n    access(n);\n    setp(n->ch[0],\
    \ nullptr); setc(n, nullptr, 0); upd(n);\n}\n\nNode *lct[MN];\n"
  code: "\nstruct Node {\n    Node *p, *ch[2];\n    int sz; bool rev;\n    // aux\n\
    \    int val, sum, max, min;\n    // lazy\n    bool isLazySet;\n    int lazySet,\
    \ lazyInc;\n    Node(int val0) {\n        sz = 1; rev = false;\n        p = ch[0]\
    \ = ch[1] = nullptr;\n        val = sum = max = min = val0;\n        lazySet =\
    \ lazyInc = 0;\n        isLazySet = false;\n    }\n    void prop(Node *c) {\n\
    \        if (c) {\n            if (isLazySet) {\n                c->isLazySet\
    \ = true;\n                c->lazySet = lazySet;\n                c->lazyInc =\
    \ 0;\n            }\n            if (lazyInc != 0) {\n                c->lazyInc\
    \ += lazyInc;\n            }\n            if (rev)\n                c->rev ^=\
    \ 1;\n        }\n    }\n    void apply() {\n        if (isLazySet) {\n       \
    \     max = min = val = lazySet;\n            sum = lazySet * sz;\n        }\n\
    \        if (lazyInc != 0) {\n            max += lazyInc;\n            min +=\
    \ lazyInc;\n            sum += sz * lazyInc;\n            val += lazyInc;\n  \
    \      }\n        if (rev) {\n            swap(ch[0], ch[1]);\n        }\n   \
    \ }\n};\n#define FUN(type, x, def) type n##x(Node *n) { return n ? n->x : def;\
    \ }\nFUN(int, sum, 0) FUN(int, max, INT_MIN) FUN(int, min, INT_MAX) FUN(int, sz,\
    \ 0)\nbool side(Node *n) { return n->p ? n == n->p->ch[1] : false; }\nbool isrt(Node\
    \ *n) { return n->p ? n != n->p->ch[side(n)] : true; }\nvoid setp(Node *n, Node\
    \ *p) { if (n) n->p = p; }\nvoid setc(Node *n, Node *c, bool dir) { if (n) { n->ch[dir]\
    \ = c; setp(c, n); }}\n\nvoid push(Node *n) {\n    if (n) {\n        n->apply();\n\
    \        n->prop(n->ch[0]); n->prop(n->ch[1]);\n\n        n->isLazySet = false;\n\
    \        n->lazyInc = 0;\n        n->rev = false;\n    }\n}\nvoid upd(Node *n)\
    \ {\n    if (n) {\n        push(n->ch[0]); push(n->ch[1]);\n\n        n->sum =\
    \ nsum(n->ch[0]) + nsum(n->ch[1]) + n->val;\n        n->max = max({nmax(n->ch[0]),\
    \ nmax(n->ch[1]), n->val});\n        n->min = min({nmin(n->ch[0]), nmin(n->ch[1]),\
    \ n->val});\n        n->sz = nsz(n->ch[0]) + nsz(n->ch[1]) + 1;\n    }\n}\nvoid\
    \ rot(Node *n) { \n    push(n->p); push(n);\n    bool ndir = side(n), pdir = side(n->p);\n\
    \    Node *p = n->p, *d = n->ch[!ndir], *pp = p->p;\n    if (isrt(p)) setp(n,\
    \ pp); else setc(pp, n, pdir); setc(p, d, ndir); setc(n, p, !ndir);\n    upd(p);\
    \ upd(n);\n}\nvoid splay(Node *n) {\n    while (n && !isrt(n)) {\n        if (!isrt(n->p))\
    \ {\n            if (side(n) == side(n->p)) { rot(n->p); rot(n); }\n         \
    \   else { rot(n); rot(n); }\n        }\n        else rot(n);\n    }\n    push(n);\n\
    }\nvoid access(Node *n) {\n    for (Node *c = n, *pre = nullptr; c; c = c->p)\
    \ {\n        splay(c); c->ch[1] = pre; upd(c);\n        pre = c;\n    }\n    splay(n);\n\
    }\n\nvoid reroot(Node *n) {\n    access(n); n->rev ^= 1; push(n);\n}\nvoid link(Node\
    \ *u, Node *v) {\n    reroot(v); access(u);\n    setc(v, u, 0); upd(v);\n}\nNode*\
    \ path(Node *u, Node *v) {\n    reroot(u); access(v);\n    // db(v->val); db(v->sum);\
    \ db(v->max); db(v->min); db(v->lazyInc); db(v->lazySet); db(v->rev); dbln;\n\
    \    return v;\n}\nNode* lca(Node *u, Node *v) {\n    access(u); access(v); splay(u);\n\
    \    // db(u); db(v); db(u->p); dbln;\n    return u->p ? u->p : u;\n}\nvoid cut(Node\
    \ *n) {\n    access(n);\n    setp(n->ch[0], nullptr); setc(n, nullptr, 0); upd(n);\n\
    }\n\nNode *lct[MN];\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lct.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/lct.cpp
layout: document
redirect_from:
- /library/tree/lct.cpp
- /library/tree/lct.cpp.html
title: tree/lct.cpp
---
