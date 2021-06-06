
struct Node {
    Node *p, *ch[2];
    int sz; bool rev;
    // aux
    int val, sum, max, min;
    // lazy
    bool isLazySet;
    int lazySet, lazyInc;
    Node(int val0) {
        sz = 1; rev = false;
        p = ch[0] = ch[1] = nullptr;
        val = sum = max = min = val0;
        lazySet = lazyInc = 0;
        isLazySet = false;
    }
    void prop(Node *c) {
        if (c) {
            if (isLazySet) {
                c->isLazySet = true;
                c->lazySet = lazySet;
                c->lazyInc = 0;
            }
            if (lazyInc != 0) {
                c->lazyInc += lazyInc;
            }
            if (rev)
                c->rev ^= 1;
        }
    }
    void apply() {
        if (isLazySet) {
            max = min = val = lazySet;
            sum = lazySet * sz;
        }
        if (lazyInc != 0) {
            max += lazyInc;
            min += lazyInc;
            sum += sz * lazyInc;
            val += lazyInc;
        }
        if (rev) {
            swap(ch[0], ch[1]);
        }
    }
};
#define FUN(type, x, def) type n##x(Node *n) { return n ? n->x : def; }
FUN(int, sum, 0) FUN(int, max, INT_MIN) FUN(int, min, INT_MAX) FUN(int, sz, 0)
bool side(Node *n) { return n->p ? n == n->p->ch[1] : false; }
bool isrt(Node *n) { return n->p ? n != n->p->ch[side(n)] : true; }
void setp(Node *n, Node *p) { if (n) n->p = p; }
void setc(Node *n, Node *c, bool dir) { if (n) { n->ch[dir] = c; setp(c, n); }}

void push(Node *n) {
    if (n) {
        n->apply();
        n->prop(n->ch[0]); n->prop(n->ch[1]);

        n->isLazySet = false;
        n->lazyInc = 0;
        n->rev = false;
    }
}
void upd(Node *n) {
    if (n) {
        push(n->ch[0]); push(n->ch[1]);

        n->sum = nsum(n->ch[0]) + nsum(n->ch[1]) + n->val;
        n->max = max({nmax(n->ch[0]), nmax(n->ch[1]), n->val});
        n->min = min({nmin(n->ch[0]), nmin(n->ch[1]), n->val});
        n->sz = nsz(n->ch[0]) + nsz(n->ch[1]) + 1;
    }
}
void rot(Node *n) { 
    push(n->p); push(n);
    bool ndir = side(n), pdir = side(n->p);
    Node *p = n->p, *d = n->ch[!ndir], *pp = p->p;
    if (isrt(p)) setp(n, pp); else setc(pp, n, pdir); setc(p, d, ndir); setc(n, p, !ndir);
    upd(p); upd(n);
}
void splay(Node *n) {
    while (n && !isrt(n)) {
        if (!isrt(n->p)) {
            if (side(n) == side(n->p)) { rot(n->p); rot(n); }
            else { rot(n); rot(n); }
        }
        else rot(n);
    }
    push(n);
}
void access(Node *n) {
    for (Node *c = n, *pre = nullptr; c; c = c->p) {
        splay(c); c->ch[1] = pre; upd(c);
        pre = c;
    }
    splay(n);
}

void reroot(Node *n) {
    access(n); n->rev ^= 1; push(n);
}
void link(Node *u, Node *v) {
    reroot(v); access(u);
    setc(v, u, 0); upd(v);
}
Node* path(Node *u, Node *v) {
    reroot(u); access(v);
    // db(v->val); db(v->sum); db(v->max); db(v->min); db(v->lazyInc); db(v->lazySet); db(v->rev); dbln;
    return v;
}
Node* lca(Node *u, Node *v) {
    access(u); access(v); splay(u);
    // db(u); db(v); db(u->p); dbln;
    return u->p ? u->p : u;
}
void cut(Node *n) {
    access(n);
    setp(n->ch[0], nullptr); setc(n, nullptr, 0); upd(n);
}

Node *lct[MN];
