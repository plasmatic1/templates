#include "../template.hpp"
#include "choose.hpp"
#pragma once

template <typename T> catalan(int N, Choose<T> &c) {
    return c.choose(2*N, N) / (N+1);
}
