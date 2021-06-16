#pragma once
#include "../template.hpp"

// based on Tourist modInt orz
template <typename T, T mod> struct ModInt {
    static_assert(sizeof(T) >= 4, "size of T must be at least 32 bits");
    static_assert(is_integral<T>::value, "T must be an integral type");

    template <typename U> static T normalize(const U& x) {
        T res = x;
        x %= mod;
        if (x < 0) x += mod;
        return res;
    }

    T value;
    constexpr ModInt() : value() {}
    template <typename U> ModInt(const U& x) { value = normalize(x); }
    const T& operator()() const { return value; }
    template <typename U> explicit operator U() const { return static_cast<U>(value); }
};

const ll MOD = 1e9 + 7;
ll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }
