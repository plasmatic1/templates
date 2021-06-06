struct Fr {
    ll n, d;
    void reduce() {
        ll gv = __gcd(abs(n), abs(d));
        n /= gv; d /= gv;
        if (d < 0) {
            n *= -1; d *= -1;
        }
    }
    Fr(ll a, ll b) : n(a), d(b) { reduce(); }
    Fr(ll x) : n(x), d(1) { reduce(); }
    Fr inv() const { return Fr(d, n); }
    Fr neg() const { return Fr(-n, d); }
    Fr mul(Fr f) const { return Fr(n * f.n, d * f.d); }
    Fr div(Fr f) const { return mul(f.inv()); }
    Fr add(Fr f) const { return Fr(n * f.d + f.n * d, d * f.d); }
    Fr sub(Fr f) const { return add(f.neg()); }
    bool operator==(const Fr o) const { return n == o.n && d == o.d; }
    bool operator!=(const Fr o) const { return n != o.n || d != o.d; }
    bool operator<(const Fr o) const { return n * o.d < o.n * d; }
    bool operator>(const Fr o) const { return o < *this; }
    bool operator<=(const Fr o) const { return !(o < *this); }
    bool operator>=(const Fr o) const { return !(*this < o); }
};
ostream& operator<<(ostream &out, const Fr o) {
    out << o.n << " / " << o.d;
    return out;
}

