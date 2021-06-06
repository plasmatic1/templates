// Hashing stuff
const ll MODS[2] = {1000000007, 1000000009}, BASE[2] = {131, 191};
ll madd(ll a, ll b, ll mod) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod) { return mmul(x, fpow(y, mod - 2, mod), mod); }

ll comb(ll lo, ll hi) { return (hi << 32) | lo; }
ll glo(ll x) { return x & ((1LL << 32) - 1); }
ll ghi(ll x) { return x >> 32; }
ll append1(ll hsh, int val, int i) { return madd(mmul(hsh, BASE[i], MODS[i]), val, MODS[i]); }
ll append(ll hsh, int val) { return comb(append1(glo(hsh), val, 0), append1(ghi(hsh), val, 1)); } 
vector<ll> pows[2];
void init_pow(int N) {
    for (auto i = 0; i < 2; i++) {
        pows[i].resize(N + 1);
        pows[i][0] = 1LL;
        for (auto j = 1; j <= N; j++)
            pows[i][j] = mmul(pows[i][j - 1], BASE[i], MODS[i]);
    }
}
ll ghsh1(ll hr, ll hl, int sz, int i) {
    return msub(hr, mmul(pows[i][sz], hl, MODS[i]), MODS[i]);
}
ll ghsh(ll *hs, int l, int r) {
    int sz = r - l + 1;
    return comb(ghsh1(glo(hs[r]), glo(hs[l - 1]), sz, 0), ghsh1(ghi(hs[r]), ghi(hs[l - 1]), sz, 1));
}
ll concat1(ll hsh, ll hsh2, int sz, int i) { return madd(mmul(hsh, pows[i][sz], MODS[i]), hsh2, MODS[i]); }
ll concat(ll hsh, ll hsh2, int sz) { return comb(concat1(glo(hsh), glo(hsh2), sz, 0), concat1(ghi(hsh), ghi(hsh2), sz, 1)); }
