// Stirling Numbers (1st kind)
// Depends on mod template
// Number of length N permutations with K disjoint cycles
vector<vector<ll>> dp;
ll stir1(ll N, ll K) {
    dp.assign(N + 1, vector<ll>(K + 1, -1));
    return _stir1(N, K);
}
ll _stir1(ll N, ll K) {
    if (!N && !K) return 1LL;
    if (!N || !K) return 0LL;
    ll &ret = dp[N][K];
    if (ret != -1) return ret;
    return ret = madd(mmul(N - 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));
}

// Stirling Numbers (2nd kind)
// Depends on mod and nchooser templates (and calling init_nchooser to init factorial table)
// Number of ways to partition N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does not matter)
// If you want to do it with labelled subsets, just remove the division at the end or multiply by fact[K]
// If empty subsets were allowed, the answer would just be K^N
ll stir2(ll N, ll K) {
    ll res = 0;
    int coeff = 1;
    for (int i = 0; i <= K; i++) {
        res = madd(res, mmul(coeff, mmul(choose(K, i), fpow(K - i, N))));
        coeff *= -1;
    }
    return mdiv(res, fact[K]);
}

