#pragma once
#include "../template.hpp"

// Sparse table is 1-indexed
// Comparator for range MIN query
// When calling init, st should point to the start (0-indexed).  (i.e. if you stored data in A[1], A[2], ..., you should call init with (A+1, A+N+1)
// However, queries are 1-indexed and inclusive
struct Comp {
    using Data = int;
    Data merge(Data a, Data b) { return min(a, b); }
};
template <class Comp> struct SparseTable {
    using Data = typename Comp::Data; Comp C;
    vector<vector<Data>> tb;
    int N, lg;
    template <typename It> void init(It st, It end) {
        N = end-st; lg = __lg(N);
        tb.assign(lg+1, vector<Data>(N+1));
        copy(st, end, tb[0].begin()+1);
        for (auto i = 1; i <= lg; i++) {
            int jmp = 1 << (i-1), end = N - (1<<i) + 1;
            for (auto j = 1; j <= end; j++)
                tb[i][j] = C.merge(tb[i-1][j], tb[i-1][j+jmp]);
        }
    }
    Data query(int l, int r) {
        int bit = __lg(r-l+1);
        return C.merge(tb[bit][l], tb[bit][r-(1<<bit)+1]);
    }
};
