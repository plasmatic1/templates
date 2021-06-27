#include "../template.hpp"
#include "choose.hpp"
#pragma once

// Stirling Numbers (2nd kind)
// Depends on mod and nchooser templates (and calling init_nchooser to init factorial table)
// Number of ways to partition N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does not matter)
// If you want to do it with labelled subsets, just remove the division at the end or multiply by fact[K]
// If empty subsets were allowed, the answer would just be K^N
template <typename T> T stir2(int N, int K, Choose<T> &c) {
    T res = 0, coeff = 1;
    for (int i = 0; i <= K; i++) {
        res += coeff * c.choose(K, i) * T::pow(K - i, N);
        coeff *= -1;
    }
    return res / c.fact[K];
}
