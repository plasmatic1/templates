#include "../template.hpp"
#pragma once

template <typename T> struct FastModInv {
    vector<T> inv;
    T mod;
    void init(int N, T _mod) {
        inv.assign(N+1); inv[1] = 1LL; mod = _mod;
        for (int i = 2; i <= N; i++)
            inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    }
    T mdiv(T x, T y) { return x * inv[y] % mod; }
};
