#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../ds/sparse_table.hpp"

int main() {
    fast_io();
    int N = readi(), Q = readi();
    auto v = readv<int>(N);
    SparseTable<Comp> st; st.init(v.begin(), v.end());
    while (Q--) {
        int l = readi()+1, r = readi(); // https://en.cppreference.com/w/cpp/language/eval_order
        print(st.query(l, r));
    }
}
