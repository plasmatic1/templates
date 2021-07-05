#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << x << ", "
#define dblb(s) cout << "[" << s << "] "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

// top 2 are fixes
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

// pragmas
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt"

// random short things
using namespace std::chrono;
ll timeMs() { return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); }

// random stuff
mt19937 __mt(chrono::steady_clock::now().time_since_epoch().count());

#define mtup make_tuple

#define O3 __attribute__((optimize("-O3")))
#define finline __attribute__((always_inline))

// order statistic idea
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;

// gp_hash_table fast
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const { return x ^ RANDOM; }
};
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b) { return (a + b) % MOD; }
ll msub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mmul(ll a, ll b) { return (a * b) % MOD; }
ll fpow(ll x, ll y) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x), y >> 1), (y & 1) ? x : 1LL);
}
ll mdiv(ll x, ll y) { return mmul(x, fpow(y, MOD - 2)); }

// N choose R
vector<ll> fact;
void init_nchooser(int MN) {
    fact.resize(MN + 1);
    fact[0] = 1LL;
    for (int i = 1; i <= MN; i++)
        fact[i] = mmul(fact[i - 1], i);
}
ll choose(ll N, ll K) { return mdiv(fact[N], mmul(fact[K], fact[N - K])); }
ll permute(ll N, ll K) { return mdiv(fact[N], fact[N - K]); }

// Stirling Numbers (1st kind)
// Depends on mod template
// Number of length N permutations with K disjoint cycles
vector<vector<ll>> dp;
ll stir1(ll N, ll K) {
    dp.assign(N + 1, vector<ll>(K + 1, -1));
    return _stir1(N, K);
}
ll _stir1(ll N, ll K) {
    if (!N && !K) return 1LL;
    if (!N || !K) return 0LL;
    ll &ret = dp[N][K];
    if (ret != -1) return ret;
    return ret = madd(mmul(N - 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));
}

// Stirling Numbers (2nd kind)
// Depends on mod and nchooser templates (and calling init_nchooser to init factorial table)
// Number of ways to partition N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does not matter)
// If you want to do it with labelled subsets, just remove the division at the end or multiply by fact[K]
// If empty subsets were allowed, the answer would just be K^N
ll stir2(ll N, ll K) {
    ll res = 0;
    int coeff = 1;
    for (int i = 0; i <= K; i++) {
        res = madd(res, mmul(coeff, mmul(choose(K, i), fpow(K - i, N))));
        coeff *= -1;
    }
    return mdiv(res, fact[K]);
}

// fast modular inverse (with O(N) precalc), 9 lines
const int MN = 1001;
ll inv[MN];
void init_modinv(ll mod) {
    inv[1] = 1LL;
    for (int i = 2; i < MN; i++)
        inv[i] = (mod - ((mod / i) * inv[mod % i]) % mod) % mod;
}
ll mdiv(ll x, ll y) { return (x * inv[y]) % MOD; }

// rabin-karp, 43 lines
const int PC = 2, MOD[PC] = {1000000007, 1000000009}, BASE[PC] = {131, 151};
using HashType = ll;
struct Hash {
    vec<ll> pow[PC], hsh[PC];
    void init(string s) {
        int len = s.length();
        for (int i = 0; i < PC; i++) {
            pow[i].resize(len + 1);
            hsh[i].resize(len + 1);
        }
        for (int i = 0; i < PC; i++) {
            pow[i][0] = 1LL;
            for (int j = 1; j <= len; j++) {
                pow[i][j] = (pow[i][j - 1] * BASE[i]) % MOD[i];
                hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1]) % MOD[i];
            }
        }
    }
    inline ll hash(int i, int L, int R) {
        return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) % MOD[i] + MOD[i]) % MOD[i];
    }
    inline HashType hash(int L, int R) {
        HashType ret = 0; 
        for (int i = 0; i < PC; i++) {
            ret <<= 32LL;
            ret |= hash(i, L, R);
        }
        return ret;
    }
    inline ll hashOther(int i, string &s) {
        ll ret = 0; for (auto ch : s) ret = (ret * BASE[i] + ch) % MOD[i];
        return ret;
    }
    inline HashType hashOther(string &s) {
        HashType ret = 0;
        for (int i = 0; i < PC; i++) {
            ret <<= 32LL;
            ret |= hashOther(i, s);
        }
        return ret;
    }
};

// Define int main for future use
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// assert for max # of iterations
static int its=100;
assert(its--);

    return 0;
}

// Rank compession
#define T int
struct Rank {
    vector<T> rank;
    void init(int n, T* init) {
        rank = vector<T>(init, init + n);
        sort(rank.begin(), rank.end());
        rank.resize(unique(rank.begin(), rank.end()) - rank.begin());
    }
    int get(T x) { return lower_bound(rank.begin(), rank.end(), x) - rank.begin() + 1; }
};
#undef T

// Rank compression (with add function instead of setting all at once)
#define T int
struct Rank {
    vector<T> rank;
    void add(T x) { rank.push_back(x); }
    void init() {
        sort(rank.begin(), rank.end());
        rank.resize(unique(rank.begin(), rank.end()) - rank.begin());
    }
    int get(T x) { return lower_bound(rank.begin(), rank.end(), x) - rank.begin() + 1; }
};
#undef T

