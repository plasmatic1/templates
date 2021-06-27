#include "../template.hpp"
#pragma once

template <typename T> vector<pair<T, int>> primeFactor1(T v) {
    vector<pair<T, int>> res;
    for (T i = 2; i * i <= v; i++) {
        if (v % i == 0) {
            int cnt = 0;
            for (; v % i == 0; v /= i) cnt++;
            res.emplace_back(i, cnt);
        }
    }
    if (v > 1) res.emplace_back(v, 1);
    return res;
}
template <typename T> vector<T> primeFactor2(T v) {
    vector<T> res;
    for (T i = 2; i * i <= v; i++) {
        for (; v % i == 0; v /= i)
            res.push_back(i);
    }
    if (v > 1) res.push_back(v);
    return res;
}
