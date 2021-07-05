---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test.cpp
    title: test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_determinant.test.cpp
    title: tests/math/matrix_determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_inverse.test.cpp
    title: tests/math/matrix_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/matrix_mul.test.cpp
    title: tests/math/matrix_mul.test.cpp
  - icon: ':x:'
    path: tests/math/matrix_solve_linear.test.cpp
    title: tests/math/matrix_solve_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Defines\n#define fs first\n#define sn second\n#define pb push_back\n\
    #define eb emplace_back\n#define mpr make_pair\n#define mtp make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n// Basic type definitions\n#if __cplusplus ==\
    \ 201703L // CPP17 only things\ntemplate <typename T> using opt_ref = optional<reference_wrapper<T>>;\
    \ // for some templates\n#endif\nusing ll = long long; using ull = unsigned long\
    \ long; using ld = long double;\nusing pii = pair<int, int>; using pll = pair<long\
    \ long, long long>;\n#ifdef __GNUG__\n// PBDS order statistic tree\n#include <ext/pb_ds/assoc_container.hpp>\
    \ // Common file\n#include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\
    template <typename T, class comp = less<T>> using os_tree = tree<T, null_type,\
    \ comp, rb_tree_tag, tree_order_statistics_node_update>;\ntemplate <typename K,\
    \ typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n// HashSet\n#include <ext/pb_ds/assoc_container.hpp>\n\
    template <typename T, class Hash> using hashset = gp_hash_table<T, null_type,\
    \ Hash>;\ntemplate <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\nconst ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };\n#endif\n//\
    \ More utilities\nint SZ(string &v) { return v.length(); }\ntemplate <typename\
    \ C> int SZ(C &v) { return v.size(); }\ntemplate <typename C> void UNIQUE(vector<C>\
    \ &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());\
    \ }\ntemplate <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }\n\
    template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }\nconst\
    \ ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;\n#line 3 \"math/matrix.hpp\"\
    \n\ntemplate <typename T> struct Matrix {\n    vector<vector<T>> m;\n\n    Matrix(int\
    \ N, int M) : m(N, vector<T>(M, T(0))) {}\n    Matrix(const vector<vector<T>>\
    \ &o) : m(o) {}\n    Matrix(const Matrix &o) : m(o.m) {}\n    static Matrix identity(int\
    \ N) {\n        Matrix res(N, N);\n        for (int i = 0; i < N; i++) res[i][i]\
    \ = T(1);\n        return res;\n    }\n\n    int N() const { return m.size();\
    \ }\n    int M() const { return m[0].size(); }\n    vector<T>& operator[](int\
    \ k) { return m[k]; }\n    const vector<T>& operator[](int k) const { return m[k];\
    \ }\n    bool invalid() { return m.size() == 0; } // For invalid returns (i.e.\
    \ matrix not invertible)\n\n    // Elementwise Stuff\n    Matrix& operator+=(const\
    \ Matrix &o) {\n        assert(N() == o.N() && M() == o.M());\n        for (int\
    \ i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n                m[i][j]\
    \ += o[i][j];\n        return *this;\n    }\n    Matrix& operator-=(const Matrix\
    \ &o) {\n        assert(N() == o.N() && M() == o.M());\n        for (int i = 0;\
    \ i < N(); i++) for (int j = 0; j < M(); j++)\n                m[i][j] -= o[i][j];\n\
    \        return *this;\n    }\n\n    // Matrix Multiplication\n    Matrix& operator*=(const\
    \ Matrix &o) {\n        assert(this->M() == o.N());\n        int N = this->N(),\
    \ M = this->M(), K = o.M();\n        vector<vector<T>> res(N, vector<T>(K, T(0)));\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < K; j++)\n\
    \                for (int k = 0; k < M; k++)\n                    res[i][j] +=\
    \ m[i][k] * o[k][j];\n        m = res;\n        return *this;\n    }\n\n    //\
    \ Scalar operations\n    Matrix& operator+=(const T &o) {\n        for (int i\
    \ = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n                m[i][j] +=\
    \ o;\n        return *this;\n    }\n    Matrix& operator-=(const T &o) {\n   \
    \     for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n          \
    \      m[i][j] -= o;\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ T &o) {\n        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n\
    \                m[i][j] *= o;\n        return *this;\n    }\n\n    Matrix& operator-()\
    \ {\n        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n   \
    \             m[i][j] = -m[i][j];\n    }\n\n    // Reduced row echelon form\n\
    \    T rref() {\n        assert(N() <= M());\n        T det = 1;\n        for\
    \ (int i = 0; i < N(); i++) {\n            int target = -1;\n            for (int\
    \ j = i; j < N(); j++) {\n                if (m[j][i] != 0) {\n              \
    \      target = j;\n                    break;\n                }\n          \
    \  }\n            if (target == -1) continue;\n            if (i != target) {\n\
    \                m[i].swap(m[target]);\n                det *= -1;\n         \
    \   }\n\n            T co = 1 / m[i][i];\n            det *= m[i][i];\n      \
    \      for (int j = 0; j < M(); j++)\n                m[i][j] *= co;\n       \
    \     for (int j = 0; j < N(); j++)\n                if (j != i) {\n         \
    \           T jco = m[j][i];\n                    for (int k = 0; k < M(); k++)\n\
    \                        m[j][k] -= jco * m[i][k];\n                }\n      \
    \  }\n        for (int i = 0; i < N(); i++)\n            if (m[i][i] == 0)\n \
    \               return T(0);\n\n        return det;\n    }\n    static pair<Matrix,\
    \ T> rref(Matrix m) { T det = m.rref(); return {m, det}; }\n\n    // Augmenting\n\
    \    void augment(const Matrix &o) {\n        assert(N() == o.N());\n        for\
    \ (int i = 0; i < N(); i++)\n            m[i].insert(m[i].end(), o[i].begin(),\
    \ o[i].end());\n    }\n    static Matrix augment(Matrix m, const Matrix n) { m.augment(n);\
    \ return m; }\n\n    // Determinant\n    T det() const {\n        assert(N() ==\
    \ M()); // determinant is only for square matrices lmfao\n        Matrix tmp(*this);\n\
    \        return tmp.rref();\n    }\n\n    // Other functions\n    static Matrix\
    \ pow(Matrix x, ll y) {\n        assert(x.N() == x.M());\n        Matrix res =\
    \ identity(x.N());\n        for (; y; y /= 2) {\n            if (y & 1) res *=\
    \ x;\n            x *= x;\n        }\n        return res;\n    }\n    static Matrix\
    \ inv(Matrix x) {\n        assert(x.N() == x.M());\n        int n = x.N(); x.augment(identity(n));\n\
    \        if (x.rref() == 0) return Matrix(0, 0); // Determinant == 0 -> no inverse\n\
    \        Matrix res(x.N(), x.N());\n        for (int i = 0; i < n; i++)\n    \
    \        for (int j = 0; j < n; j++)\n                res[i][j] = x[i][j + n];\n\
    \        return res;\n    }\n    static Matrix solveLinear(Matrix coeffs, const\
    \ Matrix &sums) {\n        assert(coeffs.N() == coeffs.M() && sums.N() == coeffs.N()\
    \ && sums.M() == 1);\n        int oldN = coeffs.N();\n        coeffs.augment(sums);\n\
    \        coeffs.rref();\n        Matrix res(coeffs.N(), 1);\n        for (int\
    \ i = 0; i < oldN; i++)\n            res[i][0] = coeffs[i][oldN];\n        return\
    \ res;\n    }\n};\n\n// Binary operators\n#define OP_CMP(op) template <typename\
    \ T> bool operator op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return lhs.value\
    \ op rhs.value; }\n#define OP_ARI(op) template <typename T> Matrix<T> operator\
    \ op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return Matrix<T>(lhs) op##=\
    \ rhs; } \\\n    template <typename T> Matrix<T> operator op(const Matrix<T> &lhs,\
    \ T rhs) { return Matrix<T>(lhs) op##= rhs; }\nOP_CMP(==) OP_CMP(!=) OP_CMP(<)\
    \ OP_CMP(>) OP_CMP(<=) OP_CMP(>=)\nOP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)\ntemplate\
    \ <typename T> Matrix<T> operator+(T lhs, const Matrix<T> &rhs) { return Matrix<T>(rhs)\
    \ += lhs; }\ntemplate <typename T> Matrix<T> operator*(T lhs, const Matrix<T>\
    \ &rhs) { return Matrix<T>(rhs) *= lhs; }\n#undef OP_CMP\n#undef OP_ARI\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate <typename T> struct\
    \ Matrix {\n    vector<vector<T>> m;\n\n    Matrix(int N, int M) : m(N, vector<T>(M,\
    \ T(0))) {}\n    Matrix(const vector<vector<T>> &o) : m(o) {}\n    Matrix(const\
    \ Matrix &o) : m(o.m) {}\n    static Matrix identity(int N) {\n        Matrix\
    \ res(N, N);\n        for (int i = 0; i < N; i++) res[i][i] = T(1);\n        return\
    \ res;\n    }\n\n    int N() const { return m.size(); }\n    int M() const { return\
    \ m[0].size(); }\n    vector<T>& operator[](int k) { return m[k]; }\n    const\
    \ vector<T>& operator[](int k) const { return m[k]; }\n    bool invalid() { return\
    \ m.size() == 0; } // For invalid returns (i.e. matrix not invertible)\n\n   \
    \ // Elementwise Stuff\n    Matrix& operator+=(const Matrix &o) {\n        assert(N()\
    \ == o.N() && M() == o.M());\n        for (int i = 0; i < N(); i++) for (int j\
    \ = 0; j < M(); j++)\n                m[i][j] += o[i][j];\n        return *this;\n\
    \    }\n    Matrix& operator-=(const Matrix &o) {\n        assert(N() == o.N()\
    \ && M() == o.M());\n        for (int i = 0; i < N(); i++) for (int j = 0; j <\
    \ M(); j++)\n                m[i][j] -= o[i][j];\n        return *this;\n    }\n\
    \n    // Matrix Multiplication\n    Matrix& operator*=(const Matrix &o) {\n  \
    \      assert(this->M() == o.N());\n        int N = this->N(), M = this->M(),\
    \ K = o.M();\n        vector<vector<T>> res(N, vector<T>(K, T(0)));\n        for\
    \ (int i = 0; i < N; i++)\n            for (int j = 0; j < K; j++)\n         \
    \       for (int k = 0; k < M; k++)\n                    res[i][j] += m[i][k]\
    \ * o[k][j];\n        m = res;\n        return *this;\n    }\n\n    // Scalar\
    \ operations\n    Matrix& operator+=(const T &o) {\n        for (int i = 0; i\
    \ < N(); i++) for (int j = 0; j < M(); j++)\n                m[i][j] += o;\n \
    \       return *this;\n    }\n    Matrix& operator-=(const T &o) {\n        for\
    \ (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n                m[i][j]\
    \ -= o;\n        return *this;\n    }\n    Matrix& operator*=(const T &o) {\n\
    \        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n       \
    \         m[i][j] *= o;\n        return *this;\n    }\n\n    Matrix& operator-()\
    \ {\n        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)\n   \
    \             m[i][j] = -m[i][j];\n    }\n\n    // Reduced row echelon form\n\
    \    T rref() {\n        assert(N() <= M());\n        T det = 1;\n        for\
    \ (int i = 0; i < N(); i++) {\n            int target = -1;\n            for (int\
    \ j = i; j < N(); j++) {\n                if (m[j][i] != 0) {\n              \
    \      target = j;\n                    break;\n                }\n          \
    \  }\n            if (target == -1) continue;\n            if (i != target) {\n\
    \                m[i].swap(m[target]);\n                det *= -1;\n         \
    \   }\n\n            T co = 1 / m[i][i];\n            det *= m[i][i];\n      \
    \      for (int j = 0; j < M(); j++)\n                m[i][j] *= co;\n       \
    \     for (int j = 0; j < N(); j++)\n                if (j != i) {\n         \
    \           T jco = m[j][i];\n                    for (int k = 0; k < M(); k++)\n\
    \                        m[j][k] -= jco * m[i][k];\n                }\n      \
    \  }\n        for (int i = 0; i < N(); i++)\n            if (m[i][i] == 0)\n \
    \               return T(0);\n\n        return det;\n    }\n    static pair<Matrix,\
    \ T> rref(Matrix m) { T det = m.rref(); return {m, det}; }\n\n    // Augmenting\n\
    \    void augment(const Matrix &o) {\n        assert(N() == o.N());\n        for\
    \ (int i = 0; i < N(); i++)\n            m[i].insert(m[i].end(), o[i].begin(),\
    \ o[i].end());\n    }\n    static Matrix augment(Matrix m, const Matrix n) { m.augment(n);\
    \ return m; }\n\n    // Determinant\n    T det() const {\n        assert(N() ==\
    \ M()); // determinant is only for square matrices lmfao\n        Matrix tmp(*this);\n\
    \        return tmp.rref();\n    }\n\n    // Other functions\n    static Matrix\
    \ pow(Matrix x, ll y) {\n        assert(x.N() == x.M());\n        Matrix res =\
    \ identity(x.N());\n        for (; y; y /= 2) {\n            if (y & 1) res *=\
    \ x;\n            x *= x;\n        }\n        return res;\n    }\n    static Matrix\
    \ inv(Matrix x) {\n        assert(x.N() == x.M());\n        int n = x.N(); x.augment(identity(n));\n\
    \        if (x.rref() == 0) return Matrix(0, 0); // Determinant == 0 -> no inverse\n\
    \        Matrix res(x.N(), x.N());\n        for (int i = 0; i < n; i++)\n    \
    \        for (int j = 0; j < n; j++)\n                res[i][j] = x[i][j + n];\n\
    \        return res;\n    }\n    static Matrix solveLinear(Matrix coeffs, const\
    \ Matrix &sums) {\n        assert(coeffs.N() == coeffs.M() && sums.N() == coeffs.N()\
    \ && sums.M() == 1);\n        int oldN = coeffs.N();\n        coeffs.augment(sums);\n\
    \        coeffs.rref();\n        Matrix res(coeffs.N(), 1);\n        for (int\
    \ i = 0; i < oldN; i++)\n            res[i][0] = coeffs[i][oldN];\n        return\
    \ res;\n    }\n};\n\n// Binary operators\n#define OP_CMP(op) template <typename\
    \ T> bool operator op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return lhs.value\
    \ op rhs.value; }\n#define OP_ARI(op) template <typename T> Matrix<T> operator\
    \ op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return Matrix<T>(lhs) op##=\
    \ rhs; } \\\n    template <typename T> Matrix<T> operator op(const Matrix<T> &lhs,\
    \ T rhs) { return Matrix<T>(lhs) op##= rhs; }\nOP_CMP(==) OP_CMP(!=) OP_CMP(<)\
    \ OP_CMP(>) OP_CMP(<=) OP_CMP(>=)\nOP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)\ntemplate\
    \ <typename T> Matrix<T> operator+(T lhs, const Matrix<T> &rhs) { return Matrix<T>(rhs)\
    \ += lhs; }\ntemplate <typename T> Matrix<T> operator*(T lhs, const Matrix<T>\
    \ &rhs) { return Matrix<T>(rhs) *= lhs; }\n#undef OP_CMP\n#undef OP_ARI"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy:
  - test.cpp
  timestamp: '2021-07-05 01:37:57-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/math/matrix_mul.test.cpp
  - tests/math/matrix_determinant.test.cpp
  - tests/math/matrix_solve_linear.test.cpp
  - tests/math/matrix_inverse.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
