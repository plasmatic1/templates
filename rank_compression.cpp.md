---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"rank_compression.cpp\"\n// template is 1-indexed\ntemplate\
    \ <typename T> struct Ranks {\n    vector<T> ranks;\n    void init() {\n     \
    \   sort(ranks.begin(), ranks.end());\n        ranks.resize(unique(ranks.begin(),\
    \ ranks.end()) - ranks.begin());\n    }\n    template <typename It> void init(It\
    \ st, It en) { ranks = vector<T>(st, en); init(); }\n    void add(T v) { ranks.push_back(v);\
    \ }\n    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin()\
    \ + 1; }\n    int size() { return ranks.size(); }\n};\n"
  code: "// template is 1-indexed\ntemplate <typename T> struct Ranks {\n    vector<T>\
    \ ranks;\n    void init() {\n        sort(ranks.begin(), ranks.end());\n     \
    \   ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());\n    }\n\
    \    template <typename It> void init(It st, It en) { ranks = vector<T>(st, en);\
    \ init(); }\n    void add(T v) { ranks.push_back(v); }\n    int get(T v) { return\
    \ lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin() + 1; }\n    int size()\
    \ { return ranks.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: rank_compression.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: rank_compression.cpp
layout: document
redirect_from:
- /library/rank_compression.cpp
- /library/rank_compression.cpp.html
title: rank_compression.cpp
---
