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
  bundledCode: "#line 1 \"external/fft.cpp\"\nusing cd = complex<double>;\nusing VT\
    \ = int;\nconst double PI = acos(-1);\n\nvoid fft(vector<cd> & a, bool invert)\
    \ {\n    int n = a.size();\n    if (n == 1)\n        return;\n\n    vector<cd>\
    \ a0(n / 2), a1(n / 2);\n    for (int i = 0; 2 * i < n; i++) {\n        a0[i]\
    \ = a[2*i];\n        a1[i] = a[2*i+1];\n    }\n    fft(a0, invert);\n    fft(a1,\
    \ invert);\n\n    double ang = 2 * PI / n * (invert ? -1 : 1);\n    cd w(1), wn(cos(ang),\
    \ sin(ang));\n    for (int i = 0; 2 * i < n; i++) {\n        a[i] = a0[i] + w\
    \ * a1[i];\n        a[i + n/2] = a0[i] - w * a1[i];\n        if (invert) {\n \
    \           a[i] /= 2;\n            a[i + n/2] /= 2;\n        }\n        w *=\
    \ wn;\n    }\n}\nvector<VT> multiply(vector<VT> const& a, vector<VT> const& b)\
    \ {\n    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n    int n\
    \ = 1;\n    while (n < (int)(a.size() + b.size())) \n        n <<= 1;\n    fa.resize(n);\n\
    \    fb.resize(n);\n\n    fft(fa, false);\n    fft(fb, false);\n    for (int i\
    \ = 0; i < n; i++)\n        fa[i] *= fb[i];\n    fft(fa, true);\n\n    vector<VT>\
    \ result(n);\n    for (int i = 0; i < n; i++)\n        result[i] = round(fa[i].real());\n\
    \    return result;\n}\n\n"
  code: "using cd = complex<double>;\nusing VT = int;\nconst double PI = acos(-1);\n\
    \nvoid fft(vector<cd> & a, bool invert) {\n    int n = a.size();\n    if (n ==\
    \ 1)\n        return;\n\n    vector<cd> a0(n / 2), a1(n / 2);\n    for (int i\
    \ = 0; 2 * i < n; i++) {\n        a0[i] = a[2*i];\n        a1[i] = a[2*i+1];\n\
    \    }\n    fft(a0, invert);\n    fft(a1, invert);\n\n    double ang = 2 * PI\
    \ / n * (invert ? -1 : 1);\n    cd w(1), wn(cos(ang), sin(ang));\n    for (int\
    \ i = 0; 2 * i < n; i++) {\n        a[i] = a0[i] + w * a1[i];\n        a[i + n/2]\
    \ = a0[i] - w * a1[i];\n        if (invert) {\n            a[i] /= 2;\n      \
    \      a[i + n/2] /= 2;\n        }\n        w *= wn;\n    }\n}\nvector<VT> multiply(vector<VT>\
    \ const& a, vector<VT> const& b) {\n    vector<cd> fa(a.begin(), a.end()), fb(b.begin(),\
    \ b.end());\n    int n = 1;\n    while (n < (int)(a.size() + b.size())) \n   \
    \     n <<= 1;\n    fa.resize(n);\n    fb.resize(n);\n\n    fft(fa, false);\n\
    \    fft(fb, false);\n    for (int i = 0; i < n; i++)\n        fa[i] *= fb[i];\n\
    \    fft(fa, true);\n\n    vector<VT> result(n);\n    for (int i = 0; i < n; i++)\n\
    \        result[i] = round(fa[i].real());\n    return result;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: external/fft.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/fft.cpp
layout: document
redirect_from:
- /library/external/fft.cpp
- /library/external/fft.cpp.html
title: external/fft.cpp
---
