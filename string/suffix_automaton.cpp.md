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
  bundledCode: "#line 1 \"string/suffix_automaton.cpp\"\nconst int MN = 5001;\nstruct\
    \ SAM {\n    struct state {\n        int len, link;\n        map<char, int> to;\n\
    \    };\n    state st[MN*2];\n    int last, sz = 0;\n    void init() {\n     \
    \   for (auto i = 0; i < MN*2; i++) st[i] = {0, 0, map<char, int>()};\n      \
    \  st[0] = {0, -1, map<char, int>()};\n        sz = 1; last = 0;\n    }\n    void\
    \ extend(char c) {\n        int cur = sz++, p = last;\n        st[cur].len = st[last].len\
    \ + 1;\n        for (; p != -1 && !st[p].to.count(c); p = st[p].link)\n      \
    \      st[p].to[c] = cur;\n        if (p == -1) st[cur].link = 0;\n        else\
    \ {\n            int q = st[p].to[c];\n            if (st[p].len + 1 == st[q].len)\
    \ st[cur].link = q; // transition is continuous, we can link directly to Q as\
    \ the parent in the prefix trie\n            else { // transition is discontinuous,\
    \ we must split node q into p+1, \n                int clone = sz++; \n      \
    \          st[clone] = st[q]; st[clone].len = st[p].len + 1;\n               \
    \ for (; p != -1 && st[p].to[c] == q; p = st[p].link)\n                    st[p].to[c]\
    \ = clone;\n                st[cur].link = st[q].link = clone;\n            }\n\
    \        }\n\n        last = cur;\n    }\n};\n\n\n"
  code: "const int MN = 5001;\nstruct SAM {\n    struct state {\n        int len,\
    \ link;\n        map<char, int> to;\n    };\n    state st[MN*2];\n    int last,\
    \ sz = 0;\n    void init() {\n        for (auto i = 0; i < MN*2; i++) st[i] =\
    \ {0, 0, map<char, int>()};\n        st[0] = {0, -1, map<char, int>()};\n    \
    \    sz = 1; last = 0;\n    }\n    void extend(char c) {\n        int cur = sz++,\
    \ p = last;\n        st[cur].len = st[last].len + 1;\n        for (; p != -1 &&\
    \ !st[p].to.count(c); p = st[p].link)\n            st[p].to[c] = cur;\n      \
    \  if (p == -1) st[cur].link = 0;\n        else {\n            int q = st[p].to[c];\n\
    \            if (st[p].len + 1 == st[q].len) st[cur].link = q; // transition is\
    \ continuous, we can link directly to Q as the parent in the prefix trie\n   \
    \         else { // transition is discontinuous, we must split node q into p+1,\
    \ \n                int clone = sz++; \n                st[clone] = st[q]; st[clone].len\
    \ = st[p].len + 1;\n                for (; p != -1 && st[p].to[c] == q; p = st[p].link)\n\
    \                    st[p].to[c] = clone;\n                st[cur].link = st[q].link\
    \ = clone;\n            }\n        }\n\n        last = cur;\n    }\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_automaton.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_automaton.cpp
layout: document
redirect_from:
- /library/string/suffix_automaton.cpp
- /library/string/suffix_automaton.cpp.html
title: string/suffix_automaton.cpp
---
