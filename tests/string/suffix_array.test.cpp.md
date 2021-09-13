---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tests/test_utils.hpp
    title: tests/test_utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"tests/string/suffix_array.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/suffixarray\"\n#line 2 \"template.hpp\"\n#include\
    \ <bits/stdc++.h>\n#define DEBUG 1\nusing namespace std;\n\n// Defines\n#define\
    \ fs first\n#define sn second\n#define pb push_back\n#define eb emplace_back\n\
    #define mpr make_pair\n#define mtp make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    // Basic type definitions\n#if __cplusplus == 201703L // CPP17 only things\ntemplate\
    \ <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates\n\
    #endif\nusing ll = long long; using ull = unsigned long long; using ld = long\
    \ double;\nusing pii = pair<int, int>; using pll = pair<long long, long long>;\n\
    #ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
    \ // Common file\n#include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\
    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,\
    \ comp, rb_tree_tag, tree_order_statistics_node_update>;\ntemplate <typename K,\
    \ typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n// HashSet\n#include <ext/pb_ds/assoc_container.hpp>\n\
    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,\
    \ Hash>;\ntemplate <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\nconst ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };\n#endif\n//\
    \ More utilities\nint SZ(string &v) { return v.length(); }\ntemplate <typename\
    \ C> int SZ(C &v) { return v.size(); }\ntemplate <typename C> void UNIQUE(vector<C>\
    \ &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());\
    \ }\ntemplate <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }\n\
    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }\nconst\
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"tests/test_utils.hpp\"\
    \n\n// I/O\ntemplate <typename T> void print(T v) {\n    cout << v << '\\n';\n\
    }\n\ntemplate <typename T, typename... Rest> void print(T v, Rest... vs) {\n \
    \   cout << v << ' ';\n    print(vs...);\n}\n\nvoid fast_io() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n}\n\n// Reading operators\ntemplate <typename T, typename\
    \ U> istream& operator>>(istream& in, pair<T, U> &o) {\n    return in >> o.first\
    \ >> o.second;\n}\n\n// Read helpers\nint readi() {\n    int x; cin >> x;\n  \
    \  return x;\n}\n\nll readl() {\n    ll x; cin >> x;\n    return x;\n}\n\ntemplate\
    \ <typename T> vector<T> readv(int n) {\n    vector<T> res(n);\n    for (auto\
    \ &x : res) cin >> x;\n    return res;\n}\n\n// Functional stuff\ntemplate <typename\
    \ T> vector<pair<int, T>> enumerate(vector<T> v, int start = 0) {\n    vector<pair<int,\
    \ T>> res;\n    for (auto &x : v)\n        res.emplace_back(start++, x);\n   \
    \ return res;\n}\n\n#line 3 \"string/suffix_array.hpp\"\n\nconst int SA_ONLY =\
    \ 0, LCP = 1 << 0;\nstruct suf {\n    int idx, r1, r2;\n\n    bool operator<(const\
    \ suf &o) const {\n        return r1 == o.r1 ? r2 < o.r2 : r1 < o.r1;\n    }\n\
    };\ntemplate <const int _MN, const int MIN_VAL, const int MAX_VAL, const int MODE>\
    \ struct SuffixArray {\n    static const int MN = _MN+1, MV = MN+1 > MAX_VAL-MIN_VAL+2\
    \ ? MN+1 : MAX_VAL-MIN_VAL+2;\n    suf sa[MN];\n    int N, crnk[MN];\n    vector<int>\
    \ lcp;\n\n    void rsort_once(function<int(suf&)> key_fun) {\n        static int\
    \ cnt[MV];\n        static suf tmp[MN];\n        fill(cnt, cnt+MV, 0);\n     \
    \   for (int i = 0; i < N; i++)\n            cnt[key_fun(sa[i])]++;\n        partial_sum(cnt,\
    \ cnt+MV, cnt);\n        for (int i = N-1; i >= 0; i--)\n            tmp[--cnt[key_fun(sa[i])]]\
    \ = sa[i];\n        copy(tmp, tmp+N, sa);\n    }\n\n    void rsort() {\n     \
    \   rsort_once([&] (const suf &s) { return s.r2; });\n        rsort_once([&] (const\
    \ suf &s) { return s.r1; });\n    }\n\n    template <typename Container> vector<int>\
    \ solve(int N0, const Container &s) {\n        N = N0;\n        for (auto i =\
    \ 0; i < N; i++)\n            sa[i] = {i, s[i] - MIN_VAL + 1, i + 1 < N ? s[i\
    \ + 1] - MIN_VAL + 1 : 0};\n        rsort();\n        for (int i = 2; i <= N;\
    \ i *= 2) {\n            int ctr = 0;\n            suf pre{-1, -1, -1};\n    \
    \        for (auto j = 0; j < N; j++) {\n                if (sa[j].r1 != pre.r1\
    \ || sa[j].r2 != pre.r2) {\n                    ctr++;\n                    pre\
    \ = sa[j];\n                }\n                sa[j].r1 = ctr;\n             \
    \   crnk[sa[j].idx] = ctr;\n            }\n            for (auto j = 0; j < N;\
    \ j++)\n                sa[j].r2 = sa[j].idx + i < N ? crnk[sa[j].idx + i] : 0;\n\
    \            rsort();\n        }\n\n        vector<int> res(N);\n        for (int\
    \ i = 0; i < N; i++) res[i] = sa[i].idx;\n\n        if (MODE & LCP) {\n      \
    \      function<int(int, int)> getch = [&] (int idx, int col) {\n            \
    \    col += idx;\n                return col < N ? s[col] : MIN_VAL - 1;\n   \
    \         };\n\n            lcp.assign(N, 0);\n            vector<int> where(N);\n\
    \            for (int i = 0; i < N; i++) where[res[i]] = i;\n            int cur\
    \ = 0;\n            for (int i = 0; i < N; i++) {\n                int t = where[i];\n\
    \                if (t < N-1)\n                    while (getch(i, cur) == getch(res[t+1],\
    \ cur))\n                        cur++;\n                lcp[t] = cur;\n\n   \
    \             if (cur > 0) cur--;\n            }\n        }\n\n        return\
    \ res;\n    }\n\n#if __cplusplus == 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>>\
    \ lcp0) {\n        if (lcp0) lcp.swap(*lcp0);\n    }\n#endif\n};\n#line 5 \"tests/string/suffix_array.test.cpp\"\
    \n\nconst int MN = 5e5 + 1;\nSuffixArray<MN, 'a', 'z', SA_ONLY> sa;\nint N;\n\
    string s;\n\nint main() {\n    fast_io();\n    cin >> s; N = s.length();\n   \
    \ for (auto idx : sa.solve(N, s))\n        cout << idx << ' ';\n    cout << '\\\
    n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"../../template.hpp\"\n#include \"../test_utils.hpp\"\n#include \"../../string/suffix_array.hpp\"\
    \n\nconst int MN = 5e5 + 1;\nSuffixArray<MN, 'a', 'z', SA_ONLY> sa;\nint N;\n\
    string s;\n\nint main() {\n    fast_io();\n    cin >> s; N = s.length();\n   \
    \ for (auto idx : sa.solve(N, s))\n        cout << idx << ' ';\n    cout << '\\\
    n';\n\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - tests/test_utils.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: tests/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/tests/string/suffix_array.test.cpp
- /verify/tests/string/suffix_array.test.cpp.html
title: tests/string/suffix_array.test.cpp
---
