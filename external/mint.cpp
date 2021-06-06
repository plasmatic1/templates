#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular int
template <typename T> T fpow(T x, T y) {
    if (!y) return 1LL;
    return fpow(x * x, y >> 1) * ((y & 1) ? x : 1LL);
}
#define mod_t modular<T, mod>
template <typename T, T mod>
struct modular { // modular allen pei
    void fix() { val = (val % mod + mod) % mod; }

    T val;
    modular(mod_t &x) : val(x.val) {}
    #define CC(type) modular(type val0) : val(val0) { fix(); } 
    CC(int) CC(unsigned int) CC(long long) CC(unsigned long long) CC(char) CC(unsigned char) CC(short) CC(unsigned short) CC(bool)
    #undef CC

    #define MAKE_OP(op) template<typename U> mod_t& operator op##= (const U &o) { return *this op##= mod_t(o); }  \
    template<typename U> mod_t& operator op##= (const U o) { return *this op##= mod_t(o); }
    mod_t& operator +=(const mod_t &o) const { val = (val + o) % mod; return *this; }
    mod_t& operator -=(const mod_t &o) const { val = (val - o + mod) % mod; return *this; }
    mod_t& operator *=(const mod_t &o) const { val = (val * o) % mod; return *this; }
    mod_t& operator /=(const mod_t &o) const { return *this *= fpow(o, mod - 2); }
    bool operator ==(const mod_t &o) const { return val == o.val; }
    bool operator !=(const mod_t &o) const { return !(val == o.val); }
    bool operator <(const mod_t &o) const { return val < o.val; }
    bool operator >(const mod_t &o) const { return val > o.val; }
    bool operator <=(const mod_t &o) const { return val <= o.val; }
    bool operator >=(const mod_t &o) const { return val >= o.val; }
    mod_t& operator =(const mod_t &o) const { return *this = o; }
    MAKE_OP(+) MAKE_OP(-) MAKE_OP(*) MAKE_OP(/) 
    #undef MAKE_OP
    mod_t& operator++() { return *this += 1; }
    mod_t& operator--() { return *this -= 1; }
    mod_t operator++(int) { mod_t res(*this); *this += 1; return res; }
    mod_t operator--(int) { mod_t res(*this); *this -= 1; return res; }
    mod_t operator-() const { return mod_t(-value); }
};
#define OP_TEMPL template <typename T, T mod, typename U>
#define MAKE_OP(op) OP_TEMPL mod_t operator op(const mod_t &l, const mod_t &r) { return mod_t(l) op##= r; }\
    OP_TEMPL mod_t operator op(const mod_t &l, const U r) { return mod_t(l) op##= r; }\
    OP_TEMPL mod_t operator op(const U l, const mod_t &r) { return mod_t(l) op##= r; }
MAKE_OP(+) MAKE_OP(-) MAKE_OP(*) MAKE_OP(/)
OP_TEMPL ostream& operator <<(ostream& out, const mod_t t) { out << t.val; return out; }
#undef MAKE_OP
#undef mod_t
const ll MOD = 1e9 + 7;
using mint = modular<int, MOD>; using mll = modular<ll, MOD>;

