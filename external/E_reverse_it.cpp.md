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
  bundledCode: "#line 1 \"external/E_reverse_it.cpp\"\ntemplate<typename T> class\
    \ reverse {\nprivate:\n    T& iterable_;\npublic:\n    explicit reverse(T& iterable)\
    \ : iterable_{iterable} {}\n    auto begin() const { return std::rbegin(iterable_);\
    \ }\n    auto end() const { return std::rend(iterable_); }\n};\ntemplate<typename\
    \ T> class reverse_move {\nprivate:\n    T iterable_;\npublic:\n    explicit reverse_move(T&&\
    \ iterable) : iterable_{std::move(iterable)} {}\n    auto begin() const { return\
    \ std::rbegin(iterable_); }\n    auto end() const { return std::rend(iterable_);\
    \ }\n};\n"
  code: "template<typename T> class reverse {\nprivate:\n    T& iterable_;\npublic:\n\
    \    explicit reverse(T& iterable) : iterable_{iterable} {}\n    auto begin()\
    \ const { return std::rbegin(iterable_); }\n    auto end() const { return std::rend(iterable_);\
    \ }\n};\ntemplate<typename T> class reverse_move {\nprivate:\n    T iterable_;\n\
    public:\n    explicit reverse_move(T&& iterable) : iterable_{std::move(iterable)}\
    \ {}\n    auto begin() const { return std::rbegin(iterable_); }\n    auto end()\
    \ const { return std::rend(iterable_); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: external/E_reverse_it.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/E_reverse_it.cpp
layout: document
redirect_from:
- /library/external/E_reverse_it.cpp
- /library/external/E_reverse_it.cpp.html
title: external/E_reverse_it.cpp
---
