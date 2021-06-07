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
  bundledCode: "#line 1 \"point.cpp\"\ntemplate <typename T> struct Vec2 {\n    T\
    \ x, y;\n    Vec2(T x0, T y0) : x(x0), y(y0) {}\n    Vec2() : x(0), y(0) {}\n\n\
    \    bool halfno() { return x < 0 || (x == 0 && y < 0); }\n    Vec2 operator-(const\
    \ Vec2 o) const { return Vec2(x - o.x, y - o.y); }\n    Vec2& operator-=(const\
    \ Vec2 o) { x -= o.x; y -= o.y; return *this; }\n    Vec2 operator+(const Vec2\
    \ o) const { return Vec2(x + o.x, y + o.y); }\n    Vec2& operator+=(const Vec2\
    \ o) { x += o.x; y += o.y; return *this; }\n    Vec2 operator*(const Vec2 o) const\
    \ { return Vec2(x * o.x, y * o.y); }\n    Vec2& operator*=(const Vec2 o) { x *=\
    \ o.x; y *= o.y; return *this; }\n    Vec2 operator/(const Vec2 o) const { return\
    \ Vec2(x / o.x, y / o.y); }\n    Vec2& operator/=(const Vec2 o) { x -= o.x; y\
    \ -= o.y; return *this; }\n    T cross(const Vec2 o) { return x * o.y - y * o.x;\
    \ }\n    T dot(const Vec2 o) { return x * o.x + y * o.y; }\n\n    // Sort points\
    \ clockwise\n    bool operator<(const Vec2 o) const {\n        bool a = halfno(),\
    \ b = o.halfno();\n        return a == b ? cross(o) < 0 : a < b;\n    }\n};\n\
    template <typename T> istream& operator>>(istream &in, Vec2<T> &o) {\n    in >>\
    \ o.x >> o.y;\n    return in;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ out, const Vec2<T> o) {\n    out << \"(x=\" << o.x << \", y=\" << o.y << \"\
    )\";\n    return out;\n}\nusing pt = Vec2<long long>;\n"
  code: "template <typename T> struct Vec2 {\n    T x, y;\n    Vec2(T x0, T y0) :\
    \ x(x0), y(y0) {}\n    Vec2() : x(0), y(0) {}\n\n    bool halfno() { return x\
    \ < 0 || (x == 0 && y < 0); }\n    Vec2 operator-(const Vec2 o) const { return\
    \ Vec2(x - o.x, y - o.y); }\n    Vec2& operator-=(const Vec2 o) { x -= o.x; y\
    \ -= o.y; return *this; }\n    Vec2 operator+(const Vec2 o) const { return Vec2(x\
    \ + o.x, y + o.y); }\n    Vec2& operator+=(const Vec2 o) { x += o.x; y += o.y;\
    \ return *this; }\n    Vec2 operator*(const Vec2 o) const { return Vec2(x * o.x,\
    \ y * o.y); }\n    Vec2& operator*=(const Vec2 o) { x *= o.x; y *= o.y; return\
    \ *this; }\n    Vec2 operator/(const Vec2 o) const { return Vec2(x / o.x, y /\
    \ o.y); }\n    Vec2& operator/=(const Vec2 o) { x -= o.x; y -= o.y; return *this;\
    \ }\n    T cross(const Vec2 o) { return x * o.y - y * o.x; }\n    T dot(const\
    \ Vec2 o) { return x * o.x + y * o.y; }\n\n    // Sort points clockwise\n    bool\
    \ operator<(const Vec2 o) const {\n        bool a = halfno(), b = o.halfno();\n\
    \        return a == b ? cross(o) < 0 : a < b;\n    }\n};\ntemplate <typename\
    \ T> istream& operator>>(istream &in, Vec2<T> &o) {\n    in >> o.x >> o.y;\n \
    \   return in;\n}\ntemplate <typename T> ostream& operator<<(ostream& out, const\
    \ Vec2<T> o) {\n    out << \"(x=\" << o.x << \", y=\" << o.y << \")\";\n    return\
    \ out;\n}\nusing pt = Vec2<long long>;\n"
  dependsOn: []
  isVerificationFile: false
  path: point.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: point.cpp
layout: document
redirect_from:
- /library/point.cpp
- /library/point.cpp.html
title: point.cpp
---
