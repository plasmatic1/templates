
mt19937 mt(04072020);
uniform_int_distribution<int> dis(INT_MIN, INT_MAX);

struct Node {
    Node *l, *r;
    int pri;

    int sz;
    ll val, sum;
    Node(ll v0) : l(nullptr), r(nullptr), pri(dis(mt)), sz(1), val(v0), sum(v0) {}
};

int sz(Node *n) { return n ? n->sz : 0; }
ll sum(Node *n) { return n ? n->sum : 0; }
void push(Node *n) {
    if (n) {

    }
}
void upd(Node *n) {
    push(n->l); push(n->r);
    if (n) {
        n->sz = sz(n->l) + sz(n->r) + 1;
        n->sum = sum(n->l) + sum(n->r) + n->val;
    }
}
const bool VAL = 0, IDX = 1;
// type=0->val, type=1->idx
void split(Node *n, bool type, ll key, Node *&l, Node *&r) {
    if (!n) return void(l = r = nullptr);
    push(n);
    int rm = sz(n->l) + 1;
    if ((type == VAL && n->val <= key) || (type == IDX && rm <= key)) { split(n->r, type, key - (type * rm), n->r, r); l = n; }
    else { split(n->l, type, key, l, n->l); r = n; }
    upd(n);
}
void merge(Node *&n, Node *l, Node *r) {
    push(l); push(r);
    if (!l || !r) n = l ? l : r;
    else if (l->pri > r->pri) { merge(l->r, l->r, r); n = l; }
    else { merge(r->l, l, r->l); n = r; }
    upd(n);
}

// debug
void io(Node *n) {
    if(!n)return;io(n->l);cout<<n->val<<", ";io(n->r);
}
#define PS(n) do{cout<<(#n)<<": [";io(n);cout<<"]"<<endl;}while(0)

void ins(Node *&rt, ll x) {
    Node *tmp;
    split(rt, VAL, x, rt, tmp);
    merge(rt, rt, new Node(x));
    merge(rt, rt, tmp);
}
void rem(Node *&rt, ll x) {
    if (rt->val == x) merge(rt, rt->l, rt->r);
    else rem(x > rt->val ? rt->r : rt->l, x);
    upd(rt);
}

ll over(Node *n, ll x) {
    if (!n) return LLINF;
    push(n);
    if (n->val > x) return min(n->val, over(n->l, x));
    return over(n->r, x);
}

