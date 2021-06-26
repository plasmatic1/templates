#include "../template.hpp"
#include "choose.hpp"
#pragma once

// Stirling Numbers (1st kind)
// Depends on mod template
// Number of length N permutations with K disjoint cycles
template <typename T> struct Stir1 {
    vector<vector<T>> dp;
    void init(int N, int K) {
        dp.assign(N+1, vector<T>(K+1));
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                dp[i][j] = (i-1)*dp[i-1][j] + dp[i-1][j-1];
    }
    T get(int n, int k) { return dp[n][k]; }
};

// Stirling Numbers (2nd kind)
// Depends on mod and nchooser templates (and calling init_nchooser to init factorial table)
// Number of ways to partition N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does not matter)
// If you want to do it with labelled subsets, just remove the division at the end or multiply by fact[K]
// If empty subsets were allowed, the answer would just be K^N
template <typename T> T stir2(int N, int K, Choose<T> &c) {
    T res = 0, coeff = 1;
    for (int i = 0; i <= K; i++) {
        res += coeff * c.choose(K, i) * mpow((T)K - i, N));
        coeff *= -1;
    }
    return mdiv(res, c.fact[K]);
}
