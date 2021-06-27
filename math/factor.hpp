#include "../template.hpp"
#pragma once

template <typename T> vector<T> factor(T v) {
    vector<T> res;
    for (T i = 1; i * i <= v; i++) {
        if (v % i == 0) {
            res.push_back(i);
            if (i * i != v) res.push_back(v/i);
        }
    }
    return res;
}