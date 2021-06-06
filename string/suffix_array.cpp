struct suf {
    int idx, r1, r2;
    bool operator<(const suf &o) const {
        return r1 == o.r1 ? r2 < o.r2 : r1 < o.r1;
    }
};

const int MN = 1e5 + 1;
int N, M;
string A, B;

// SA
suf sa[MN];
int crnk[MN];
char getc(int idx, int col) {
    int cidx = sa[idx].idx + col;
    if (cidx >= N) return '$';
    return A[cidx];
}

void build() {
    for (auto i = 0; i < N; i++)
        sa[i] = {i, A[i] - 'a', i + 1 < N ? A[i + 1] - 'a' : -1};
    sort(sa, sa + N);
    for (int i = 2; i <= N; i *= 2) {
        int ctr = 0;
        suf pre{-1, -INF, -INF};
        for (auto j = 0; j < N; j++) {
            if (sa[j].r1 != pre.r1 || sa[j].r2 != pre.r2) {
                pre = sa[j];
                ctr++;
            }
            sa[j].r1 = ctr;
            crnk[sa[j].idx] = ctr;
        }
        for (auto j = 0; j < N; j++)
            sa[j].r2 = sa[j].idx + i < N ? crnk[sa[j].idx + i] : -1;
        sort(sa, sa + N);
    }
}
