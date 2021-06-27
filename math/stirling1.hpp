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
                dp[i][j] = (i - 1) * dp[i - 1][j] + dp[i - 1][j - 1];
    }
    T get(int n, int k) { return dp[n][k]; }
};