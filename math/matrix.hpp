#pragma once
#include "../template.hpp"

template <typename T> struct Matrix {
    vector<vector<T>> m;

    Matrix(int N, int M) : m(N, vector<T>(M, T(0))) {}
    Matrix(const vector<vector<T>> &o) : m(o) {}
    Matrix(const Matrix &o) : m(o.m) {}
    static Matrix identity(int N) {
        Matrix res(N, N);
        for (int i = 0; i < N; i++) res[i][i] = T(1);
        return res;
    }

    int N() const { return m.size(); }
    int M() const { return m[0].size(); }
    vector<T>& operator[](int k) { return m[k]; }
    const vector<T>& operator[](int k) const { return m[k]; }
    bool invalid() { return m.size() == 0; } // For invalid returns (i.e. matrix not invertible)

    // Elementwise Stuff
    Matrix& operator+=(const Matrix &o) {
        assert(N() == o.N() && M() == o.M());
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] += o[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix &o) {
        assert(N() == o.N() && M() == o.M());
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] -= o[i][j];
        return *this;
    }

    // Matrix Multiplication
    Matrix& operator*=(const Matrix &o) {
        assert(this->M() == o.N());
        int N = this->N(), M = this->M(), K = o.M();
        vector<vector<T>> res(N, vector<T>(K, T(0)));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < K; j++)
                for (int k = 0; k < M; k++)
                    res[i][j] += m[i][k] * o[k][j];
        m = res;
        return *this;
    }

    // Scalar operations
    Matrix& operator+=(const T &o) {
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] += o;
        return *this;
    }
    Matrix& operator-=(const T &o) {
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] -= o;
        return *this;
    }
    Matrix& operator*=(const T &o) {
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] *= o;
        return *this;
    }

    Matrix& operator-() {
        for (int i = 0; i < N(); i++) for (int j = 0; j < M(); j++)
                m[i][j] = -m[i][j];
    }

    // Reduced row echelon form
    T rref() {
        assert(N() <= M());
        T det = 1;
        for (int i = 0; i < N(); i++) {
            int target = -1;
            for (int j = i; j < N(); j++) {
                if (m[j][i] != 0) {
                    target = j;
                    break;
                }
            }
            if (target == -1) continue;
            if (i != target) {
                m[i].swap(m[target]);
                det *= -1;
            }

            T co = 1 / m[i][i];
            det *= m[i][i];
            for (int j = 0; j < M(); j++)
                m[i][j] *= co;
            for (int j = 0; j < N(); j++)
                if (j != i) {
                    T jco = m[j][i];
                    for (int k = 0; k < M(); k++)
                        m[j][k] -= jco * m[i][k];
                }
        }
        for (int i = 0; i < N(); i++)
            if (m[i][i] == 0)
                return T(0);

        return det;
    }
    static pair<Matrix, T> rref(Matrix m) { T det = m.rref(); return {m, det}; }

    // Augmenting
    void augment(const Matrix &o) {
        assert(N() == o.N());
        for (int i = 0; i < N(); i++)
            m[i].insert(m[i].end(), o[i].begin(), o[i].end());
    }
    static Matrix augment(Matrix m, const Matrix n) { m.augment(n); return m; }

    // Determinant
    T det() const {
        assert(N() == M()); // determinant is only for square matrices lmfao
        Matrix tmp(*this);
        return tmp.rref();
    }

    // Other functions
    static Matrix pow(Matrix x, ll y) {
        assert(x.N() == x.M());
        Matrix res = identity(x.N());
        for (; y; y /= 2) {
            if (y & 1) res *= x;
            x *= x;
        }
        return res;
    }
    static Matrix inv(Matrix x) {
        assert(x.N() == x.M());
        int n = x.N(); x.augment(identity(n));
        if (x.rref() == 0) return Matrix(0, 0); // Determinant == 0 -> no inverse
        Matrix res(x.N(), x.N());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = x[i][j + n];
        return res;
    }
    static Matrix solveLinear(Matrix coeffs, const Matrix &sums) {
        assert(coeffs.N() == coeffs.M() && sums.N() == coeffs.N() && sums.M() == 1);
        int oldN = coeffs.N();
        coeffs.augment(sums);
        coeffs.rref();
        Matrix res(coeffs.N(), 1);
        for (int i = 0; i < oldN; i++)
            res[i][0] = coeffs[i][oldN];
        return res;
    }
};

// Binary operators
#define OP_CMP(op) template <typename T> bool operator op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return lhs.value op rhs.value; }
#define OP_ARI(op) template <typename T> Matrix<T> operator op(const Matrix<T> &lhs, const Matrix<T> &rhs) { return Matrix<T>(lhs) op##= rhs; } \
    template <typename T> Matrix<T> operator op(const Matrix<T> &lhs, T rhs) { return Matrix<T>(lhs) op##= rhs; }
OP_CMP(==) OP_CMP(!=) OP_CMP(<) OP_CMP(>) OP_CMP(<=) OP_CMP(>=)
OP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)
template <typename T> Matrix<T> operator+(T lhs, const Matrix<T> &rhs) { return Matrix<T>(rhs) += lhs; }
template <typename T> Matrix<T> operator*(T lhs, const Matrix<T> &rhs) { return Matrix<T>(rhs) *= lhs; }
#undef OP_CMP
#undef OP_ARI