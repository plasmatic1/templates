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
  bundledCode: "#line 1 \"external/mint.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\n// Modular int\ntemplate <typename T> T fpow(T\
    \ x, T y) {\n    if (!y) return 1LL;\n    return fpow(x * x, y >> 1) * ((y & 1)\
    \ ? x : 1LL);\n}\n#define mod_t modular<T, mod>\ntemplate <typename T, T mod>\n\
    struct modular { // modular allen pei\n    void fix() { val = (val % mod + mod)\
    \ % mod; }\n\n    T val;\n    modular(mod_t &x) : val(x.val) {}\n    #define CC(type)\
    \ modular(type val0) : val(val0) { fix(); } \n    CC(int) CC(unsigned int) CC(long\
    \ long) CC(unsigned long long) CC(char) CC(unsigned char) CC(short) CC(unsigned\
    \ short) CC(bool)\n    #undef CC\n\n    #define MAKE_OP(op) template<typename\
    \ U> mod_t& operator op##= (const U &o) { return *this op##= mod_t(o); }  \\\n\
    \    template<typename U> mod_t& operator op##= (const U o) { return *this op##=\
    \ mod_t(o); }\n    mod_t& operator +=(const mod_t &o) const { val = (val + o)\
    \ % mod; return *this; }\n    mod_t& operator -=(const mod_t &o) const { val =\
    \ (val - o + mod) % mod; return *this; }\n    mod_t& operator *=(const mod_t &o)\
    \ const { val = (val * o) % mod; return *this; }\n    mod_t& operator /=(const\
    \ mod_t &o) const { return *this *= fpow(o, mod - 2); }\n    bool operator ==(const\
    \ mod_t &o) const { return val == o.val; }\n    bool operator !=(const mod_t &o)\
    \ const { return !(val == o.val); }\n    bool operator <(const mod_t &o) const\
    \ { return val < o.val; }\n    bool operator >(const mod_t &o) const { return\
    \ val > o.val; }\n    bool operator <=(const mod_t &o) const { return val <= o.val;\
    \ }\n    bool operator >=(const mod_t &o) const { return val >= o.val; }\n   \
    \ mod_t& operator =(const mod_t &o) const { return *this = o; }\n    MAKE_OP(+)\
    \ MAKE_OP(-) MAKE_OP(*) MAKE_OP(/) \n    #undef MAKE_OP\n    mod_t& operator++()\
    \ { return *this += 1; }\n    mod_t& operator--() { return *this -= 1; }\n   \
    \ mod_t operator++(int) { mod_t res(*this); *this += 1; return res; }\n    mod_t\
    \ operator--(int) { mod_t res(*this); *this -= 1; return res; }\n    mod_t operator-()\
    \ const { return mod_t(-value); }\n};\n#define OP_TEMPL template <typename T,\
    \ T mod, typename U>\n#define MAKE_OP(op) OP_TEMPL mod_t operator op(const mod_t\
    \ &l, const mod_t &r) { return mod_t(l) op##= r; }\\\n    OP_TEMPL mod_t operator\
    \ op(const mod_t &l, const U r) { return mod_t(l) op##= r; }\\\n    OP_TEMPL mod_t\
    \ operator op(const U l, const mod_t &r) { return mod_t(l) op##= r; }\nMAKE_OP(+)\
    \ MAKE_OP(-) MAKE_OP(*) MAKE_OP(/)\nOP_TEMPL ostream& operator <<(ostream& out,\
    \ const mod_t t) { out << t.val; return out; }\n#undef MAKE_OP\n#undef mod_t\n\
    const ll MOD = 1e9 + 7;\nusing mint = modular<int, MOD>; using mll = modular<ll,\
    \ MOD>;\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    // Modular int\ntemplate <typename T> T fpow(T x, T y) {\n    if (!y) return 1LL;\n\
    \    return fpow(x * x, y >> 1) * ((y & 1) ? x : 1LL);\n}\n#define mod_t modular<T,\
    \ mod>\ntemplate <typename T, T mod>\nstruct modular { // modular allen pei\n\
    \    void fix() { val = (val % mod + mod) % mod; }\n\n    T val;\n    modular(mod_t\
    \ &x) : val(x.val) {}\n    #define CC(type) modular(type val0) : val(val0) { fix();\
    \ } \n    CC(int) CC(unsigned int) CC(long long) CC(unsigned long long) CC(char)\
    \ CC(unsigned char) CC(short) CC(unsigned short) CC(bool)\n    #undef CC\n\n \
    \   #define MAKE_OP(op) template<typename U> mod_t& operator op##= (const U &o)\
    \ { return *this op##= mod_t(o); }  \\\n    template<typename U> mod_t& operator\
    \ op##= (const U o) { return *this op##= mod_t(o); }\n    mod_t& operator +=(const\
    \ mod_t &o) const { val = (val + o) % mod; return *this; }\n    mod_t& operator\
    \ -=(const mod_t &o) const { val = (val - o + mod) % mod; return *this; }\n  \
    \  mod_t& operator *=(const mod_t &o) const { val = (val * o) % mod; return *this;\
    \ }\n    mod_t& operator /=(const mod_t &o) const { return *this *= fpow(o, mod\
    \ - 2); }\n    bool operator ==(const mod_t &o) const { return val == o.val; }\n\
    \    bool operator !=(const mod_t &o) const { return !(val == o.val); }\n    bool\
    \ operator <(const mod_t &o) const { return val < o.val; }\n    bool operator\
    \ >(const mod_t &o) const { return val > o.val; }\n    bool operator <=(const\
    \ mod_t &o) const { return val <= o.val; }\n    bool operator >=(const mod_t &o)\
    \ const { return val >= o.val; }\n    mod_t& operator =(const mod_t &o) const\
    \ { return *this = o; }\n    MAKE_OP(+) MAKE_OP(-) MAKE_OP(*) MAKE_OP(/) \n  \
    \  #undef MAKE_OP\n    mod_t& operator++() { return *this += 1; }\n    mod_t&\
    \ operator--() { return *this -= 1; }\n    mod_t operator++(int) { mod_t res(*this);\
    \ *this += 1; return res; }\n    mod_t operator--(int) { mod_t res(*this); *this\
    \ -= 1; return res; }\n    mod_t operator-() const { return mod_t(-value); }\n\
    };\n#define OP_TEMPL template <typename T, T mod, typename U>\n#define MAKE_OP(op)\
    \ OP_TEMPL mod_t operator op(const mod_t &l, const mod_t &r) { return mod_t(l)\
    \ op##= r; }\\\n    OP_TEMPL mod_t operator op(const mod_t &l, const U r) { return\
    \ mod_t(l) op##= r; }\\\n    OP_TEMPL mod_t operator op(const U l, const mod_t\
    \ &r) { return mod_t(l) op##= r; }\nMAKE_OP(+) MAKE_OP(-) MAKE_OP(*) MAKE_OP(/)\n\
    OP_TEMPL ostream& operator <<(ostream& out, const mod_t t) { out << t.val; return\
    \ out; }\n#undef MAKE_OP\n#undef mod_t\nconst ll MOD = 1e9 + 7;\nusing mint =\
    \ modular<int, MOD>; using mll = modular<ll, MOD>;\n\n"
  dependsOn: []
  isVerificationFile: false
  path: external/mint.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/mint.cpp
layout: document
redirect_from:
- /library/external/mint.cpp
- /library/external/mint.cpp.html
title: external/mint.cpp
---
