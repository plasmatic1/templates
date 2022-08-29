---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rank_compression.test.cpp
    title: tests/rank_compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ rank_compression.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"template.hpp\"\n#pragma once\n\n// template is 1-indexed\ntemplate\
    \ <typename T> struct Ranks {\n    vector<T> ranks;\n    void init() {\n     \
    \   sort(ranks.begin(), ranks.end());\n        ranks.resize(unique(ranks.begin(),\
    \ ranks.end()) - ranks.begin());\n    }\n    template <typename It> void init(It\
    \ st, It en) { ranks = vector<T>(st, en); init(); }\n    void add(T v) { ranks.push_back(v);\
    \ }\n    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin()\
    \ + 1; }\n    int size() { return ranks.size(); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: rank_compression.hpp
  requiredBy: []
  timestamp: '2021-09-12 23:20:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rank_compression.test.cpp
documentation_of: rank_compression.hpp
layout: document
redirect_from:
- /library/rank_compression.hpp
- /library/rank_compression.hpp.html
title: rank_compression.hpp
---
