---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/template_additons.cpp\"\n#pragma region\n#include <bits/stdc++.h>\n\
    using namespace std;\n// Common Type shorteners and int128\nusing ll = long long;\
    \ using ull = unsigned long long; using ld = long double;\nusing pii = pair<int,\
    \ int>; using pll = pair<ll, ll>;\ntemplate <typename T> using vec = vector<T>;\n\
    template <typename K, typename V> using umap = unordered_map<K, V>; template <typename\
    \ K> using uset = unordered_set<K>;\nusing vi = vec<int>; using vl = vec<ll>;\
    \ using vpi = vec<pii>; using vpl = vec<pll>;\n#ifdef __SIZEOF_INT128__\nusing\
    \ int128 = __int128_t; using uint128 = __uint128_t;\n#endif\ntemplate<typename\
    \ I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x\
    \ /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string\n//\
    \ Shorthand Macros\n#define INF 0x3f3f3f3f\n#define LLINF 0x3f3f3f3f3f3f3f3f\n\
    #define mpr make_pair\n#define pb push_back\n#define popcount __builtin_popcount\n\
    #define clz __builtin_clz\n#define ctz __builtin_ctz\n// Shorthand Function Macros\n\
    #define sz(x) ((int)((x).size()))\n#define all(x) (x).begin(), (x).end()\n#define\
    \ rep(i, a, b) for (__typeof(a) i = a; i < b; i++)\n#define reprev(i, a, b) for\
    \ (__typeof(a) i = a; i > b; i--)\n#define repi(a, b) rep(i, a, b)\n#define repj(a,\
    \ b) rep(j, a, b)\n#define repk(a, b) rep(k, a, b)\n#define Cmplt(type) bool operator<(const\
    \ type &o) const\n#define Cmpgt(type) bool operator>(const type &o) const\n#define\
    \ Cmpfn(name, type) bool name(const type &a, const type &b)\n#define Inop(type)\
    \ istream& operator>>(istream& in, type &o)\n#define Outop(type) ostream& operator<<(ostream&\
    \ out, type o)\n#define Pow2(x) (1LL << (x))\n#define scn(type, ...) type __VA_ARGS__;\
    \ scan(__VA_ARGS__) // scn -> Short for SCan New\n// Shorthand Functions\ntemplate<typename\
    \ T> inline void maxa(T& st, T v) { st = max(st, v); }\ntemplate<typename T> inline\
    \ void mina(T& st, T v) { st = min(st, v); }\ninline void setprec(ostream& out,\
    \ int prec) { out << setprecision(prec) << fixed; }\n// Out operators and printing\
    \ for arrays and vectors\ntemplate <typename T> ostream& operator<<(ostream& out,vector<T>\
    \ iter){out<<\"[\";for(auto t:iter){out<<t<<\", \";}out<<\"]\";return out;}\n\
    template <typename T> string arrayStr(T *arr,int sz){string ret = \"[\";for(int\
    \ i=0;i<sz;i++){ret+=to_string(arr[i])+\", \"; } return ret + \"]\";}\ntemplate\
    \ <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<\"\
    \ \"; } cout<<\"\\n\";}\n// I/O Operations\ninline void scan(){}\ntemplate<typename\
    \ F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}\ntemplate\
    \ <typename F> inline void println(F t){cout<<t<<'\\n';}\ntemplate<typename F,\
    \ typename... R> inline void println(F f,R... r){cout<<f<<\" \";println(r...);}\n\
    inline void print(){}\ntemplate<typename F, typename... R> inline void print(F\
    \ f,R... r){cout<<f;print(r...);}\n// Debugging\n#define db(x) cout << (#x) <<\
    \ \": \" << x << \", \"\n#define dblb(s) cout << \"[\" << s << \"] \"\n#define\
    \ dbbin(x, n) cout << (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x,\
    \ n) cout << (#x) << \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout\
    \ << endl;\n#pragma endregion\n\n// top 2 are fixes\n#define db(x) cout << (#x)\
    \ << \": \" << (x) << \", \"\n#define dblb(s) cout << \"[\" << (s) << \"] \"\n\
    #define dba(alias, x) cout << (alias) << \": \" << (x) << \", \"\ntemplate<typename\
    \ F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return\
    \ ss.str(); }\ntemplate<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}\n\
    template<typename F, typename... R> string __join_comma(F f, R... r) { return\
    \ __generic_tostring(f) + \", \" + __join_comma(r...); }\n#define dbp(alias, ...)\
    \ cout << (alias) << \": (\" << __join_comma(__VA_ARGS__) << \"), \"\n#define\
    \ dbbin(x, n) cout << (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x,\
    \ n) cout << (#x) << \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout\
    \ << endl;\n\n// pragmas\n#pragma GCC optimize \"Ofast\"\n#pragma GCC optimize\
    \ \"unroll-loops\"\n#pragma GCC target \"sse,sse2,sse3,sse4,abm,avx,mmx,popcnt\"\
    \n\n// random short things\nusing namespace std::chrono;\nll timeMs() { return\
    \ duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();\
    \ }\n\n// random stuff\nmt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n#define mtup make_tuple\n\n#define O3 __attribute__((optimize(\"-O3\")))\n#define\
    \ finline __attribute__((always_inline))\n\n// order statistic idea\n#include\
    \ <ext/pb_ds/assoc_container.hpp> // Common file \n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds; \ntemplate <typename T, class comp = less<T>> using\
    \ os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\
    template <typename K, typename V, class comp = less<K>> using treemap = tree<K,\
    \ V, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\n// gp_hash_table\
    \ fast\n#line 98 \"old/template_additons.cpp\"\nusing namespace __gnu_pbds;\n\
    const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {\n    ll operator()(ll x) const { return x ^ RANDOM; }\n};\ntemplate\
    \ <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;\n\
    template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\n\nconst ll MOD = 1e9 + 7;\nll madd(ll a, ll b) { return (a + b) %\
    \ MOD; }\nll msub(ll a, ll b) { return (a - b + MOD) % MOD; }\nll mmul(ll a, ll\
    \ b) { return (a * b) % MOD; }\nll fpow(ll x, ll y) {\n    if (!y) return 1LL;\n\
    \    return mmul(fpow(mmul(x, x), y >> 1), (y & 1) ? x : 1LL);\n}\nll mdiv(ll\
    \ x, ll y) { return mmul(x, fpow(y, MOD - 2)); }\n\n// N choose R\nvector<ll>\
    \ fact;\nvoid init_nchooser(int MN) {\n    fact.resize(MN + 1);\n    fact[0] =\
    \ 1LL;\n    for (int i = 1; i <= MN; i++)\n        fact[i] = mmul(fact[i - 1],\
    \ i);\n}\nll choose(ll N, ll K) { return mdiv(fact[N], mmul(fact[K], fact[N -\
    \ K])); }\nll permute(ll N, ll K) { return mdiv(fact[N], fact[N - K]); }\n\n//\
    \ Stirling Numbers (1st kind)\n// Depends on mod template\n// Number of length\
    \ N permutations with K disjoint cycles\nvector<vector<ll>> dp;\nll stir1(ll N,\
    \ ll K) {\n    dp.assign(N + 1, vector<ll>(K + 1, -1));\n    return _stir1(N,\
    \ K);\n}\nll _stir1(ll N, ll K) {\n    if (!N && !K) return 1LL;\n    if (!N ||\
    \ !K) return 0LL;\n    ll &ret = dp[N][K];\n    if (ret != -1) return ret;\n \
    \   return ret = madd(mmul(N - 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));\n\
    }\n\n// Stirling Numbers (2nd kind)\n// Depends on mod and nchooser templates\
    \ (and calling init_nchooser to init factorial table)\n// Number of ways to partition\
    \ N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does\
    \ not matter)\n// If you want to do it with labelled subsets, just remove the\
    \ division at the end or multiply by fact[K]\n// If empty subsets were allowed,\
    \ the answer would just be K^N\nll stir2(ll N, ll K) {\n    ll res = 0;\n    int\
    \ coeff = 1;\n    for (int i = 0; i <= K; i++) {\n        res = madd(res, mmul(coeff,\
    \ mmul(choose(K, i), fpow(K - i, N))));\n        coeff *= -1;\n    }\n    return\
    \ mdiv(res, fact[K]);\n}\n\n// fast modular inverse (with O(N) precalc), 9 lines\n\
    const int MN = 1001;\nll inv[MN];\nvoid init_modinv(ll mod) {\n    inv[1] = 1LL;\n\
    \    for (int i = 2; i < MN; i++)\n        inv[i] = (mod - ((mod / i) * inv[mod\
    \ % i]) % mod) % mod;\n}\nll mdiv(ll x, ll y) { return (x * inv[y]) % MOD; }\n\
    \n// rabin-karp, 43 lines\nconst int PC = 2, MOD[PC] = {1000000007, 1000000009},\
    \ BASE[PC] = {131, 151};\nusing HashType = ll;\nstruct Hash {\n    vec<ll> pow[PC],\
    \ hsh[PC];\n    void init(string s) {\n        int len = s.length();\n       \
    \ for (int i = 0; i < PC; i++) {\n            pow[i].resize(len + 1);\n      \
    \      hsh[i].resize(len + 1);\n        }\n        for (int i = 0; i < PC; i++)\
    \ {\n            pow[i][0] = 1LL;\n            for (int j = 1; j <= len; j++)\
    \ {\n                pow[i][j] = (pow[i][j - 1] * BASE[i]) % MOD[i];\n       \
    \         hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1]) % MOD[i];\n       \
    \     }\n        }\n    }\n    inline ll hash(int i, int L, int R) {\n       \
    \ return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) % MOD[i] + MOD[i]) %\
    \ MOD[i];\n    }\n    inline HashType hash(int L, int R) {\n        HashType ret\
    \ = 0; \n        for (int i = 0; i < PC; i++) {\n            ret <<= 32LL;\n \
    \           ret |= hash(i, L, R);\n        }\n        return ret;\n    }\n   \
    \ inline ll hashOther(int i, string &s) {\n        ll ret = 0; for (auto ch :\
    \ s) ret = (ret * BASE[i] + ch) % MOD[i];\n        return ret;\n    }\n    inline\
    \ HashType hashOther(string &s) {\n        HashType ret = 0;\n        for (int\
    \ i = 0; i < PC; i++) {\n            ret <<= 32LL;\n            ret |= hashOther(i,\
    \ s);\n        }\n        return ret;\n    }\n};\n\n// Define int main for future\
    \ use\nint main(){\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\
    \n// assert for max # of iterations\nstatic int its=100;\nassert(its--);\n\n \
    \   return 0;\n}\n\n// Rank compession\n#define T int\nstruct Rank {\n    vector<T>\
    \ rank;\n    void init(int n, T* init) {\n        rank = vector<T>(init, init\
    \ + n);\n        sort(rank.begin(), rank.end());\n        rank.resize(unique(rank.begin(),\
    \ rank.end()) - rank.begin());\n    }\n    int get(T x) { return lower_bound(rank.begin(),\
    \ rank.end(), x) - rank.begin() + 1; }\n};\n#undef T\n\n// Rank compression (with\
    \ add function instead of setting all at once)\n#define T int\nstruct Rank {\n\
    \    vector<T> rank;\n    void add(T x) { rank.push_back(x); }\n    void init()\
    \ {\n        sort(rank.begin(), rank.end());\n        rank.resize(unique(rank.begin(),\
    \ rank.end()) - rank.begin());\n    }\n    int get(T x) { return lower_bound(rank.begin(),\
    \ rank.end(), x) - rank.begin() + 1; }\n};\n#undef T\n\n// Binary lifting lca\
    \ (weighted)\nconst int LG = 18;\nint tb[LG][MN], lv[MN];\nll dis[MN];\nvector<Ed>\
    \ g[MN];\nvoid dfsLca(int c, int p, int clv, ll cdis) {\n\tlv[c] = clv;\n\tdis[c]\
    \ = cdis;\n\ttb[0][c] = p;\n\tfor (auto to : g[c])\n\t\tif (to.v ^ p) \n\t\t\t\
    dfsLca(to.v, c, clv + 1, cdis + to.w);\n}\nvoid initSp() {\n\tmemset(tb, -1, sizeof\
    \ tb);\n\tdfsLca(1, -1, 0, 0);\n\tfor (int i = 1; i < LG; i++) {\n\t\tfor (int\
    \ j = 1; j <= N; j++) {\n\t\t\tint pp = tb[i - 1][j];\n\t\t\ttb[i][j] = pp ==\
    \ -1 ? -1 : tb[i - 1][pp];\n\t\t}\n\t}\n}\nint lca(int a, int b) {\n\tif (a ==\
    \ b) return a;\n\tif (lv[a] > lv[b]) swap(a, b);\n\tint delta = lv[b] - lv[a];\n\
    \tfor (int i = 0; i < LG; i++)\n\t\tif ((delta >> i) & 1)\n\t\t\tb = tb[i][b];\n\
    \tif (a == b) return a;\n\tfor (int i = LG - 1; i >= 0; i--) {\n\t\tif (tb[i][a]\
    \ != tb[i][b]) {\n\t\t\ta = tb[i][a];\n\t\t\tb = tb[i][b];\n\t\t}\n\t}\n\treturn\
    \ tb[0][a];\n}\nll qdis(int a, int b) {\n\treturn dis[a] + dis[b] - 2 * dis[lca(a,\
    \ b)];\n}\n\n// Binary lifting lca (unweighted)\nconst int LG = 18;\nint tb[LG][MN],\
    \ lv[MN];\nvector<int> g[MN];\nvoid dfsLca(int c, int p, int clv) {\n\tlv[c] =\
    \ clv;\n\ttb[0][c] = p;\n\tfor (auto to : g[c])\n\t\tif (to.v ^ p) \n\t\t\tdfsLca(to.v,\
    \ c, clv + 1);\n}\nvoid initSp() {\n\tmemset(tb, -1, sizeof tb);\n\tdfsLca(1,\
    \ -1, 0);\n\tfor (int i = 1; i < LG; i++) {\n\t\tfor (int j = 1; j <= N; j++)\
    \ {\n\t\t\tint pp = tb[i - 1][j];\n\t\t\ttb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];\n\
    \t\t}\n\t}\n}\nint lca(int a, int b) {\n\tif (a == b) return a;\n\tif (lv[a] >\
    \ lv[b]) swap(a, b);\n\tint delta = lv[b] - lv[a];\n\tfor (int i = 0; i < LG;\
    \ i++)\n\t\tif ((delta >> i) & 1)\n\t\t\tb = tb[i][b];\n\tif (a == b) return a;\n\
    \tfor (int i = LG - 1; i >= 0; i--) {\n\t\tif (tb[i][a] != tb[i][b]) {\n\t\t\t\
    a = tb[i][a];\n\t\t\tb = tb[i][b];\n\t\t}\n\t}\n\treturn tb[0][a];\n}\nll qdis(int\
    \ a, int b) {\n\treturn lv[a] + lv[b] - 2 * lv[lca(a, b)];\n}\n\n// Sparse Table\
    \ (RMQ) O(NlogN)/O(1) LCABinaryLift\nint dep[MN], fst[MN], tb[LG][MN * 2];\nvi\
    \ tour;\nbool cmpDep(const int &a, const int &b) {\n    return dep[a] < dep[b];\n\
    }\nvoid dfsTour(int c, int p) {\n    dep[c] = p == -1 ? 0 : dep[p] + 1;\n    tour.pb(c);\n\
    \    for (int to : g[c])\n        if (to != p)\n            dfsTour(to, c);\n\
    \    tour.pb(c);\n}\nvoid initLCA(int rt = 1) {\n    tour.pb(-1);\n    dfsTour(rt,\
    \ -1);\n    int sz = tour.size() - 1;\n    reprev(i, sz, 0)\n        fst[tour[i]]\
    \ = i;\n    copy(all(tour), tb[0]);\n    repi(1, LG) {\n        int jmp = 1 <<\
    \ (i - 1), end = sz = jmp;\n        repj(1, sz + 1)\n            tb[i][j] = min(tb[i\
    \ - 1][j], tb[i - 1][j + jmp], cmpDep);\n    }\n}\nint lca(int a, int b) {\n \
    \   a = fst[a]; b = fst[b];\n    if (a > b) swap(a, b);\n    int bit = 31 - __builtin_clz(b\
    \ - a + 1);\n    return min(tb[bit][a], tb[bit][b - (1 << bit) + 1], cmpDep);\n\
    }\n\n// Rabin karp but with random base\nusing namespace std::chrono;\nll timeMs()\
    \ { return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();\
    \ }\n \nconst int MH = 10001;\nmt19937 mt(timeMs());\nvi primes;\nbool isprime[MH];\n\
    \ \nvoid init() {\n    memset(isprime, true, sizeof isprime);\n    repi(2, MH)\
    \ {\n        if (isprime[i]) {\n            for (int j = i + i; j < MH; j += i)\n\
    \                isprime[j] = false;\n            if (i > 100)\n             \
    \   primes.pb(i);\n        }\n    }\n}\nconst int PC = 2;\nll MOD[PC] = {1000000007,\
    \ 1000000009}, BASE[PC] = {};\n \nuniform_int_distribution<int> dis;\nvoid initPr()\
    \ {\n    init();\n    dis = uniform_int_distribution<int>(0, primes.size() - 1);\n\
    }\n \nvoid getPr() {\n    repi(0, PC) BASE[i] = primes[dis(mt)];\n}\n \nconst\
    \ int MN = 1e6 + 1;\nusing HashType = ll;\nstruct Hash {\n    vec<ll> pow[PC],\
    \ hsh[PC];\n    void initVec(int len) {\n        for (int i = 0; i < PC; i++)\
    \ {\n            pow[i].resize(len);\n            hsh[i].resize(len);\n      \
    \  }\n    }\n    void init(string s) {\n        int len = s.length();\n      \
    \  for (int i = 0; i < PC; i++) {\n            pow[i][0] = 1LL;\n            for\
    \ (int j = 1; j <= len; j++) {\n                pow[i][j] = (pow[i][j - 1] * BASE[i])\
    \ % MOD[i];\n                hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1])\
    \ % MOD[i];\n            }\n        }\n    }\n    inline ll hash(int i, int L,\
    \ int R) {\n        return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) %\
    \ MOD[i] + MOD[i]) % MOD[i];\n    }\n    inline HashType hash(int L, int R) {\n\
    \        HashType ret = 0; \n        for (int i = 0; i < PC; i++) {\n        \
    \    ret <<= 32LL;\n            ret |= hash(i, L, R);\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "#pragma region\n#include <bits/stdc++.h>\nusing namespace std;\n// Common\
    \ Type shorteners and int128\nusing ll = long long; using ull = unsigned long\
    \ long; using ld = long double;\nusing pii = pair<int, int>; using pll = pair<ll,\
    \ ll>;\ntemplate <typename T> using vec = vector<T>;\ntemplate <typename K, typename\
    \ V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;\n\
    using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;\n\
    #ifdef __SIZEOF_INT128__\nusing int128 = __int128_t; using uint128 = __uint128_t;\n\
    #endif\ntemplate<typename I> string intStr(I x) { string ret; while (x > 0) {\
    \ ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret;\
    \ } // Int to string\n// Shorthand Macros\n#define INF 0x3f3f3f3f\n#define LLINF\
    \ 0x3f3f3f3f3f3f3f3f\n#define mpr make_pair\n#define pb push_back\n#define popcount\
    \ __builtin_popcount\n#define clz __builtin_clz\n#define ctz __builtin_ctz\n//\
    \ Shorthand Function Macros\n#define sz(x) ((int)((x).size()))\n#define all(x)\
    \ (x).begin(), (x).end()\n#define rep(i, a, b) for (__typeof(a) i = a; i < b;\
    \ i++)\n#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)\n#define repi(a,\
    \ b) rep(i, a, b)\n#define repj(a, b) rep(j, a, b)\n#define repk(a, b) rep(k,\
    \ a, b)\n#define Cmplt(type) bool operator<(const type &o) const\n#define Cmpgt(type)\
    \ bool operator>(const type &o) const\n#define Cmpfn(name, type) bool name(const\
    \ type &a, const type &b)\n#define Inop(type) istream& operator>>(istream& in,\
    \ type &o)\n#define Outop(type) ostream& operator<<(ostream& out, type o)\n#define\
    \ Pow2(x) (1LL << (x))\n#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__)\
    \ // scn -> Short for SCan New\n// Shorthand Functions\ntemplate<typename T> inline\
    \ void maxa(T& st, T v) { st = max(st, v); }\ntemplate<typename T> inline void\
    \ mina(T& st, T v) { st = min(st, v); }\ninline void setprec(ostream& out, int\
    \ prec) { out << setprecision(prec) << fixed; }\n// Out operators and printing\
    \ for arrays and vectors\ntemplate <typename T> ostream& operator<<(ostream& out,vector<T>\
    \ iter){out<<\"[\";for(auto t:iter){out<<t<<\", \";}out<<\"]\";return out;}\n\
    template <typename T> string arrayStr(T *arr,int sz){string ret = \"[\";for(int\
    \ i=0;i<sz;i++){ret+=to_string(arr[i])+\", \"; } return ret + \"]\";}\ntemplate\
    \ <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<\"\
    \ \"; } cout<<\"\\n\";}\n// I/O Operations\ninline void scan(){}\ntemplate<typename\
    \ F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}\ntemplate\
    \ <typename F> inline void println(F t){cout<<t<<'\\n';}\ntemplate<typename F,\
    \ typename... R> inline void println(F f,R... r){cout<<f<<\" \";println(r...);}\n\
    inline void print(){}\ntemplate<typename F, typename... R> inline void print(F\
    \ f,R... r){cout<<f;print(r...);}\n// Debugging\n#define db(x) cout << (#x) <<\
    \ \": \" << x << \", \"\n#define dblb(s) cout << \"[\" << s << \"] \"\n#define\
    \ dbbin(x, n) cout << (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x,\
    \ n) cout << (#x) << \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout\
    \ << endl;\n#pragma endregion\n\n// top 2 are fixes\n#define db(x) cout << (#x)\
    \ << \": \" << (x) << \", \"\n#define dblb(s) cout << \"[\" << (s) << \"] \"\n\
    #define dba(alias, x) cout << (alias) << \": \" << (x) << \", \"\ntemplate<typename\
    \ F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return\
    \ ss.str(); }\ntemplate<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}\n\
    template<typename F, typename... R> string __join_comma(F f, R... r) { return\
    \ __generic_tostring(f) + \", \" + __join_comma(r...); }\n#define dbp(alias, ...)\
    \ cout << (alias) << \": (\" << __join_comma(__VA_ARGS__) << \"), \"\n#define\
    \ dbbin(x, n) cout << (#x) << \": \" << bitset<n>(x) << \", \"\n#define dbarr(x,\
    \ n) cout << (#x) << \": \" << arrayStr((x), (n)) << \", \"\n#define dbln cout\
    \ << endl;\n\n// pragmas\n#pragma GCC optimize \"Ofast\"\n#pragma GCC optimize\
    \ \"unroll-loops\"\n#pragma GCC target \"sse,sse2,sse3,sse4,abm,avx,mmx,popcnt\"\
    \n\n// random short things\nusing namespace std::chrono;\nll timeMs() { return\
    \ duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();\
    \ }\n\n// random stuff\nmt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n#define mtup make_tuple\n\n#define O3 __attribute__((optimize(\"-O3\")))\n#define\
    \ finline __attribute__((always_inline))\n\n// order statistic idea\n#include\
    \ <ext/pb_ds/assoc_container.hpp> // Common file \n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds; \ntemplate <typename T, class comp = less<T>> using\
    \ os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\
    template <typename K, typename V, class comp = less<K>> using treemap = tree<K,\
    \ V, comp, rb_tree_tag, tree_order_statistics_node_update>;\n\n// gp_hash_table\
    \ fast\n#include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\
    const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {\n    ll operator()(ll x) const { return x ^ RANDOM; }\n};\ntemplate\
    \ <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;\n\
    template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K,\
    \ V, Hash>;\n\nconst ll MOD = 1e9 + 7;\nll madd(ll a, ll b) { return (a + b) %\
    \ MOD; }\nll msub(ll a, ll b) { return (a - b + MOD) % MOD; }\nll mmul(ll a, ll\
    \ b) { return (a * b) % MOD; }\nll fpow(ll x, ll y) {\n    if (!y) return 1LL;\n\
    \    return mmul(fpow(mmul(x, x), y >> 1), (y & 1) ? x : 1LL);\n}\nll mdiv(ll\
    \ x, ll y) { return mmul(x, fpow(y, MOD - 2)); }\n\n// N choose R\nvector<ll>\
    \ fact;\nvoid init_nchooser(int MN) {\n    fact.resize(MN + 1);\n    fact[0] =\
    \ 1LL;\n    for (int i = 1; i <= MN; i++)\n        fact[i] = mmul(fact[i - 1],\
    \ i);\n}\nll choose(ll N, ll K) { return mdiv(fact[N], mmul(fact[K], fact[N -\
    \ K])); }\nll permute(ll N, ll K) { return mdiv(fact[N], fact[N - K]); }\n\n//\
    \ Stirling Numbers (1st kind)\n// Depends on mod template\n// Number of length\
    \ N permutations with K disjoint cycles\nvector<vector<ll>> dp;\nll stir1(ll N,\
    \ ll K) {\n    dp.assign(N + 1, vector<ll>(K + 1, -1));\n    return _stir1(N,\
    \ K);\n}\nll _stir1(ll N, ll K) {\n    if (!N && !K) return 1LL;\n    if (!N ||\
    \ !K) return 0LL;\n    ll &ret = dp[N][K];\n    if (ret != -1) return ret;\n \
    \   return ret = madd(mmul(N - 1, _stir1(N - 1, K)), _stir1(N - 1, K - 1));\n\
    }\n\n// Stirling Numbers (2nd kind)\n// Depends on mod and nchooser templates\
    \ (and calling init_nchooser to init factorial table)\n// Number of ways to partition\
    \ N labelled objects into K (NONEMPTY) unlabelled subsets (order of subsets does\
    \ not matter)\n// If you want to do it with labelled subsets, just remove the\
    \ division at the end or multiply by fact[K]\n// If empty subsets were allowed,\
    \ the answer would just be K^N\nll stir2(ll N, ll K) {\n    ll res = 0;\n    int\
    \ coeff = 1;\n    for (int i = 0; i <= K; i++) {\n        res = madd(res, mmul(coeff,\
    \ mmul(choose(K, i), fpow(K - i, N))));\n        coeff *= -1;\n    }\n    return\
    \ mdiv(res, fact[K]);\n}\n\n// fast modular inverse (with O(N) precalc), 9 lines\n\
    const int MN = 1001;\nll inv[MN];\nvoid init_modinv(ll mod) {\n    inv[1] = 1LL;\n\
    \    for (int i = 2; i < MN; i++)\n        inv[i] = (mod - ((mod / i) * inv[mod\
    \ % i]) % mod) % mod;\n}\nll mdiv(ll x, ll y) { return (x * inv[y]) % MOD; }\n\
    \n// rabin-karp, 43 lines\nconst int PC = 2, MOD[PC] = {1000000007, 1000000009},\
    \ BASE[PC] = {131, 151};\nusing HashType = ll;\nstruct Hash {\n    vec<ll> pow[PC],\
    \ hsh[PC];\n    void init(string s) {\n        int len = s.length();\n       \
    \ for (int i = 0; i < PC; i++) {\n            pow[i].resize(len + 1);\n      \
    \      hsh[i].resize(len + 1);\n        }\n        for (int i = 0; i < PC; i++)\
    \ {\n            pow[i][0] = 1LL;\n            for (int j = 1; j <= len; j++)\
    \ {\n                pow[i][j] = (pow[i][j - 1] * BASE[i]) % MOD[i];\n       \
    \         hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1]) % MOD[i];\n       \
    \     }\n        }\n    }\n    inline ll hash(int i, int L, int R) {\n       \
    \ return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) % MOD[i] + MOD[i]) %\
    \ MOD[i];\n    }\n    inline HashType hash(int L, int R) {\n        HashType ret\
    \ = 0; \n        for (int i = 0; i < PC; i++) {\n            ret <<= 32LL;\n \
    \           ret |= hash(i, L, R);\n        }\n        return ret;\n    }\n   \
    \ inline ll hashOther(int i, string &s) {\n        ll ret = 0; for (auto ch :\
    \ s) ret = (ret * BASE[i] + ch) % MOD[i];\n        return ret;\n    }\n    inline\
    \ HashType hashOther(string &s) {\n        HashType ret = 0;\n        for (int\
    \ i = 0; i < PC; i++) {\n            ret <<= 32LL;\n            ret |= hashOther(i,\
    \ s);\n        }\n        return ret;\n    }\n};\n\n// Define int main for future\
    \ use\nint main(){\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\
    \n// assert for max # of iterations\nstatic int its=100;\nassert(its--);\n\n \
    \   return 0;\n}\n\n// Rank compession\n#define T int\nstruct Rank {\n    vector<T>\
    \ rank;\n    void init(int n, T* init) {\n        rank = vector<T>(init, init\
    \ + n);\n        sort(rank.begin(), rank.end());\n        rank.resize(unique(rank.begin(),\
    \ rank.end()) - rank.begin());\n    }\n    int get(T x) { return lower_bound(rank.begin(),\
    \ rank.end(), x) - rank.begin() + 1; }\n};\n#undef T\n\n// Rank compression (with\
    \ add function instead of setting all at once)\n#define T int\nstruct Rank {\n\
    \    vector<T> rank;\n    void add(T x) { rank.push_back(x); }\n    void init()\
    \ {\n        sort(rank.begin(), rank.end());\n        rank.resize(unique(rank.begin(),\
    \ rank.end()) - rank.begin());\n    }\n    int get(T x) { return lower_bound(rank.begin(),\
    \ rank.end(), x) - rank.begin() + 1; }\n};\n#undef T\n\n// Binary lifting lca\
    \ (weighted)\nconst int LG = 18;\nint tb[LG][MN], lv[MN];\nll dis[MN];\nvector<Ed>\
    \ g[MN];\nvoid dfsLca(int c, int p, int clv, ll cdis) {\n\tlv[c] = clv;\n\tdis[c]\
    \ = cdis;\n\ttb[0][c] = p;\n\tfor (auto to : g[c])\n\t\tif (to.v ^ p) \n\t\t\t\
    dfsLca(to.v, c, clv + 1, cdis + to.w);\n}\nvoid initSp() {\n\tmemset(tb, -1, sizeof\
    \ tb);\n\tdfsLca(1, -1, 0, 0);\n\tfor (int i = 1; i < LG; i++) {\n\t\tfor (int\
    \ j = 1; j <= N; j++) {\n\t\t\tint pp = tb[i - 1][j];\n\t\t\ttb[i][j] = pp ==\
    \ -1 ? -1 : tb[i - 1][pp];\n\t\t}\n\t}\n}\nint lca(int a, int b) {\n\tif (a ==\
    \ b) return a;\n\tif (lv[a] > lv[b]) swap(a, b);\n\tint delta = lv[b] - lv[a];\n\
    \tfor (int i = 0; i < LG; i++)\n\t\tif ((delta >> i) & 1)\n\t\t\tb = tb[i][b];\n\
    \tif (a == b) return a;\n\tfor (int i = LG - 1; i >= 0; i--) {\n\t\tif (tb[i][a]\
    \ != tb[i][b]) {\n\t\t\ta = tb[i][a];\n\t\t\tb = tb[i][b];\n\t\t}\n\t}\n\treturn\
    \ tb[0][a];\n}\nll qdis(int a, int b) {\n\treturn dis[a] + dis[b] - 2 * dis[lca(a,\
    \ b)];\n}\n\n// Binary lifting lca (unweighted)\nconst int LG = 18;\nint tb[LG][MN],\
    \ lv[MN];\nvector<int> g[MN];\nvoid dfsLca(int c, int p, int clv) {\n\tlv[c] =\
    \ clv;\n\ttb[0][c] = p;\n\tfor (auto to : g[c])\n\t\tif (to.v ^ p) \n\t\t\tdfsLca(to.v,\
    \ c, clv + 1);\n}\nvoid initSp() {\n\tmemset(tb, -1, sizeof tb);\n\tdfsLca(1,\
    \ -1, 0);\n\tfor (int i = 1; i < LG; i++) {\n\t\tfor (int j = 1; j <= N; j++)\
    \ {\n\t\t\tint pp = tb[i - 1][j];\n\t\t\ttb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];\n\
    \t\t}\n\t}\n}\nint lca(int a, int b) {\n\tif (a == b) return a;\n\tif (lv[a] >\
    \ lv[b]) swap(a, b);\n\tint delta = lv[b] - lv[a];\n\tfor (int i = 0; i < LG;\
    \ i++)\n\t\tif ((delta >> i) & 1)\n\t\t\tb = tb[i][b];\n\tif (a == b) return a;\n\
    \tfor (int i = LG - 1; i >= 0; i--) {\n\t\tif (tb[i][a] != tb[i][b]) {\n\t\t\t\
    a = tb[i][a];\n\t\t\tb = tb[i][b];\n\t\t}\n\t}\n\treturn tb[0][a];\n}\nll qdis(int\
    \ a, int b) {\n\treturn lv[a] + lv[b] - 2 * lv[lca(a, b)];\n}\n\n// Sparse Table\
    \ (RMQ) O(NlogN)/O(1) LCABinaryLift\nint dep[MN], fst[MN], tb[LG][MN * 2];\nvi\
    \ tour;\nbool cmpDep(const int &a, const int &b) {\n    return dep[a] < dep[b];\n\
    }\nvoid dfsTour(int c, int p) {\n    dep[c] = p == -1 ? 0 : dep[p] + 1;\n    tour.pb(c);\n\
    \    for (int to : g[c])\n        if (to != p)\n            dfsTour(to, c);\n\
    \    tour.pb(c);\n}\nvoid initLCA(int rt = 1) {\n    tour.pb(-1);\n    dfsTour(rt,\
    \ -1);\n    int sz = tour.size() - 1;\n    reprev(i, sz, 0)\n        fst[tour[i]]\
    \ = i;\n    copy(all(tour), tb[0]);\n    repi(1, LG) {\n        int jmp = 1 <<\
    \ (i - 1), end = sz = jmp;\n        repj(1, sz + 1)\n            tb[i][j] = min(tb[i\
    \ - 1][j], tb[i - 1][j + jmp], cmpDep);\n    }\n}\nint lca(int a, int b) {\n \
    \   a = fst[a]; b = fst[b];\n    if (a > b) swap(a, b);\n    int bit = 31 - __builtin_clz(b\
    \ - a + 1);\n    return min(tb[bit][a], tb[bit][b - (1 << bit) + 1], cmpDep);\n\
    }\n\n// Rabin karp but with random base\nusing namespace std::chrono;\nll timeMs()\
    \ { return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();\
    \ }\n \nconst int MH = 10001;\nmt19937 mt(timeMs());\nvi primes;\nbool isprime[MH];\n\
    \ \nvoid init() {\n    memset(isprime, true, sizeof isprime);\n    repi(2, MH)\
    \ {\n        if (isprime[i]) {\n            for (int j = i + i; j < MH; j += i)\n\
    \                isprime[j] = false;\n            if (i > 100)\n             \
    \   primes.pb(i);\n        }\n    }\n}\nconst int PC = 2;\nll MOD[PC] = {1000000007,\
    \ 1000000009}, BASE[PC] = {};\n \nuniform_int_distribution<int> dis;\nvoid initPr()\
    \ {\n    init();\n    dis = uniform_int_distribution<int>(0, primes.size() - 1);\n\
    }\n \nvoid getPr() {\n    repi(0, PC) BASE[i] = primes[dis(mt)];\n}\n \nconst\
    \ int MN = 1e6 + 1;\nusing HashType = ll;\nstruct Hash {\n    vec<ll> pow[PC],\
    \ hsh[PC];\n    void initVec(int len) {\n        for (int i = 0; i < PC; i++)\
    \ {\n            pow[i].resize(len);\n            hsh[i].resize(len);\n      \
    \  }\n    }\n    void init(string s) {\n        int len = s.length();\n      \
    \  for (int i = 0; i < PC; i++) {\n            pow[i][0] = 1LL;\n            for\
    \ (int j = 1; j <= len; j++) {\n                pow[i][j] = (pow[i][j - 1] * BASE[i])\
    \ % MOD[i];\n                hsh[i][j] = (hsh[i][j - 1] * BASE[i] + s[j - 1])\
    \ % MOD[i];\n            }\n        }\n    }\n    inline ll hash(int i, int L,\
    \ int R) {\n        return (hsh[i][R] - (hsh[i][L - 1] * pow[i][R - L + 1]) %\
    \ MOD[i] + MOD[i]) % MOD[i];\n    }\n    inline HashType hash(int L, int R) {\n\
    \        HashType ret = 0; \n        for (int i = 0; i < PC; i++) {\n        \
    \    ret <<= 32LL;\n            ret |= hash(i, L, R);\n        }\n        return\
    \ ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/template_additons.cpp
  requiredBy: []
  timestamp: '2021-06-29 16:57:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/template_additons.cpp
layout: document
redirect_from:
- /library/old/template_additons.cpp
- /library/old/template_additons.cpp.html
title: old/template_additons.cpp
---
