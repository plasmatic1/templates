#include "../template.hpp"
#pragma once

// N choose R
template <typename T> struct Choose {
    vector<T> fact, invf;
    void init(int N) {
        fact.resize(N + 1); invf.resize(N + 1);
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
        invf[N] = 1 / fact[N];
        for (auto i = N - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1);
    }
    T choose(T N, T K) { return fact[N] * invf[K] * invf[N - K]; }
    T permute(T N, T K) { return fact[N] * invf[N - K]; }
};
