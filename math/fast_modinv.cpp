// fast modular inverse (with O(N) precalc), 9 lines
const int MN = 1001;
ll inv[MN];
void init_modinv(ll mod) {
    inv[1] = 1LL;
    for (int i = 2; i < MN; i++)
        inv[i] = (mod - ((mod / i) * inv[mod % i]) % mod) % mod;
}
ll mdiv(ll x, ll y) { return (x * inv[y]) % MOD; }
