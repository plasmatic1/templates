---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/bit.hpp
    title: ds/bit.hpp
  - icon: ':warning:'
    path: ds/dsu.hpp
    title: ds/dsu.hpp
  - icon: ':warning:'
    path: template.cpp
    title: template.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: '#pragma once

    #include "bits/stdc++.h"

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

    '
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - ds/bit.hpp
  - ds/dsu.hpp
  - template.cpp
  timestamp: '2021-06-07 01:26:18-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---