// Binary lifting lca (weighted)
const int LG = 18;
int tb[LG][MN], lv[MN];
ll dis[MN];
vector<Ed> g[MN];
void dfsLca(int c, int p, int clv, ll cdis) {
	lv[c] = clv;
	dis[c] = cdis;
	tb[0][c] = p;
	for (auto to : g[c])
		if (to.v ^ p) 
			dfsLca(to.v, c, clv + 1, cdis + to.w);
}
void initSp() {
	memset(tb, -1, sizeof tb);
	dfsLca(1, -1, 0, 0);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= N; j++) {
			int pp = tb[i - 1][j];
			tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
		}
	}
}
int lca(int a, int b) {
	if (a == b) return a;
	if (lv[a] > lv[b]) swap(a, b);
	int delta = lv[b] - lv[a];
	for (int i = 0; i < LG; i++)
		if ((delta >> i) & 1)
			b = tb[i][b];
	if (a == b) return a;
	for (int i = LG - 1; i >= 0; i--) {
		if (tb[i][a] != tb[i][b]) {
			a = tb[i][a];
			b = tb[i][b];
		}
	}
	return tb[0][a];
}
ll qdis(int a, int b) {
	return dis[a] + dis[b] - 2 * dis[lca(a, b)];
}

// Binary lifting lca (unweighted)
const int LG = 18;
int tb[LG][MN], lv[MN];
vector<int> g[MN];
void dfsLca(int c, int p, int clv) {
	lv[c] = clv;
	tb[0][c] = p;
	for (auto to : g[c])
		if (to.v ^ p) 
			dfsLca(to.v, c, clv + 1);
}
void initSp() {
	memset(tb, -1, sizeof tb);
	dfsLca(1, -1, 0);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= N; j++) {
			int pp = tb[i - 1][j];
			tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
		}
	}
}
int lca(int a, int b) {
	if (a == b) return a;
	if (lv[a] > lv[b]) swap(a, b);
	int delta = lv[b] - lv[a];
	for (int i = 0; i < LG; i++)
		if ((delta >> i) & 1)
			b = tb[i][b];
	if (a == b) return a;
	for (int i = LG - 1; i >= 0; i--) {
		if (tb[i][a] != tb[i][b]) {
			a = tb[i][a];
			b = tb[i][b];
		}
	}
	return tb[0][a];
}
ll qdis(int a, int b) {
	return lv[a] + lv[b] - 2 * lv[lca(a, b)];
}

// Sparse Table (RMQ) O(NlogN)/O(1) LCABinaryLift
int dep[MN], fst[MN], tb[LG][MN * 2];
vi tour;
bool cmpDep(const int &a, const int &b) {
    return dep[a] < dep[b];
}
void dfsTour(int c, int p) {
    dep[c] = p == -1 ? 0 : dep[p] + 1;
    tour.pb(c);
    for (int to : g[c])
        if (to != p)
            dfsTour(to, c);
    tour.pb(c);
}
void initLCA(int rt = 1) {
    tour.pb(-1);
    dfsTour(rt, -1);
    int sz = tour.size() - 1;
    reprev(i, sz, 0)
        fst[tour[i]] = i;
    copy(all(tour), tb[0]);
    repi(1, LG) {
        int jmp = 1 << (i - 1), end = sz = jmp;
        repj(1, sz + 1)
            tb[i][j] = min(tb[i - 1][j], tb[i - 1][j + jmp], cmpDep);
    }
}
int lca(int a, int b) {
    a = fst[a]; b = fst[b];
    if (a > b) swap(a, b);
    int bit = 31 - __builtin_clz(b - a + 1);
    return min(tb[bit][a], tb[bit][b - (1 << bit) + 1], cmpDep);
}

// Rabin karp but with random base
using namespace std::chrono;
ll timeMs() { return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); }
 
const int MH = 10001;
mt19937 __mt(timeMs());
vi primes;
bool isprime[MH];
 
void init() {
    memset(isprime, true, sizeof isprime);
    repi(2, MH) {
        if (isprime[i]) {
            for (int j = i + i; j < MH; j += i)
                isprime[j] = false;
            if (i > 100)
                primes.pb(i);
        }
    }
}
const int PC = 2;
ll MOD[PC] = {1000000007, 1000000009}, BASE[PC] = {};
 
uniform_int_distribution<int> dis;
void initPr() {
    init();
    dis = uniform_int_distribution<int>(0, primes.size() - 1);
}
 
void getPr() {
    repi(0, PC) BASE[i] = primes[dis(__mt)];
}
 
const int MN = 1e6 + 1;
using HashType = ll;
struct Hash {
    vec<ll> pow[PC], hsh[PC];
    void initVec(int len) {
        for (int i = 0; i < PC; i++) {
            pow[i].resize(len);
            hsh[i].resize(len);
        }
    }
    void init(string s) {
        int len = s.length();
        for (int i = 0; i < PC; i++) {
            pow[i][0] = 1LL;
            for (int j = 1; j <= len; j++) {
                pow[i][j] = (pow[i][j - 1] * BASE[i]) % MOD[i];
                hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1]) % MOD[i];
            }
        }
    }
    inline ll hash(int i, int L, int R) {
        return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) % MOD[i] + MOD[i]) % MOD[i];
    }
    inline HashType hash(int L, int R) {
        HashType ret = 0; 
        for (int i = 0; i < PC; i++) {
            ret <<= 32LL;
            ret |= hash(i, L, R);
        }
        return ret;
    }
};
