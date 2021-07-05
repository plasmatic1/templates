#pragma once
#include "template.hpp"

mt19937 mt(26022021);
int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(mt); }
ll randll(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(mt); }
