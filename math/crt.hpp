#include "../template.hpp"
#include "eea.hpp"
#pragma once

/*
 * Provide in the form of:
 * {{residue1, modulus1}, {residue2, modulus2}, ...}
 */
template <typename T> T crt(const vector<pair<T, T>> &ms) {
    T v = 0, m = 1;
    for (auto [v0, m0] : ms) {
        T c, c0, _ = extgcd(m, m0, c, c0);
        v = v*c*m + v0*c0*m0;
        m *= m0;
    }
    return v;
}
