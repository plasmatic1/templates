#include "../template.hpp"
#pragma once

template <typename T> T totient(T v) {
    T res = v;
    for (T i = 2; i * i <= v; i++) {
        if (v % i == 0) {
            while (v % i == 0) v /= i;
            res /= i;
            res *= i-1;
        }
    }
    if (v > 1) {
        res /= v;
        res *= v-1;
    }
    return res;
}
