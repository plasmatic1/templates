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
  code: "from random import *\nfrom functools import partial\n\nqc = 500\nn = 500\n\
    its = 1\n\ndef make():\n    getType = partial(choice, list('12'))\n    # getType\
    \ = lambda: '2'\n    getIdx = partial(randint, 1, n)\n\n    s = ''.join(choices(list('01'),\
    \ k=n))\n\n    def lr():\n        l, r = getIdx(), getIdx()\n        while l >\
    \ r:\n            l, r = getIdx(), getIdx()\n        return l, r\n\n    inp =\
    \ ''\n    ans = ''\n\n    inp += f'{n} {qc}\\n'\n    inp += s + '\\n'\n\n    for\
    \ qcounter in range(qc):\n        # if not qcounter&255:\n        #     print(f'Reached\
    \ query {qcounter}')\n\n        l, r = lr()\n        t = getType()\n        inp\
    \ += f'{t} {l - 1} {r - l + 1}\\n'\n\n        if t == '1':\n            ls = list(s)\n\
    \            ls = ls[:l - 1] + list(reversed(ls[l - 1:r])) + ls[r:]\n        \
    \    s = ''.join(ls)\n        elif t == '2':\n            ss = s[l - 1:r]\n  \
    \          #print(ss)\n            best = 0\n            for i in range(len(ss),\
    \ 0, -1):\n                if ('1' * i) in ss:\n                    best = i\n\
    \                    break\n            ans += f'{best}\\n'\n\n    return inp,\
    \ ans\n\n    # with open('in.txt','w') as f:f.write(inp)\n    # with open('jout.txt','w')\
    \ as f: f.write(ans)\n\nfor _ in range(its):\n    make()\n    print('---')\n"
  dependsOn: []
  isVerificationFile: false
  path: old/acc1p1gen.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/acc1p1gen.py
layout: document
redirect_from:
- /library/old/acc1p1gen.py
- /library/old/acc1p1gen.py.html
title: old/acc1p1gen.py
---
