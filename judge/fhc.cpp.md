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
  bundledCode: "#line 1 \"judge/fhc.cpp\"\nvoid init_file_io() {\n#ifndef LOCAL\n\
    \    const string PROBLEM_ID = \"prob\";\n    freopen((PROBLEM_ID + \".in\").c_str(),\
    \ \"r\", stdin);\n    freopen((PROBLEM_ID + \".out\").c_str(), \"w\", stdout);\n\
    #endif\n}\n\ntemplate <typename T> void read_fhc_array(vector<T> &v, int k, int\
    \ inc = 1, ll dval = -1) {\n    for (auto i = 0; i < k; i++)\n        cin >> v[i];\n\
    \    ll a, b, c, d;\n    cin >> a >> b >> c;\n    if (dval == -1) cin >> d;\n\
    \    else d = dval;\n    for (auto i = k; i < (int)v.size(); i++)\n        v[i]\
    \ = (a * v[i - 2] + b * v[i - 1] + c) % d + inc;\n}\n\nvoid solve() {\n\n}\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\n  \
    \  init_file_io();\n\n    int T;\n    cin >> T;\n    for (int caseno = 1; caseno\
    \ <= T; caseno++) {\n        // Input\n       \n        cout << \"Case #\" <<\
    \ caseno << \": \";\n        solve();\n\n        // Reset\n#ifndef LOCAL\n   \
    \     cerr << \"Done case #\" << caseno << endl;\n#endif\n    }\n\n    return\
    \ 0;\n}\n\n"
  code: "void init_file_io() {\n#ifndef LOCAL\n    const string PROBLEM_ID = \"prob\"\
    ;\n    freopen((PROBLEM_ID + \".in\").c_str(), \"r\", stdin);\n    freopen((PROBLEM_ID\
    \ + \".out\").c_str(), \"w\", stdout);\n#endif\n}\n\ntemplate <typename T> void\
    \ read_fhc_array(vector<T> &v, int k, int inc = 1, ll dval = -1) {\n    for (auto\
    \ i = 0; i < k; i++)\n        cin >> v[i];\n    ll a, b, c, d;\n    cin >> a >>\
    \ b >> c;\n    if (dval == -1) cin >> d;\n    else d = dval;\n    for (auto i\
    \ = k; i < (int)v.size(); i++)\n        v[i] = (a * v[i - 2] + b * v[i - 1] +\
    \ c) % d + inc;\n}\n\nvoid solve() {\n\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n\n    init_file_io();\n\n    int T;\n    cin >> T;\n    for\
    \ (int caseno = 1; caseno <= T; caseno++) {\n        // Input\n       \n     \
    \   cout << \"Case #\" << caseno << \": \";\n        solve();\n\n        // Reset\n\
    #ifndef LOCAL\n        cerr << \"Done case #\" << caseno << endl;\n#endif\n  \
    \  }\n\n    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: judge/fhc.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: judge/fhc.cpp
layout: document
redirect_from:
- /library/judge/fhc.cpp
- /library/judge/fhc.cpp.html
title: judge/fhc.cpp
---
