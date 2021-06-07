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
  bundledCode: "#line 1 \"external/E_fft.cpp\"\nusing cd = complex<double>;\nconst\
    \ double PI = acos(-1);\nvoid fft(vector<cd> & a, bool invert) {\n    int n =\
    \ a.size();\n    for (int i = 1, j = 0; i < n; i++) {\n        int bit = n >>\
    \ 1;\n        for (; j & bit; bit >>= 1)\n            j ^= bit;\n        j ^=\
    \ bit;\n\n        if (i < j)\n            swap(a[i], a[j]);\n    }\n    for (int\
    \ len = 2; len <= n; len <<= 1) {\n        double ang = 2 * PI / len * (invert\
    \ ? -1 : 1);\n        cd wlen(cos(ang), sin(ang));\n        for (int i = 0; i\
    \ < n; i += len) {\n            cd w(1);\n            for (int j = 0; j < len\
    \ / 2; j++) {\n                cd u = a[i+j], v = a[i+j+len/2] * w;\n        \
    \        a[i+j] = u + v;\n                a[i+j+len/2] = u - v;\n            \
    \    w *= wlen;\n            }\n        }\n    }\n    if (invert) {\n        for\
    \ (cd & x : a)\n            x /= n;\n    }\n}\ntemplate <typename T> vector<T>\
    \ multiply(vector<T> const& a, vector<T> const& b) {\n    vector<cd> fa(a.begin(),\
    \ a.end()), fb(b.begin(), b.end());\n    int n = 1;\n    while (n < a.size() +\
    \ b.size()) \n        n <<= 1;\n    fa.resize(n);\n    fb.resize(n);\n\n    fft(fa,\
    \ false);\n    fft(fb, false);\n    for (int i = 0; i < n; i++)\n        fa[i]\
    \ *= fb[i];\n    fft(fa, true);\n\n    vector<T> result(n);\n    for (int i =\
    \ 0; i < n; i++)\n        result[i] = round(fa[i].real());\n    return result;\n\
    }\n"
  code: "using cd = complex<double>;\nconst double PI = acos(-1);\nvoid fft(vector<cd>\
    \ & a, bool invert) {\n    int n = a.size();\n    for (int i = 1, j = 0; i < n;\
    \ i++) {\n        int bit = n >> 1;\n        for (; j & bit; bit >>= 1)\n    \
    \        j ^= bit;\n        j ^= bit;\n\n        if (i < j)\n            swap(a[i],\
    \ a[j]);\n    }\n    for (int len = 2; len <= n; len <<= 1) {\n        double\
    \ ang = 2 * PI / len * (invert ? -1 : 1);\n        cd wlen(cos(ang), sin(ang));\n\
    \        for (int i = 0; i < n; i += len) {\n            cd w(1);\n          \
    \  for (int j = 0; j < len / 2; j++) {\n                cd u = a[i+j], v = a[i+j+len/2]\
    \ * w;\n                a[i+j] = u + v;\n                a[i+j+len/2] = u - v;\n\
    \                w *= wlen;\n            }\n        }\n    }\n    if (invert)\
    \ {\n        for (cd & x : a)\n            x /= n;\n    }\n}\ntemplate <typename\
    \ T> vector<T> multiply(vector<T> const& a, vector<T> const& b) {\n    vector<cd>\
    \ fa(a.begin(), a.end()), fb(b.begin(), b.end());\n    int n = 1;\n    while (n\
    \ < a.size() + b.size()) \n        n <<= 1;\n    fa.resize(n);\n    fb.resize(n);\n\
    \n    fft(fa, false);\n    fft(fb, false);\n    for (int i = 0; i < n; i++)\n\
    \        fa[i] *= fb[i];\n    fft(fa, true);\n\n    vector<T> result(n);\n   \
    \ for (int i = 0; i < n; i++)\n        result[i] = round(fa[i].real());\n    return\
    \ result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: external/E_fft.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/E_fft.cpp
layout: document
redirect_from:
- /library/external/E_fft.cpp
- /library/external/E_fft.cpp.html
title: external/E_fft.cpp
---
