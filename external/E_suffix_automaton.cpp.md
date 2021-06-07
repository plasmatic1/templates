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
  bundledCode: "#line 1 \"external/E_suffix_automaton.cpp\"\nconst int MAXLEN = 100000;\n\
    struct state {\n    int len, link;\n    map<char, int> next;\n};\nstate st[MAXLEN\
    \ * 2];\nint sz, last;\nvoid sa_init() {\n    st[0].len = 0;\n    st[0].link =\
    \ -1;\n    sz++;\n    last = 0;\n}\nvoid sa_extend(char c) {\n    int cur = sz++;\n\
    \    st[cur].len = st[last].len + 1;\n    int p = last;\n    while (p != -1 &&\
    \ !st[p].next.count(c)) {\n        st[p].next[c] = cur;\n        p = st[p].link;\n\
    \    }\n    if (p == -1) {\n        st[cur].link = 0;\n    } else {\n        int\
    \ q = st[p].next[c];\n        if (st[p].len + 1 == st[q].len) {\n            st[cur].link\
    \ = q;\n        } else {\n            int clone = sz++;\n            st[clone].len\
    \ = st[p].len + 1;\n            st[clone].next = st[q].next;\n            st[clone].link\
    \ = st[q].link;\n            while (p != -1 && st[p].next[c] == q) {\n       \
    \         st[p].next[c] = clone;\n                p = st[p].link;\n          \
    \  }\n            st[q].link = st[cur].link = clone;\n        }\n    }\n    last\
    \ = cur;\n}\n"
  code: "const int MAXLEN = 100000;\nstruct state {\n    int len, link;\n    map<char,\
    \ int> next;\n};\nstate st[MAXLEN * 2];\nint sz, last;\nvoid sa_init() {\n   \
    \ st[0].len = 0;\n    st[0].link = -1;\n    sz++;\n    last = 0;\n}\nvoid sa_extend(char\
    \ c) {\n    int cur = sz++;\n    st[cur].len = st[last].len + 1;\n    int p =\
    \ last;\n    while (p != -1 && !st[p].next.count(c)) {\n        st[p].next[c]\
    \ = cur;\n        p = st[p].link;\n    }\n    if (p == -1) {\n        st[cur].link\
    \ = 0;\n    } else {\n        int q = st[p].next[c];\n        if (st[p].len +\
    \ 1 == st[q].len) {\n            st[cur].link = q;\n        } else {\n       \
    \     int clone = sz++;\n            st[clone].len = st[p].len + 1;\n        \
    \    st[clone].next = st[q].next;\n            st[clone].link = st[q].link;\n\
    \            while (p != -1 && st[p].next[c] == q) {\n                st[p].next[c]\
    \ = clone;\n                p = st[p].link;\n            }\n            st[q].link\
    \ = st[cur].link = clone;\n        }\n    }\n    last = cur;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: external/E_suffix_automaton.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/E_suffix_automaton.cpp
layout: document
redirect_from:
- /library/external/E_suffix_automaton.cpp
- /library/external/E_suffix_automaton.cpp.html
title: external/E_suffix_automaton.cpp
---
