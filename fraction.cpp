#pragma once
#include "template.hpp"

template <typename T = int64_t> struct Fraction {
    T n, d;
    void reduce() {
        T gv = __gcd(abs(n), abs(d));
        n /= gv; d /= gv;
        if (d < 0) {
            n *= -1; d *= -1;
        }
    }
    Fraction(T a, T b) : n(a), d(b) { reduce(); }
    Fraction(T x) : n(x), d(1) { reduce(); }
    Fraction inv() const { return Fraction(d, n); }
    Fraction neg() const { return Fraction(-n, d); }
    Fraction mul(Fraction f) const { return Fraction(n * f.n, d * f.d); }
    Fraction div(Fraction f) const { return mul(f.inv()); }
    Fraction add(Fraction f) const { return Fraction(n * f.d + f.n * d, d * f.d); }
    Fraction sub(Fraction f) const { return add(f.neg()); }
    bool operator==(const Fraction o) const { return n == o.n && d == o.d; }
    bool operator!=(const Fraction o) const { return n != o.n || d != o.d; }
    bool operator<(const Fraction o) const { return n * o.d < o.n * d; }
    bool operator>(const Fraction o) const { return o < *this; }
    bool operator<=(const Fraction o) const { return !(o < *this); }
    bool operator>=(const Fraction o) const { return !(*this < o); }
};
ostream& operator<<(ostream &out, const Fraction o) {
    out << o.n << " / " << o.d;
    return out;
}

