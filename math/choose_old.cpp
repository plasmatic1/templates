// N choose R
vector<ll> fact, invf;
void init_nchooser(int MN) {
    fact.resize(MN + 1); invf.resize(MN + 1);
    fact[0] = invf[0] = 1LL;
    for (int i = 1; i <= MN; i++) {
        fact[i] = mmul(fact[i - 1], i);
        invf[i] = mdiv(1, fact[i]);
    }
}
ll choose(ll N, ll K) { return mmul(fact[N], mmul(invf[K], invf[N - K])); }
ll permute(ll N, ll K) { return mmul(fact[N], invf[N - K]); }
