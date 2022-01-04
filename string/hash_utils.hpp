#pragma once
#include "../template.hpp"

// Hashing stuff
const int FIXED_BASE = 0, RAND_BASE = 1 << 0;
const ll MOD = 999999999999999989;
ll BASE = 131;

vector<ll> _hash_pows;
template <int MODE> void init_hash(int MAX_N) {
    if (MODE & RAND_BASE) {
        mt19937 mt(RANDOM);
        BASE = uniform_int_distribution<ll>(MOD/2, MOD-2)(mt);
    }

    _hash_pows.resize(MAX_N + 1);
    _hash_pows[0] = 1LL;
    for (auto i = 1; i <= MAX_N; i++)
        _hash_pows[i] = __int128(_hash_pows[i - 1]) * BASE % MOD;
}
template <typename It> ll hget(It hs, int l, int r) {
    __int128 res = (hs[r] - __int128(hs[l - 1]) * _hash_pows[r - l + 1]) % MOD;
    if (res < 0) res += MOD;
    return res;
}
ll happend(ll hsh, int val) { return (__int128(hsh) * BASE + val) % MOD; }
ll hconcat(ll hshLeft, ll hshRight, int szRight) { return (__int128(hshLeft) * _hash_pows[szRight] + hshRight) % MOD; }
