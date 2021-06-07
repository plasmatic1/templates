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
  bundledCode: "#line 1 \"judge/topcoder.cpp\"\n#include <bits/stdc++.h>\n#define\
    \ CLASS_NAME a\n#define METHOD_NAME b\n#define METHOD_SIGNATURE int a\n#define\
    \ METHOD_RETURN int\n\nusing namespace std;\nusing ll = long long;\nusing ld =\
    \ long double;\n#define db(x) cout << (#x) << \": \" << (x) << \", \"\n#define\
    \ dblb(s) cout << \"[\" << (s) << \"] \"\n#define dba(alias, x) cout << (alias)\
    \ << \": \" << (x) << \", \"\ntemplate<typename F> inline string __generic_tostring(F\
    \ f) { stringstream ss; ss << f; return ss.str(); }\ntemplate<typename F> inline\
    \ string __join_comma(F f) {return __generic_tostring(f);}\ntemplate<typename\
    \ F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f)\
    \ + \", \" + __join_comma(r...); }\n#define dbp(alias, ...) cout << (alias) <<\
    \ \": (\" << __join_comma(__VA_ARGS__) << \"), \"\n#define dbbin(x, n) cout <<\
    \ (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x, n) cout << (#x) <<\
    \ \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout << endl;\n\nclass\
    \ CLASS_NAME {\n    public:\n    METHOD_RETURN METHOD_NAME(METHOD_SIGNATURE) {\n\
    \n    }\n};\n\n#ifdef LOCAL\ntemplate <typename T> T nothing(T t) { return t;\
    \ }\ntemplate <typename T> string pvector(vector<T> t) { string res; for (auto\
    \ x : t) { res += __generic_tostring(x) + \", \"; } return res; }\n#define _CHECK(p_fun,\
    \ ...) cout << \"Testing: \" #__VA_ARGS__ \"\\n\" << p_fun(p.METHOD_NAME(__VA_ARGS__))\
    \ << endl\n#define CHECK(...) _CHECK(nothing, __VA_ARGS__)\n#define CHECK_VEC(...)\
    \ _CHECK(pvector, __VA_ARGS__)\nint main() {\n    CLASS_NAME p;\n\n    return\
    \ 0;\n}\n#endif\n"
  code: "#include <bits/stdc++.h>\n#define CLASS_NAME a\n#define METHOD_NAME b\n#define\
    \ METHOD_SIGNATURE int a\n#define METHOD_RETURN int\n\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\n#define db(x) cout << (#x) <<\
    \ \": \" << (x) << \", \"\n#define dblb(s) cout << \"[\" << (s) << \"] \"\n#define\
    \ dba(alias, x) cout << (alias) << \": \" << (x) << \", \"\ntemplate<typename\
    \ F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return\
    \ ss.str(); }\ntemplate<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}\n\
    template<typename F, typename... R> string __join_comma(F f, R... r) { return\
    \ __generic_tostring(f) + \", \" + __join_comma(r...); }\n#define dbp(alias, ...)\
    \ cout << (alias) << \": (\" << __join_comma(__VA_ARGS__) << \"), \"\n#define\
    \ dbbin(x, n) cout << (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x,\
    \ n) cout << (#x) << \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout\
    \ << endl;\n\nclass CLASS_NAME {\n    public:\n    METHOD_RETURN METHOD_NAME(METHOD_SIGNATURE)\
    \ {\n\n    }\n};\n\n#ifdef LOCAL\ntemplate <typename T> T nothing(T t) { return\
    \ t; }\ntemplate <typename T> string pvector(vector<T> t) { string res; for (auto\
    \ x : t) { res += __generic_tostring(x) + \", \"; } return res; }\n#define _CHECK(p_fun,\
    \ ...) cout << \"Testing: \" #__VA_ARGS__ \"\\n\" << p_fun(p.METHOD_NAME(__VA_ARGS__))\
    \ << endl\n#define CHECK(...) _CHECK(nothing, __VA_ARGS__)\n#define CHECK_VEC(...)\
    \ _CHECK(pvector, __VA_ARGS__)\nint main() {\n    CLASS_NAME p;\n\n    return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: judge/topcoder.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: judge/topcoder.cpp
layout: document
redirect_from:
- /library/judge/topcoder.cpp
- /library/judge/topcoder.cpp.html
title: judge/topcoder.cpp
---
