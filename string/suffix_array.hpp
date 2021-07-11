#pragma once
#include "../template.hpp"

const int SA_ONLY = 0, LCP = 1 << 0;
struct suf {
    int idx, r1, r2;

    bool operator<(const suf &o) const {
        return r1 == o.r1 ? r2 < o.r2 : r1 < o.r1;
    }
};
template <const int _MN, const int MIN_VAL, const int MAX_VAL, const int MODE> struct SuffixArray {
    static const int MN = _MN+1, MV = MN+1 > MAX_VAL-MIN_VAL+2 ? MN+1 : MAX_VAL-MIN_VAL+2;
    suf sa[MN];
    int N, crnk[MN];
    vector<int> lcp;

    void rsort_once(function<int(suf&)> key_fun) {
        static int cnt[MV];
        static suf tmp[MN];
        fill(cnt, cnt+MV, 0);
        for (int i = 0; i < N; i++)
            cnt[key_fun(sa[i])]++;
        partial_sum(cnt, cnt+MV, cnt);
        for (int i = N-1; i >= 0; i--)
            tmp[--cnt[key_fun(sa[i])]] = sa[i];
        copy(tmp, tmp+N, sa);
    }

    void rsort() {
        rsort_once([&] (const suf &s) { return s.r2; });
        rsort_once([&] (const suf &s) { return s.r1; });
    }

    template <typename Container> vector<int> solve(int N0, const Container &s) {
        N = N0;
        for (auto i = 0; i < N; i++)
            sa[i] = {i, s[i] - MIN_VAL + 1, i + 1 < N ? s[i + 1] - MIN_VAL + 1 : 0};
        rsort();
        for (int i = 2; i <= N; i *= 2) {
            int ctr = 0;
            suf pre{-1, -1, -1};
            for (auto j = 0; j < N; j++) {
                if (sa[j].r1 != pre.r1 || sa[j].r2 != pre.r2) {
                    ctr++;
                    pre = sa[j];
                }
                sa[j].r1 = ctr;
                crnk[sa[j].idx] = ctr;
            }
            for (auto j = 0; j < N; j++)
                sa[j].r2 = sa[j].idx + i < N ? crnk[sa[j].idx + i] : 0;
            rsort();
        }

        vector<int> res(N);
        for (int i = 0; i < N; i++) res[i] = sa[i].idx;

        if (MODE & LCP) {
            function<int(int, int)> getch = [&] (int idx, int col) {
                col += idx;
                return col < N ? s[col] : MIN_VAL - 1;
            };

            lcp.assign(N, 0);
            vector<int> where(N);
            for (int i = 0; i < N; i++) where[res[i]] = i;
            int cur = 0;
            for (int i = 0; i < N; i++) {
                int t = where[i];
                if (t < N-1)
                    while (getch(i, cur) == getch(res[t+1], cur))
                        cur++;
                lcp[t] = cur;

                if (cur > 0) cur--;
            }
        }

        return res;
    }

#if __cplusplus == 201703L // CPP17 only things
    void bind(opt_ref<vector<int>> lcp0) {
        if (lcp0) lcp.swap(*lcp0);
    }
#endif
};
