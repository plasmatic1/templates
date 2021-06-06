#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct HashBase {
    ll base, mod;
    HashBase(ll b0, ll m0) : base(b0), mod(m0) {}
    ll madd(ll a, ll b) { return (a + b) % mod; }
    ll mmul(ll a, ll b) { return (a * b) % mod; }
    ll msub(ll a, ll b) { return ((a - b) % mod + mod) % mod; }
    ll fpow(ll x, ll y) {
        if (!y) return 1LL;
        return mmul(fpow(mmul(x, x), y / 2), (y & 1) ? x : 1LL);
    }
    ll mdiv(ll x, ll y) { return mmul(x, fpow(y, mod - 2)); }

    vector<ll> pow;
    void initPow(int sz) {
        pow.resize(sz + 1);
        pow[0] = 1LL;
        for (int i = 1; i <= sz; i++)
            pow[i] = mmul(pow[i - 1], base);
    }
};

// hash with random base
HashBase randBase(ll mod) {
    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    return HashBase(uniform_int_distribution<ll>(mod / 2, mod - 2)(mt), mod);
}

struct Hash {
    vector<ll> hsh;
    HashBase &b;
    Hash(HashBase &b0) : b(b0) {}
    void init(string &s) { // auto-inits pow
        int len = s.length();
        hsh.resize(len + 1);
        for (int i = 1; i <= len; i++)
            hsh[i] = b.madd(b.mmul(hsh[i - 1], b.base), s[i - 1]);
    }
    ll get(int l, int r) { // 1-indexed
        return b.msub(hsh[r], b.mmul(hsh[l - 1], b.pow[r - l + 1]));
    }
};

template <int C, typename HashType = ll>
struct MultiHash {
    HashType comb(HashType curHash, HashType toAdd) { return (curHash << 32) | toAdd; } // TODO: Override if needed
    HashType zeroVal() { return 0LL; } // Zero value of the hashtype, override if needed 
    Hash hs[C];
    MultiHash(HashBase bs[C]) {
        for (int i = 0; i < C; i++)
            hs[i] = Hash(bs[i]);
    }
    void init(string &s) {
        for (int i = 0; i < C; i++)
            hs[i].init(s);
    }
    HashType get(int l, int r) {
        HashType res = zeroVal();
        for (int i = 0; i < C; i++)
            res = comb(res, hs[i].get(l, r));
        return res;
    }
};
