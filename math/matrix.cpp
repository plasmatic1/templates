#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using VecType = ll;
constexpr ll MOD = 1e9 + 7;
constexpr bool USE_MOD = true;

using Vec = vector<VecType>; using Mat = vector<Vec>;
void init(Mat &m, int N) {
    m.resize(N);
    for (int i = 0; i < N; i++) m[i].assign(N, 0);
}
void init(Vec &v, int N) { v.assign(N, 0); }
void init_identity(Mat &m, int N) {
    init(m, N);
    for (int i = 0; i < N; i++) m[i][i] = 1;
}
void mul(Mat &res, const Mat &a, const Mat &b) {
    int N = a.size();
    init(res, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j]; if (USE_MOD) { res[i][j] %= MOD; } } } }
}
void mul(Vec &res, const Mat &m, const Vec &v) {
    int N = m.size();
    init(res, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i] += m[i][j] * v[j]; if (USE_MOD) { res[i] %= MOD; } } }
}
Mat mul(const Mat &a, const Mat &b) { Mat ret; mul(ret, a, b); return ret; }
Vec mul(const Mat &m, const Vec &v) { Vec ret; mul(ret, m, v); return ret; }
void exp(Mat &res, ll exp) {
    int N = res.size();
    Mat cpow = res; init_identity(res, N);
    for (ll cxp = 0; exp >> cxp; cxp++) {
        if ((exp >> cxp) & 1)
            res = mul(res, cpow);
        cpow = mul(cpow, cpow);
    }
}
