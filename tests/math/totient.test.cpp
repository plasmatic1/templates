#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"
#include "../../template.hpp"
#include "../test_utils.hpp"
#include "../../math/totient.hpp"

int main() {
    fast_io();
    print(totient(readi()));
}
