template <typename T> struct Vec2 {
    T x, y;
    Vec2(T x0, T y0) : x(x0), y(y0) {}
    Vec2() : x(0), y(0) {}

    bool halfno() { return x < 0 || (x == 0 && y < 0); }
    Vec2 operator-(const Vec2 o) const { return Vec2(x - o.x, y - o.y); }
    Vec2& operator-=(const Vec2 o) { x -= o.x; y -= o.y; return *this; }
    Vec2 operator+(const Vec2 o) const { return Vec2(x + o.x, y + o.y); }
    Vec2& operator+=(const Vec2 o) { x += o.x; y += o.y; return *this; }
    Vec2 operator*(const Vec2 o) const { return Vec2(x * o.x, y * o.y); }
    Vec2& operator*=(const Vec2 o) { x *= o.x; y *= o.y; return *this; }
    Vec2 operator/(const Vec2 o) const { return Vec2(x / o.x, y / o.y); }
    Vec2& operator/=(const Vec2 o) { x -= o.x; y -= o.y; return *this; }
    T cross(const Vec2 o) { return x * o.y - y * o.x; }
    T dot(const Vec2 o) { return x * o.x + y * o.y; }

    // Sort points clockwise
    bool operator<(const Vec2 o) const {
        bool a = halfno(), b = o.halfno();
        return a == b ? cross(o) < 0 : a < b;
    }
};
template <typename T> istream& operator>>(istream &in, Vec2<T> &o) {
    in >> o.x >> o.y;
    return in;
}
template <typename T> ostream& operator<<(ostream& out, const Vec2<T> o) {
    out << "(x=" << o.x << ", y=" << o.y << ")";
    return out;
}
using pt = Vec2<long long>;
