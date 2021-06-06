#include <bits/stdc++.h>
#define CLASS_NAME a
#define METHOD_NAME b
#define METHOD_SIGNATURE int a
#define METHOD_RETURN int

using namespace std;
using ll = long long;
using ld = long double;
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;

class CLASS_NAME {
    public:
    METHOD_RETURN METHOD_NAME(METHOD_SIGNATURE) {

    }
};

#ifdef LOCAL
template <typename T> T nothing(T t) { return t; }
template <typename T> string pvector(vector<T> t) { string res; for (auto x : t) { res += __generic_tostring(x) + ", "; } return res; }
#define _CHECK(p_fun, ...) cout << "Testing: " #__VA_ARGS__ "\n" << p_fun(p.METHOD_NAME(__VA_ARGS__)) << endl
#define CHECK(...) _CHECK(nothing, __VA_ARGS__)
#define CHECK_VEC(...) _CHECK(pvector, __VA_ARGS__)
int main() {
    CLASS_NAME p;

    return 0;
}
#endif
