void init_file_io() {
#ifndef LOCAL
    const string PROBLEM_ID = "prob";
    freopen((PROBLEM_ID + ".in").c_str(), "r", stdin);
    freopen((PROBLEM_ID + ".out").c_str(), "w", stdout);
#endif
}

template <typename T> void read_fhc_array(vector<T> &v, int k, int inc = 1) {
    for (auto i = 0; i < k; i++)
        cin >> v[i];
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (auto i = k; i < (int)v.size(); i++)
        v[i] = (a * v[i - 2] + b * v[i - 1] + c) % d + inc;
}

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_file_io();

    int T;
    cin >> T;
    for (int caseno = 1; caseno <= T; caseno++) {
        // Input

        cout << "Case #" << caseno << ": ";
        solve();

        // Reset
#ifndef LOCAL
        cerr << "Done case #" << caseno << endl;
#endif
    }

    return 0;
}
