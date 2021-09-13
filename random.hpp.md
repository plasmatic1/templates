---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "template.hpp"

    #include <bits/stdc++.h>

    #define DEBUG 1

    using namespace std;


    // Defines

    #define fs first

    #define sn second

    #define pb push_back

    #define eb emplace_back

    #define mpr make_pair

    #define mtp make_tuple

    #define all(x) (x).begin(), (x).end()

    // Basic type definitions

    #if __cplusplus == 201703L // CPP17 only things

    template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some
    templates

    #endif

    using ll = long long; using ull = unsigned long long; using ld = long double;

    using pii = pair<int, int>; using pll = pair<long long, long long>;

    #ifdef __GNUG__

    // PBDS order statistic tree

    #include <ext/pb_ds/assoc_container.hpp> // Common file

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,
    comp, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename K, typename V, class comp = less<K>> using treemap = tree<K,
    V, comp, rb_tree_tag, tree_order_statistics_node_update>;

    // HashSet

    #include <ext/pb_ds/assoc_container.hpp>

    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,
    Hash>;

    template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,
    V, Hash>;

    const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

    #endif

    // More utilities

    int SZ(string &v) { return v.length(); }

    template <typename C> int SZ(C &v) { return v.size(); }

    template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(),
    v.end()) - v.begin()); }

    template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }

    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }

    const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

    #line 3 "random.hpp"


    mt19937 __mt(26022021);

    int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(__mt);
    }

    ll randll(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(__mt); }

    template <typename T, typename It> T choice(It st, It en) { return *(st + randint(0,
    en-st-1)); }

    '
  code: '#pragma once

    #include "template.hpp"


    mt19937 __mt(26022021);

    int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(__mt);
    }

    ll randll(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(__mt); }

    template <typename T, typename It> T choice(It st, It en) { return *(st + randint(0,
    en-st-1)); }'
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: random.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.hpp
layout: document
redirect_from:
- /library/random.hpp
- /library/random.hpp.html
title: random.hpp
---
