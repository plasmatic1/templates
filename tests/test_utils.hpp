#pragma once
#include "../template.hpp"

// I/O
template <typename T> void print(T v) {
    cout << v << '\n';
}

template <typename T, typename... Rest> void print(T v, Rest... vs) {
    cout << v << ' ';
    print(vs...);
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Reading operators
template <typename T, typename U> istream& operator>>(istream& in, pair<T, U> &o) {
    return in >> o.first >> o.second;
}

// Read helpers
int readi() {
    int x; cin >> x;
    return x;
}

ll readl() {
    ll x; cin >> x;
    return x;
}

template <typename T> vector<T> readv(int n) {
    vector<T> res(n);
    for (auto &x : res) cin >> x;
    return res;
}

// Functional stuff
template <typename T> vector<pair<int, T>> enumerate(vector<T> v, int start = 0) {
    vector<pair<int, T>> res;
    for (auto &x : v)
        res.emplace_back(start++, x);
    return res;
}

