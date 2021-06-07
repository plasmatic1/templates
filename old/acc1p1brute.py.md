---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "n, q = map(int, input().split())\ns = input()\n\nfor _ in range(q):\n   \
    \ a, b, c = map(int, input().split())\n    print(f'Q: {a} {b} {c}')\n    print(_,\
    \ s)\n    if a == 1:\n        rev = s[b:b+c]\n        print(rev)\n        rev\
    \ = ''.join(reversed(rev))\n        print(rev)\n        s = s[:b] + rev + s[b+c:]\n\
    \    else:\n        print(f'QA: {s[b:b+c]}')\n    print(_, s[6:19])"
  dependsOn: []
  isVerificationFile: false
  path: old/acc1p1brute.py
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/acc1p1brute.py
layout: document
redirect_from:
- /library/old/acc1p1brute.py
- /library/old/acc1p1brute.py.html
title: old/acc1p1brute.py
---
