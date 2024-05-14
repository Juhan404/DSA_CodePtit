#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second

#ifdef Juhan404
#include "debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void run_case() {
    string s;
    cin >> s;

    int n = s.size();
    s = '!' + s;

    vector<vector<int>> f(n + 5, vector<int>(n + 5, 0));

    FOR(i, 1, n) {
        f[i][i] = 1;
    }

    FOR(k, 2, n) {
        FOR(i, 1, n - k + 1) {
            if (s[i] == s[i + k - 1])
                f[i][i + k - 1] = f[i + 1][i + k - 2] + 2;
            else
                f[i][i + k - 1] = max(f[i + 1][i + k - 1], f[i][i + k - 2]);
        }
    }

    cout << n - f[1][n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}