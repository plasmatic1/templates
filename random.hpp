#pragma once
#include "template.hpp"

mt19937 __mt(26022021);
int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(__mt); }
ll randll(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(__mt); }
template <typename T, typename It> T choice(It st, It en) { return *(st + randint(0, en-st-1)); }