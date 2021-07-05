---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/scc.test.cpp
    title: tests/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus ==\
    \ 201703L // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
    \ // for some templates\n#endif\nusing ll = long long; using ull = unsigned long\
    \ long; using ld = long double;\nusing pii = pair<int, int>; using pll = pair<long\
    \ long, long long>;\n#ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
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
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"graph/scc.hpp\"\n\
    \ntemplate <typename GraphType, typename EdgeType> struct SCC {\n    EdgeType\
    \ E;\n    int cord = 0;\n    vector<int> ord, low, stk;\n    vector<bool> instk;\n\
    \n    vector<vector<int>> solve(int N, GraphType &g) {\n        ord.assign(N+1,\
    \ 0);\n        low.assign(N+1, 0);\n        instk.assign(N+1, false);\n      \
    \  stk.clear();\n        cord = 0;\n\n        vector<vector<int>> cs;\n      \
    \  function<void(int)> tarjan = [&] (int c) {\n            ord[c] = low[c] = ++cord;\n\
    \            instk[c] = true;\n            stk.push_back(c);\n\n            for\
    \ (auto _to : g[c]) {\n                int to = E.v(_to);\n                if\
    \ (!ord[to]) {\n                    tarjan(to);\n                    low[c] =\
    \ min(low[c], low[to]);\n                } else if (instk[to])\n             \
    \       low[c] = min(low[c], ord[to]);\n            }\n\n            if (low[c]\
    \ == ord[c]) {\n                int u;\n                cs.push_back(vector<int>());\n\
    \                do {\n                    u = stk.back();\n                 \
    \   instk[u] = false;\n                    stk.pop_back();\n                 \
    \   cs.back().push_back(u);\n                } while (u != c);\n            }\n\
    \        };\n        for (int i = 1; i <= N; i++)\n            if (!ord[i])\n\
    \                tarjan(i);\n\n        return cs;\n    }\n\n#if __cplusplus ==\
    \ 201703L // CPP17 only things\n    void bind(opt_ref<vector<int>> ord0, opt_ref<vector<int>>\
    \ low0) {\n        if (ord0) ord.swap(*ord0);\n        if (low0) low.swap(*low0);\n\
    \    }\n#endif\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <typename GraphType,\
    \ typename EdgeType> struct SCC {\n    EdgeType E;\n    int cord = 0;\n    vector<int>\
    \ ord, low, stk;\n    vector<bool> instk;\n\n    vector<vector<int>> solve(int\
    \ N, GraphType &g) {\n        ord.assign(N+1, 0);\n        low.assign(N+1, 0);\n\
    \        instk.assign(N+1, false);\n        stk.clear();\n        cord = 0;\n\n\
    \        vector<vector<int>> cs;\n        function<void(int)> tarjan = [&] (int\
    \ c) {\n            ord[c] = low[c] = ++cord;\n            instk[c] = true;\n\
    \            stk.push_back(c);\n\n            for (auto _to : g[c]) {\n      \
    \          int to = E.v(_to);\n                if (!ord[to]) {\n             \
    \       tarjan(to);\n                    low[c] = min(low[c], low[to]);\n    \
    \            } else if (instk[to])\n                    low[c] = min(low[c], ord[to]);\n\
    \            }\n\n            if (low[c] == ord[c]) {\n                int u;\n\
    \                cs.push_back(vector<int>());\n                do {\n        \
    \            u = stk.back();\n                    instk[u] = false;\n        \
    \            stk.pop_back();\n                    cs.back().push_back(u);\n  \
    \              } while (u != c);\n            }\n        };\n        for (int\
    \ i = 1; i <= N; i++)\n            if (!ord[i])\n                tarjan(i);\n\n\
    \        return cs;\n    }\n\n#if __cplusplus == 201703L // CPP17 only things\n\
    \    void bind(opt_ref<vector<int>> ord0, opt_ref<vector<int>> low0) {\n     \
    \   if (ord0) ord.swap(*ord0);\n        if (low0) low.swap(*low0);\n    }\n#endif\n\
    };\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-06-16 10:53:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
